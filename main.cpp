#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <windows.h>
#include <string>

HANDLE openProc;
DWORD pid;
unsigned long n;

void WriteMemory(DWORD addr, DWORD value)
{
	WriteProcessMemory(openProc, LPVOID(addr), &value, sizeof(value), 0);
}

int main() 
{
	HWND handle = FindWindow(0, "GTA: San Andreas");
	while (handle == NULL)
	{
		handle = FindWindow(0, "GTA: San Andreas");
		Sleep(100);
	}

	if (handle != NULL)
	{
		GetWindowThreadProcessId(handle, &pid);
		openProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		printf("openProc is true");
	}

	while(true)
	{
		if (GetAsyncKeyState('J'))
		{
			WriteMemory(0x00B7CE50, 999999999);
			printf("set money");
		}
		if (GetAsyncKeyState('P'))
		{

		}
		Sleep(100);
	}
	return 0;
}
