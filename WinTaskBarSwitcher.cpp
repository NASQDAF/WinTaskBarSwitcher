#include <Windows.h>
#include <stdlib.h>
#include <shellapi.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    APPBARDATA rusnepizda = { 0 };
    rusnepizda.cbSize = sizeof(rusnepizda);
    if (SHAppBarMessage(ABM_GETSTATE, &rusnepizda) & ABS_AUTOHIDE) {
        rusnepizda.lParam = ABS_ALWAYSONTOP;
        SHAppBarMessage(ABM_SETSTATE, &rusnepizda);
    }
    else {
        rusnepizda.lParam = ABS_AUTOHIDE;
        SHAppBarMessage(ABM_SETSTATE, &rusnepizda);
    }
    return 0;
}
