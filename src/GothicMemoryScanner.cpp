#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>

// Gothic 1 Remake Tools
// Educational single-player utility skeleton.
// This file is intentionally minimal and does not include hard-coded offsets.

DWORD FindProcessId(const std::wstring& processName)
{
    DWORD processId = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    PROCESSENTRY32W entry{};
    entry.dwSize = sizeof(PROCESSENTRY32W);

    if (Process32FirstW(snapshot, &entry))
    {
        do
        {
            if (processName == entry.szExeFile)
            {
                processId = entry.th32ProcessID;
                break;
            }
        }
        while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return processId;
}

int wmain()
{
    const std::wstring processName = L"GothicRemake-Win64-Shipping.exe";
    DWORD pid = FindProcessId(processName);

    if (pid == 0)
    {
        std::wcout << L"Game process not found: " << processName << std::endl;
        return 1;
    }

    std::wcout << L"Game process found. PID: " << pid << std::endl;
    std::wcout << L"Offset scanning is disabled in this public skeleton." << std::endl;
    return 0;
}
