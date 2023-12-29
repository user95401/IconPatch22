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
    int Player = 3;//= ini.GetLongValue("IconsCount", "Player", 484));
    int Ship = 3;//= ini.GetLongValue("IconsCount", "Ship", 169);
    int Player_ball = 3;//= ini.GetLongValue("IconsCount", "Player_ball", 118);
    int Bird = 3;//= ini.GetLongValue("IconsCount", "Bird", 149);
    int Dart = 3;//= ini.GetLongValue("IconsCount", "Dart", 69);
    int Swingcopter = 3;//= ini.GetLongValue("IconsCount", "Swingcopter", 43);
    int JetPack = 3;//= ini.GetLongValue("IconsCount", "JetPack", 5);

    /// BY RUHAX | GUSCHIN
    {
        //Player (484)
        {
            //todo: kinda broken plr rewrite i think
            std::vector<unsigned char> toRewrite = intToBytes(Player);
            ModUtils::write_bytes(base + 0x1F0271, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125AF5, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EF70F, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2BD0B3, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EFB2E, { 0xB9, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1227, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x12546E, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Ship (169)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Ship);
            ModUtils::write_bytes(base + 0x125474, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125AFD, { 0x81, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01C1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D13F7, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Player_ball (118)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Player_ball);
            ModUtils::write_bytes(base + 0x12547A, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B05, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1661A3, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01D9, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1997, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Bird (149)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Bird);
            ModUtils::write_bytes(base + 0x125480, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B0A, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1661B7, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0xC4D34, { 0x68, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01F1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1777, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Dart (69)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Dart);
            ModUtils::write_bytes(base + 0x125486, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1661CB, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1D17, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B12, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //Swingcopter (43)
        {
            std::vector<unsigned char> toRewrite = intToBytes(Swingcopter);
            ModUtils::write_bytes(base + 0x125498, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x5FF54, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x16625C, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1812B6, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EB585, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F01F1, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D1B57, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B21, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
        //JetPack (5)
        {
            std::vector<unsigned char> toRewrite = intToBytes(JetPack);
            ModUtils::write_bytes(base + 0x1254AA, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x16626D, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1EB72E, { 0xB8, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x1F025A, { 0xBB, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x2D15B7, { 0xBA, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
            ModUtils::write_bytes(base + 0x125B26, { 0x83, 0xC6, toRewrite[0], toRewrite[1], toRewrite[2], toRewrite[3] });
        };
    };
}

void calcIconsCount() {
    CSimpleIni ini;
    ini.LoadFile("IconsCount.ini");
    std::stringstream num;

    std::vector<std::string> SearchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
    for (std::vector<std::string>::iterator i = SearchPaths.begin(); i != SearchPaths.end(); ++i) {
        CCFileUtils::sharedFileUtils()->addSearchPath((i[0] + "icons").c_str());
    }

    int Player = 0;
    for (int i = 0; i < 1000; ++i) {
        std::string toFind = std::format("player_{}.png", (std::stringstream() << std::setw(2) << std::setfill('0') << i).str());
        if (CCFileUtils::sharedFileUtils()->isFileExist(toFind.c_str())) {
            ++Player;
        }
    }
    CCMessageBox(std::format("Player: {}", Player).c_str(), __FUNCSIG__);

    ini.SaveFile("geode/config/IconsCount.ini");
}

void __fastcall loadingFinished(CCLayer* self, void* edx) {//; = win 0x2722A0;
    MappedHooks::getOriginal(loadingFinished)(self, edx);
    calcIconsCount();
}

DWORD WINAPI ModThread(void* hModule) {
    //game ver check
    if (ModUtils::GetGameVersion() != "2.200")
        if (MessageBoxA(hWnd, "This mod developed for Geometry Dash 2.200!\nStill countinue?", "Wrong game version", MB_OKCANCEL | MB_ICONWARNING) != IDOK)
            return 1;
    //hooks
    MH_Initialize();
    MappedHooks::registerHook(base + 0x2722A0, loadingFinished);
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
