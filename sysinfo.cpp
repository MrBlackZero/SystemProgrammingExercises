#define BUILD_WINDOWS
#include <stdio.h>
#include<Windows.h>
#include"system_info.h"
// get system inforamation -> proc and memory
void print_sysinfo() {
		SYSTEM_INFO system_inforamtion;
		GetNativeSystemInfo(&system_inforamtion);

		printf_s("---------processor/memory info---------\n");
		print_ramsize();
		printf_s("number core cpu :%d\n", system_inforamtion.dwNumberOfProcessors);
		printf_s("page size : %d\n", system_inforamtion.dwPageSize);
		printf_s("starting address at which virtual memory : 0x%p\n", system_inforamtion.dwAllocationGranularity);
		printf_s("number of logical processors : 0x%p\n", system_inforamtion.dwActiveProcessorMask);
		printf_s("Maximum memory address : 0x%p\n", system_inforamtion.lpMaximumApplicationAddress);
		printf_s("Minimum memory address : 0x%p\n", system_inforamtion.lpMinimumApplicationAddress);
}
//function get computer name target
void print_computername() {
		wchar_t computerName[MAX_COMPUTERNAME_LENGTH + 1];
		DWORD size = { sizeof(computerName) };
		GetComputerName(computerName, &size);
		printf_s("Computer Name: %ws\n", computerName);
}
// function print windows version -> MajorVersion.MinorVersion.dwBuildNumber
void print_versionwindows() {
	    OSVERSIONINFO os_version = { sizeof(os_version) };
	    GetVersionEx(&os_version);
	    printf_s("Windows Version: %d.%d.%d.%d\n",os_version.dwMajorVersion,os_version.dwMinorVersion,os_version.dwBuildNumber);
}

void print_ramsize() { 
		ULONGLONG ram{ sizeof(ram) };
		GetPhysicallyInstalledSystemMemory(&ram);
		int size_GB =(int) ram >> 20;// convert KB to GB and convert unsigned long long to int 
		printf_s("ram : %dGB\n", size_GB); 
}