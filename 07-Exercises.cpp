#include <stdio.h>
#include <stdlib.h>
#include <strsafe.h>
#include"system_info.h"
int main() {
	printf_s("\tExercises system programming\t\n\n");
	printf_s("programmer : MrBlackZero\n");
	printf_s("--------------------------------------\n");
	print_versionwindows();
	print_computername();
	print_sysinfo();
	printf_s("--------------------------------------\n");
	/*LARGE_INTEGER pointer;
	QueryPerformanceCounter(&pointer);
	printf("%d", pointer.QuadPart);*/
	puts("Press any key to close this window...");
	getchar();
	return EXIT_SUCCESS;
}

