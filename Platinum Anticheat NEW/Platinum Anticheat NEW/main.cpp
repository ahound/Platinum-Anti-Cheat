#include <iostream>
#include <Windows.h>
#include "hwid.h"

#define exit_positive false

int main()
{
	retrieveHDD();
	retrievePCN();
    printf("--------------------------------------------------------------\n");
    printf("! HWID LOGGED, CHEAT SCANNING IN 2 SECONDS !\n");
    printf("--------------------------------------------------------------\n");	Sleep(2000);

    return exit_positive;
}


