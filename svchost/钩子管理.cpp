#include "stdafx.h"
#include "钩子管理.h"
#include "扩展函数.h"
#include "读写函数.h"
#include "Asm.h"

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
		cmp ecx, 消息ID
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
	// 1.写入hook代码
	printf("申请 _NewCodeAddr ...\n");
	int _NewCodeAddr = allocMemory("NewCodeAddr", 128);
	if (!_NewCodeAddr) {
		printf("申请 _NewCodeAddr 失败!\n");
		system("pause");
		exit(1);
	}
	printf("Write HookCode ...\n");
	if (writeMemory(_NewCodeAddr, NewCode, 128) == false) {
		printf("Write _NewCodeAddr 失败!\n");
		system("pause");
		exit(1);
	}
	printf("Set NewCodeAddr ...\n");
	if (writeInteger(NewCodeAddr, _NewCodeAddr) == false) {
		printf("Write NewCodeAddr 失败!\n");
		system("pause");
		exit(1);
	}
	printf("Get HookAddr ...\n");
	_HookAddr = getModleAddrByPid(dwProcessId, L"CrossAdapter4DNF.dll") + 0x12DAA;//CrossAdapter4DNF.dll+0x12DAA
	if (!_HookAddr) {
		printf("Get hookAddr 失败!\n");
		system("pause");
		exit(1);
	}
	printf("Set HookAddr ...\n");
	if (writeInteger(HookAddr, _HookAddr) == false) {
		printf("Write HookAddr 失败!\n");
		system("pause");
		exit(1);
	}
	printf("Set ReturnAddr ...\n");
	if (writeInteger(ReturnAddr, _HookAddr + 0x9) == false) {
		printf("Write ReturnAddr 失败!\n");
		system("pause");
		exit(1);
	}
	printf("Set Hook ...\n");
	if (writeMemory(_HookAddr, SetHookAddr, 0x9) == false) {
		printf("SetHookAddr 失败!\n");
		system("pause");
		exit(1);
	}
	//printf("哦尼玛的彩虹鸡巴K！！！！！\n");
}

/*VOID Hook_窗口消息()
{
	int Hook_地址 = getModleAddrByPid(dwProcessId, L"CrossAdapter4DNF.dll") + 0x12DAA;
	int Hook_长度 = 0x9;
	int Ret_地址 = getModleAddrByPid(dwProcessId, L"CrossAdapter4DNF.dll") + 0x12DAA + Hook_长度;
	int OriginalCodeAddress;
	int NewCodeAddress;
	vector<int> NewCode = {};
	vector<int> OriginalCode = {};
	Asm _Asm;
	_Asm.Mov_Ecx_Ptr_Ebp_Add(0xC);
	_Asm.Cmp_Ecx(消息ID);
	_Asm.Mov_Eax(OriginalCodeAddress);
	_Asm.Mov_Ecx(NewCodeAddress);


}*/