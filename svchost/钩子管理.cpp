#include "stdafx.h"
#include "���ӹ���.h"
#include "��չ����.h"
#include "��д����.h"

#define NAKED void __declspec(naked)
#define ReturnAddr		0x400400
#define NewCodeAddr		0x400404
#define HookAddr		0x400408

int _HookAddr = 0;

NAKED NewCode()
{
	__asm
	{
		mov ecx, dword ptr[ebp + 0xC]
		cmp ecx, ��ϢID
		je newcode
		jmp originalcode
		newcode :
		mov ecx, dword ptr[ebp + 0x10]
			call ecx
			add esp, 0x8
			pop ebp
			ret
			originalcode :
		mov eax, fs : [00000000]
			push eax
			push ebx
			push esi
			mov ecx, ReturnAddr
			mov ecx, dword ptr[ecx]
			jmp ecx
	}
}

NAKED SetHookAddr()
{
	__asm
	{
		mov eax, NewCodeAddr
		mov eax, dword ptr[eax]
		jmp eax
	}
}

NAKED ReHook()
{
	__asm {
		mov eax, fs : [00000000]
		push eax
		push ebx
		push esi
	}
}

bool ReHookMsg()
{
	return writeMemory(_HookAddr, ReHook, 0x9);
}

void HookWindowsMsg()
{
	// 1.д��hook����
	printf("���� _NewCodeAddr ...\n");
	int _NewCodeAddr = allocMemory("NewCodeAddr", 128);
	if (!_NewCodeAddr) {
		printf("���� _NewCodeAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	printf("Write HookCode ...\n");
	if (writeMemory(_NewCodeAddr, NewCode, 128) == false) {
		printf("Write _NewCodeAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	printf("Set NewCodeAddr ...\n");
	if (writeInteger(NewCodeAddr, _NewCodeAddr) == false) {
		printf("Write NewCodeAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	printf("Get HookAddr ...\n");
	_HookAddr = getModleAddrByPid(dwProcessId, L"CrossAdapter4DNF.dll") + 0x12DAA;//CrossAdapter4DNF.dll+0x12DAA
	if (!_HookAddr) {
		printf("Get hookAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	printf("Set HookAddr ...\n");
	if (writeInteger(HookAddr, _HookAddr) == false) {
		printf("Write HookAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	printf("Set ReturnAddr ...\n");
	if (writeInteger(ReturnAddr, _HookAddr + 0x9) == false) {
		printf("Write ReturnAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	printf("Set Hook ...\n");
	if (writeMemory(_HookAddr, SetHookAddr, 0x9) == false) {
		printf("SetHookAddr ʧ��!\n");
		system("pause");
		exit(1);
	}
	//printf("Ŷ����Ĳʺ缦��K����������\n");
}