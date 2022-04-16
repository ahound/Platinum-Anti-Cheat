#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include "memory.h"

namespace blackList
{
    const string blackListA = "csgo.exe";
    const string blackListB = "ReadProcessMemory";
    const string blackListC = "WriteProcessMemory";
    const string blackListD = "Counter-Strike: Global Offensive";
    const string blackListE = "Process32Next";
    const string blackListF = "engine.dll";
    const string blackListG = "zwWriteVirtualMemory";
    const string blackListH = "VirtualMemory";
    const string blackListI = "CreateToolhelp32Snapshot";
    const string blackListJ = "client.dll";
}

namespace directory
{
    string fileDirectory = {};
}

using namespace blackList;

void scanFileAddress()
{
    ifstream myfile(directory::fileDirectory, std::ios::in | std::ios::binary);

    string line;

    bool fileOpen = myfile.is_open();

    const string blackListedStrings[0xA] = { blackListA, blackListB, blackListC, blackListD, blackListE, blackListF, blackListG, blackListH, blackListI, blackListJ }; // BLACKLISTED words from namespace to scan in the array

    if (fileOpen) // Begin main priority
    {

        while (getline(myfile, line))
        {
            // Begin Loop for searching the EXE file, if all is OK then scan.detect() should not trigger a windows sound.
            for (int i = 0x0; i < 0xA; i++)
            {
                stringQuery anticheat(line, blackListedStrings[i]);

                anticheat.outAC(line);
                anticheat.scanStrings();
            }

        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void EnitiateFileScanning(std::string directory, std::string fileFilter, bool recursively = true)
{
    if (recursively)
        EnitiateFileScanning(directory, fileFilter, false);

    directory += "\\";

    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    std::string filter = directory + (recursively ? "*" : fileFilter);

    hFind = FindFirstFile(filter.c_str(), &FindFileData);

    if (hFind == INVALID_HANDLE_VALUE)
    {
        return;
    }
    else
    {
        if (!recursively)
        {
            std::cout << directory + std::string(FindFileData.cFileName) << std::endl;
            directory::fileDirectory = directory + std::string(FindFileData.cFileName);
            scanFileAddress();
        }

        while (FindNextFile(hFind, &FindFileData) != 0)
        {
            if (!recursively)
            {
                std::cout << directory + std::string(FindFileData.cFileName) << std::endl;
                directory::fileDirectory = directory + std::string(FindFileData.cFileName);
                scanFileAddress();
            }
            else
            {
                if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) > 0 && FindFileData.cFileName[0] != '.')
                {
                    EnitiateFileScanning(directory + std::string(FindFileData.cFileName), fileFilter);
                    directory::fileDirectory = directory + std::string(FindFileData.cFileName);
                    scanFileAddress();
                }
            }
        }

        DWORD dwError = GetLastError();
        FindClose(hFind);
        if (dwError != ERROR_NO_MORE_FILES)
        {
            std::cout << "FindNextFile error. Error is " << dwError << std::endl;
        }
    }
}