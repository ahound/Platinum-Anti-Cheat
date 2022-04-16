#include <intrin.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>

void retrieveHDD()
{
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
		std::cout << "Volume Name: " << volumeName << std::endl;
		std::cout << "HDD Serial: " << serialNumber << std::endl;
		std::cout << "File System Type: " << fileSystemName << std::endl;
		std::cout << "Max Component Length: " << maxComponentLen << std::endl;
	}
}

void retrievePCN()
{
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	if (GetComputerName(
		computerName,
		&size))
	{
		std::cout << "Computer Name: " << computerName << std::endl;
	}
}