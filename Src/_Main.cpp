#include "ModUtils.hpp"
#include "HooksUtils.hpp"
using namespace cocos2d;
using namespace cocos2d::extension;
using namespace gd;

//todo: load new plists idk if needed really
//todo: unlock news icons
//todo: calcIconsCount is sus asue

HWND hWnd;

std::vector<unsigned char> intToBytes(int value)
{
    std::vector<unsigned char> result;
    result.push_back(value & 0x000000ff);
    result.push_back((value & 0x0000ff00) >> 8);
    result.push_back((value & 0x00ff0000) >> 16);
    result.push_back((value & 0xff000000) >> 24);
    return result;
}

#include "SimpleIni.h"
void updateIconsCount() {
    CSimpleIni ini;
    ini.LoadFile("IconsCount.ini");
    int Player = ini.GetLongValue("IconsCount", "Player", 484);
    int Ship = ini.GetLongValue("IconsCount", "Ship", 169);
    int Player_ball = ini.GetLongValue("IconsCount", "Player_ball", 118);
    int Bird = ini.GetLongValue("IconsCount", "Bird", 149);
    int Dart = ini.GetLongValue("IconsCount", "Dart", 69);
    int Swingcopter = ini.GetLongValue("IconsCount", "Swingcopter", 43);
    int JetPack = ini.GetLongValue("IconsCount", "JetPack", 5);
    //
    /*
    *  сука ебучий патчинг нахуй какая же хуета сука
    *  >:(
    */
    /// BY RUHAX | GUSCHIN
    {
        //Player (484)
        {
            //todo: kinda broken plr rewrite i think
            std::vector<unsigned char> toRewrite = intToBytes(Player);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x1F0271, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EF70F, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2BD0B3, { 0xBa, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1227, { 0xBb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x12546E, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1227, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x12546E, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EFB2E, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Ship (169)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Ship);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x125474, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125AFD, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01C1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D13F7, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Player_ball (118)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Player_ball);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x12547A, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B05, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1661A3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01D9, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });     
            ModUtils::write_bytes(base + 0x2D1997, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Bird (149)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Bird);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x125480, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B0A, { 0x81, 0xc6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1661B7, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0xC4D34, { 0x68, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01F1, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1777, { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Dart (69)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Dart);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x125486, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1661CB, { 0xb8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1D17, { 0xba, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B12, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F0206, { 0xbb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Swingcopter (43)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Swingcopter);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x125498, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x5FF54, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x16625C, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1812B6, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F0245, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1B57, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B21, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //JetPack (5)
        {
            std::vector<unsigned char> toRewrite = intToBytes(JetPack);
            toRewrite = toRewrite[0] > 36 ? toRewrite : intToBytes(37);
            ModUtils::write_bytes(base + 0x1254AA, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x16626D, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EB72E, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F025A, { 0xBb, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D15B7, { 0xBa, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B26, { 0x83, 0xc6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
    };
}

void __fastcall loadingFinished(CCLayer* self, void* edx) {//; = win 0x2722A0;
    MappedHooks::getOriginal(loadingFinished)(self, edx);
}

DWORD WINAPI ModThread(void* hModule) {
    //game ver check
    if (ModUtils::GetGameVersion() != "2.200")
        if (MessageBoxA(hWnd, "This mod developed for Geometry Dash 2.200!\nStill countinue?", "Wrong game version", MB_OKCANCEL | MB_ICONWARNING) != IDOK)
            return 1;
    //hooks
    MH_Initialize();
    MappedHooks::registerHook(base + 0x2722A0, loadingFinished);
    //cfginit
    CSimpleIni ini;
    ini.LoadFile("IconsCount.ini");
    if (!(ini.KeyExists("IconsCount", "Player")))
        ini.SetLongValue("IconsCount", "Player", 484, 
            ";------------------------" "\n"
            "; DISCOVERED BY GUSCHIN" "\n"
            "; https://github.com/zGuschin/IconPatch" "\n"
            ";------------------------" "\n"
            "\n"
            "; WARN: u cant set less than 36" "\n"
            "\n"
            "; org count of cubes 484"
        );
    if (!(ini.KeyExists("IconsCount", "Ship")))
        ini.SetLongValue("IconsCount", "Ship", 169, "; org count of ships 169");
    if (!(ini.KeyExists("IconsCount", "Player_ball")))
        ini.SetLongValue("IconsCount", "Player_ball", 118, "; org count of BALLS 118");
    if (!(ini.KeyExists("IconsCount", "Bird")))
        ini.SetLongValue("IconsCount", "Bird", 149, "; org count of ufos 149");
    if (!(ini.KeyExists("IconsCount", "Dart")))
        ini.SetLongValue("IconsCount", "Dart", 41, "; org count of waves 41");
    if (!(ini.KeyExists("IconsCount", "Swingcopter")))
        ini.SetLongValue("IconsCount", "Swingcopter", 43, "; org count of Swingcopters 43");
    if (!(ini.KeyExists("IconsCount", "JetPack")))
        ini.SetLongValue("IconsCount", "JetPack", 5, "; org count of JetPacks 5");
    /*if (!(ini.KeyExists("IconsCount", "Auto calculation")))
        ini.SetBoolValue("IconsCount", "Auto calculation", false, "; Auto calculation icons count by loaded textures");*/
    ini.SaveFile("IconsCount.ini");
    //update count
    while (true) {
        Sleep(1000);
        updateIconsCount();
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) return TRUE;
    hWnd = GetForegroundWindow();//сatch the game window right on launch (maybe on launch) hehe
    CreateThread(0, 0, ModThread, hModule, 0, 0);
    return TRUE;
}
