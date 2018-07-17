#include "stdafx.h"
#include "Asm.h"
#include "扩展函数.h"
#include "读写函数.h"


Asm::Asm()
{
	printf("tesl\n");
}


Asm::~Asm()
{
}

VOID Asm::Clear()
{
	Opcode.clear();
}

VOID Asm::RemoteCAll(const char * CallName)
{
	int 地址;
	// 1.申请内存空间
	地址 = allocMemory(CallName,Opcode.size());
	// 2.写入汇编代码
	writeBytes(地址, Opcode);
	// 3.调用
	//printf("%x\n", 地址);
	SendMessage(hWnd,消息ID, 地址,0);
}
// =================================PUSH
VOID Asm::Push(INT value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x6A ,value });
	}
	else {
		Opcode.insert(Opcode.end(), 0x68);
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}

VOID Asm::Push_Eax()
{
	Opcode.insert(Opcode.end(), { 0x50 });
}
VOID Asm::Push_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x53 });
}
VOID Asm::Push_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x51 });
}
VOID Asm::Push_Edx()
{
	Opcode.insert(Opcode.end(), { 0x52 });
}
VOID Asm::Push_Esi()
{
	Opcode.insert(Opcode.end(), { 0x56 });
}
VOID Asm::Push_Edi()
{
	Opcode.insert(Opcode.end(), { 0x57 });
}
VOID Asm::Push_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x55 });
}
VOID Asm::Push_Esp()
{
	Opcode.insert(Opcode.end(), { 0x54 });
}


// =================================MOV
VOID Asm::Mov_Eax_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC0 });
}
VOID Asm::Mov_Eax_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC3 });
}
VOID Asm::Mov_Eax_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC1 });
}
VOID Asm::Mov_Eax_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC2 });
}
VOID Asm::Mov_Eax_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC6 });
}
VOID Asm::Mov_Eax_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC7 });
}
VOID Asm::Mov_Eax_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC5 });
}
VOID Asm::Mov_Eax_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC4 });
}

VOID Asm::Mov_Ebx_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD8 });
}
VOID Asm::Mov_Ebx_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xDB });
}
VOID Asm::Mov_Ebx_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD9 });
}
VOID Asm::Mov_Ebx_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xDA });
}
VOID Asm::Mov_Ebx_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xDE });
}
VOID Asm::Mov_Ebx_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xDF });
}
VOID Asm::Mov_Ebx_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xDD });
}
VOID Asm::Mov_Ebx_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xDC });
}

VOID Asm::Mov_Ecx_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC8 });
}
VOID Asm::Mov_Ecx_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xCB });
}
VOID Asm::Mov_Ecx_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xC9 });
}
VOID Asm::Mov_Ecx_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xCA });
}
VOID Asm::Mov_Ecx_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xCE });
}
VOID Asm::Mov_Ecx_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xCF });
}
VOID Asm::Mov_Ecx_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xCD });
}
VOID Asm::Mov_Ecx_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xCC });
}

VOID Asm::Mov_Edx_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD0 });
}
VOID Asm::Mov_Edx_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD3 });
}
VOID Asm::Mov_Edx_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD1 });
}
VOID Asm::Mov_Edx_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD2 });
}
VOID Asm::Mov_Edx_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD6 });
}
VOID Asm::Mov_Edx_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD7 });
}
VOID Asm::Mov_Edx_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD5 });
}
VOID Asm::Mov_Edx_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xD4 });
}

VOID Asm::Mov_Esi_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF0 });
}
VOID Asm::Mov_Esi_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF3 });
}
VOID Asm::Mov_Esi_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF1 });
}
VOID Asm::Mov_Esi_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF2 });
}
VOID Asm::Mov_Esi_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF6 });
}
VOID Asm::Mov_Esi_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF7 });
}
VOID Asm::Mov_Esi_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF5 });
}
VOID Asm::Mov_Esi_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF4 });
}

VOID Asm::Mov_Edi_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF8 });
}
VOID Asm::Mov_Edi_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xFB });
}
VOID Asm::Mov_Edi_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xF9 });
}
VOID Asm::Mov_Edi_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xFA });
}
VOID Asm::Mov_Edi_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xFE });
}
VOID Asm::Mov_Edi_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xFF });
}
VOID Asm::Mov_Edi_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xFD });
}
VOID Asm::Mov_Edi_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xFC });
}

VOID Asm::Mov_Ebp_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE8 });
}
VOID Asm::Mov_Ebp_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xEB });
}
VOID Asm::Mov_Ebp_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE9 });
}
VOID Asm::Mov_Ebp_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xEA });
}
VOID Asm::Mov_Ebp_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xEE });
}
VOID Asm::Mov_Ebp_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xEF });
}
VOID Asm::Mov_Ebp_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xED });
}
VOID Asm::Mov_Ebp_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xEC });
}

VOID Asm::Mov_Esp_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE0 });
}
VOID Asm::Mov_Esp_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE3 });
}
VOID Asm::Mov_Esp_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE1 });
}
VOID Asm::Mov_Esp_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE2 });
}
VOID Asm::Mov_Esp_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE6 });
}
VOID Asm::Mov_Esp_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE7 });
}
VOID Asm::Mov_Esp_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE5 });
}
VOID Asm::Mov_Esp_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0xE4 });
}

VOID Asm::Mov_Eax(INT value)
{
	Opcode.insert(Opcode.end(), { 0xB8 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ebx(INT value)
{
	Opcode.insert(Opcode.end(), { 0xBB });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ecx(INT value)
{
	Opcode.insert(Opcode.end(), { 0xB9 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Edx(INT value)
{
	Opcode.insert(Opcode.end(), { 0xBA });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Esi(INT value)
{
	Opcode.insert(Opcode.end(), { 0xBE });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Edi(INT value)
{
	Opcode.insert(Opcode.end(), { 0xBF });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ebp(INT value)
{
	Opcode.insert(Opcode.end(), { 0xBd });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Esp(INT value)
{
	Opcode.insert(Opcode.end(), { 0xBC });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Mov_Eax_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0xA1 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ebx_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x1D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ecx_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x0D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Edx_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x15 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Esi_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x35 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Edi_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x3D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ebp_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x2D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Esp_Ptr(INT value)
{
	Opcode.insert(Opcode.end(), { 0x8B,0x25 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Mov_Ptr_Eax(INT value)
{
	Opcode.insert(Opcode.end(), { 0xA3 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Ebx(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x1D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Ecx(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x0D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Edx(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x15 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Esi(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x35 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Edi(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x3D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Ebp(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x2D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Mov_Ptr_Esp(INT value)
{
	Opcode.insert(Opcode.end(), { 0x89,0x25 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Mov_Eax_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x00 });
}
VOID Asm::Mov_Eax_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x03 });
}
VOID Asm::Mov_Eax_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x01 });
}
VOID Asm::Mov_Eax_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x02 });
}
VOID Asm::Mov_Eax_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x06 });
}
VOID Asm::Mov_Eax_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x07 });
}
VOID Asm::Mov_Eax_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x45,0x00 });
}
VOID Asm::Mov_Eax_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x04,0x24 });
}

VOID Asm::Mov_Ebx_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x18 });
}
VOID Asm::Mov_Ebx_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x1B });
}
VOID Asm::Mov_Ebx_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x19 });
}
VOID Asm::Mov_Ebx_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x1A });
}
VOID Asm::Mov_Ebx_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x1E });
}
VOID Asm::Mov_Ebx_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x1F });
}
VOID Asm::Mov_Ebx_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x5D,0x00 });
}
VOID Asm::Mov_Ebx_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x1C,0x24 });
}

VOID Asm::Mov_Ecx_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x08 });
}
VOID Asm::Mov_Ecx_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x0B });
}
VOID Asm::Mov_Ecx_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x09 });
}
VOID Asm::Mov_Ecx_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x0A });
}
VOID Asm::Mov_Ecx_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x0E });
}
VOID Asm::Mov_Ecx_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x0F });
}
VOID Asm::Mov_Ecx_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x4D,0x00 });
}
VOID Asm::Mov_Ecx_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x0C,0x24 });
}

VOID Asm::Mov_Edx_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x10 });
}
VOID Asm::Mov_Edx_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x13 });
}
VOID Asm::Mov_Edx_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x11 });
}
VOID Asm::Mov_Edx_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x12 });
}
VOID Asm::Mov_Edx_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x16 });
}
VOID Asm::Mov_Edx_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x17 });
}
VOID Asm::Mov_Edx_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x55,0x00 });
}
VOID Asm::Mov_Edx_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x14,0x24 });
}

VOID Asm::Mov_Esi_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x30 });
}
VOID Asm::Mov_Esi_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x33 });
}
VOID Asm::Mov_Esi_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x31 });
}
VOID Asm::Mov_Esi_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x32 });
}
VOID Asm::Mov_Esi_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x36 });
}
VOID Asm::Mov_Esi_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x37 });
}
VOID Asm::Mov_Esi_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x75,0x00 });
}
VOID Asm::Mov_Esi_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x34,0x24 });
}

VOID Asm::Mov_Edi_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x38 });
}
VOID Asm::Mov_Edi_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x3B });
}
VOID Asm::Mov_Edi_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x39 });
}
VOID Asm::Mov_Edi_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x3A });
}
VOID Asm::Mov_Edi_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x3E });
}
VOID Asm::Mov_Edi_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x3F });
}
VOID Asm::Mov_Edi_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x7D,0x00 });
}
VOID Asm::Mov_Edi_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x3C,0x24 });
}

VOID Asm::Mov_Ebp_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x28 });
}
VOID Asm::Mov_Ebp_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x2B });
}
VOID Asm::Mov_Ebp_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x29 });
}
VOID Asm::Mov_Ebp_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x2A });
}
VOID Asm::Mov_Ebp_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x2E });
}
VOID Asm::Mov_Ebp_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x2F });
}
VOID Asm::Mov_Ebp_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x6D,0x00 });
}
VOID Asm::Mov_Ebp_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x2C,0x24 });
}

VOID Asm::Mov_Esp_Ptr_Eax()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x20 });
}
VOID Asm::Mov_Esp_Ptr_Ebx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x23 });
}
VOID Asm::Mov_Esp_Ptr_Ecx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x21 });
}
VOID Asm::Mov_Esp_Ptr_Edx()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x22 });
}
VOID Asm::Mov_Esp_Ptr_Esi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x26 });
}
VOID Asm::Mov_Esp_Ptr_Edi()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x27 });
}
VOID Asm::Mov_Esp_Ptr_Ebp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x65,0x00 });
}
VOID Asm::Mov_Esp_Ptr_Esp()
{
	Opcode.insert(Opcode.end(), { 0x8B,0x24,0x24 });
}

VOID Asm::Mov_Eax_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x47,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x87 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ebx_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x5F,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x9F });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ecx_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x4F,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x8F });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Edx_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x57,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x97 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Esi_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x77,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xB7 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Edi_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x7F,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xBF });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ebp_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x6F,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xAF });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Esp_Ptr_Edi_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x67,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xA7 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}

VOID Asm::Mov_Eax_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x45,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x85 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ebx_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x5D,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x9D });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ecx_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x4D,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x8D });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Edx_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x55,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x95 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Esi_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x75,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xB5 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Edi_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x7D,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xBD });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ebp_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x6D,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xAD });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Esp_Ptr_Ebp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x65,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xA5 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}

VOID Asm::Mov_Eax_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x44,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x84,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ebx_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x5C,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x9C,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ecx_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x4C,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x8C,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Edx_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x54,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0x94,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Esi_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x74,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xB4,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Edi_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x7C,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xBC,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Ebp_Ptr_Esp_Add(int value) 
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x6C,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xAC,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}
VOID Asm::Mov_Esp_Ptr_Esp_Add(int value)
{
	if (value <= 127 && value >= -128) {
		Opcode.insert(Opcode.end(), { 0x8B ,0x64,0x24,value });
	}
	else {
		Opcode.insert(Opcode.end(), { 0x8B ,0xA4,0x24 });
		TempOpcode = IntToBytes(value);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}


// =================================ADD
VOID Asm::Add_Ptr(INT ptr,INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0x05 });

	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Add_Ptr_Eax(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x05 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Ebx(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x1D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Ecx(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x0D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Edx(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x15 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Esi(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x35 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Edi(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x3D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Ebp(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x2D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ptr_Esp(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x01,0x25 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Add_Eax(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x05 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ebx(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC3 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ecx(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC1 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Edx(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC2 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Esi(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC6 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Edi(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC7 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Ebp(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC4 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Add_Esp(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xC5 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
// =================================SUB
VOID Asm::Sub_Ptr(INT ptr, INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0x2D });

	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Sub_Ptr_Eax(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x05 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Ebx(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x1D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Ecx(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x0D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Edx(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x15 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Esi(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x35 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Edi(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x3D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Ebp(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x2D });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ptr_Esp(INT ptr)
{
	Opcode.insert(Opcode.end(), { 0x29,0x25 });
	TempOpcode = IntToBytes(ptr);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

VOID Asm::Sub_Eax(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x2D });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ebx(INT value)
{
	Opcode.insert(Opcode.end(), { 0x81,0xEB });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ecx(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xE9 });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Edx(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xEA });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Esi(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xEE });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Edi(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xEF });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Ebp(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xEC });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}
VOID Asm::Sub_Esp(INT value) 
{
	Opcode.insert(Opcode.end(), { 0x81,0xED });
	TempOpcode = IntToBytes(value);
	for (unsigned i = 0; i < TempOpcode.size(); i++) {
		Opcode.insert(Opcode.end(), TempOpcode[i]);
	}
}

//================================CALL
VOID Asm::Call_Eax() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD0 });
}
VOID Asm::Call_Ebx() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD3 });
}
VOID Asm::Call_Ecx() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD1 });
}
VOID Asm::Call_Edx() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD2 });
}
VOID Asm::Call_Esi() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD6 });
}
VOID Asm::Call_Edi() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD7 });
}
VOID Asm::Call_Ebp() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD4 });
}
VOID Asm::Call_Esp() 
{
	Opcode.insert(Opcode.end(), { 0xFF,0xD5 });
}

//================================RET
VOID Asm::Ret(int value) 
{
	if (value == 0)
	{
		Opcode.insert(Opcode.end(), { 0xC3 });
	}
	else {
		Opcode.insert(Opcode.end(), { 0xC2 });
		TempOpcode = IntToBytes(value,4);
		for (unsigned i = 0; i < TempOpcode.size(); i++) {
			Opcode.insert(Opcode.end(), TempOpcode[i]);
		}
	}
}