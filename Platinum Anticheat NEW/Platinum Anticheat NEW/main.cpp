#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm> 
#include "memory.h"
#include "stringquery.h"
#include <iterator>
#include "scanstring.h"
#include <intrin.h>
#include "hwid.h"
#include <tchar.h>

#define exit_positive false

void boxOfDoom()
{
    const char* result = {};

    if (dataRecord::stringOffenses > 0)
    {
        dataRecord::stringOffenseBool = true;
    }

    if (dataRecord::stringOffenseBool == true)
    {
        result = "true";
    }

    char text[128];
    sprintf_s(text, "BlackListed Strings Detected -> %s", result);
    MessageBox(NULL, text, "", MB_OK);
}


boolean main()
{
	retrieveHDD();
	retrievePCN();
    printf("--------------------------------------------------------------\n");
    printf("! HWID LOGGED, CHEAT SCANNING IN 2 SECONDS !\n");
    printf("--------------------------------------------------------------\n");	Sleep(2000);

	EnitiateFileScanning("C:\\Kostya\\Desktop\\Platinum Anticheat NEW\\Release", "*.exe");

	boxOfDoom();
	

    return exit_positive;
}


