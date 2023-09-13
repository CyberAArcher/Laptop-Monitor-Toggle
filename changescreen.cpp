#include <iostream>
#include <windows.h>

//compile this with g++ changescreen.cpp -o changescreen.exe -mwindows
// Callback function to count monitors

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
    int *count = (int*)dwData;
    (*count)++;
    return true;
}

bool isCurrentlyExtended() {
    int nMonitors = 0;
    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&nMonitors);
    return nMonitors > 1; // If more than 1 monitor is active, it's extended.
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    if (isCurrentlyExtended()) {
        ShellExecute(NULL, "open", "DisplaySwitch.exe", "/external", NULL, SW_HIDE); //you can change this to other stuff all you need to know is here https://ss64.com/nt/displayswitch.html
    } else {
        ShellExecute(NULL, "open", "DisplaySwitch.exe", "/extend", NULL, SW_HIDE);
    }
    return 0;
}
//just some nerdy detail: instead of system I used ShellExecute because If you compile this file using g++ with -mwindows you will no longer have that disgusting CMD opening (also why the WINAPI) is there
//btw I have a youtube channel please check that out :) (@cyberarcher on youtube)