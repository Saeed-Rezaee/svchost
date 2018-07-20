#pragma once
class Asm
{
public:
	vector<int> Opcode;

	vector<int> TempOpcode;

	LPVOID Address = NULL;

	const char *Name;

	Asm(const char *name, int size = 0);

	~Asm();

	void Clear();

	VOID RemoteCAll();

	VOID Push(INT value);
	VOID Push_Eax();
	VOID Push_Ebx();
	VOID Push_Ecx();
	VOID Push_Edx();
	VOID Push_Esi();
	VOID Push_Edi();
	VOID Push_Ebp();
	VOID Push_Esp();

	VOID Mov_Eax_Eax();
	VOID Mov_Eax_Ebx();
	VOID Mov_Eax_Ecx();
	VOID Mov_Eax_Edx();
	VOID Mov_Eax_Esi();
	VOID Mov_Eax_Edi();
	VOID Mov_Eax_Ebp();
	VOID Mov_Eax_Esp();

	VOID Mov_Ebx_Eax();
	VOID Mov_Ebx_Ebx();
	VOID Mov_Ebx_Ecx();
	VOID Mov_Ebx_Edx();
	VOID Mov_Ebx_Esi();
	VOID Mov_Ebx_Edi();
	VOID Mov_Ebx_Ebp();
	VOID Mov_Ebx_Esp();

	VOID Mov_Ecx_Eax();
	VOID Mov_Ecx_Ebx();
	VOID Mov_Ecx_Ecx();
	VOID Mov_Ecx_Edx();
	VOID Mov_Ecx_Esi();
	VOID Mov_Ecx_Edi();
	VOID Mov_Ecx_Ebp();
	VOID Mov_Ecx_Esp();

	VOID Mov_Edx_Eax();
	VOID Mov_Edx_Ebx();
	VOID Mov_Edx_Ecx();
	VOID Mov_Edx_Edx();
	VOID Mov_Edx_Esi();
	VOID Mov_Edx_Edi();
	VOID Mov_Edx_Ebp();
	VOID Mov_Edx_Esp();

	VOID Mov_Esi_Eax();
	VOID Mov_Esi_Ebx();
	VOID Mov_Esi_Ecx();
	VOID Mov_Esi_Edx();
	VOID Mov_Esi_Esi();
	VOID Mov_Esi_Edi();
	VOID Mov_Esi_Ebp();
	VOID Mov_Esi_Esp();
	VOID Mov_Edi_Eax();

	VOID Mov_Edi_Ebx();
	VOID Mov_Edi_Ecx();
	VOID Mov_Edi_Edx();
	VOID Mov_Edi_Esi();
	VOID Mov_Edi_Edi();
	VOID Mov_Edi_Ebp();
	VOID Mov_Edi_Esp();

	VOID Mov_Ebp_Eax();
	VOID Mov_Ebp_Ebx();
	VOID Mov_Ebp_Ecx();
	VOID Mov_Ebp_Edx();
	VOID Mov_Ebp_Esi();
	VOID Mov_Ebp_Edi();
	VOID Mov_Ebp_Ebp();
	VOID Mov_Ebp_Esp();

	VOID Mov_Esp_Eax();
	VOID Mov_Esp_Ebx();
	VOID Mov_Esp_Ecx();
	VOID Mov_Esp_Edx();
	VOID Mov_Esp_Esi();
	VOID Mov_Esp_Edi();
	VOID Mov_Esp_Ebp();
	VOID Mov_Esp_Esp();


	VOID Mov_Eax(INT value);
	VOID Mov_Ebx(INT value);
	VOID Mov_Ecx(INT value);
	VOID Mov_Edx(INT value);
	VOID Mov_Esi(INT value);
	VOID Mov_Edi(INT value);
	VOID Mov_Ebp(INT value);
	VOID Mov_Esp(INT value);

	VOID Mov_Eax_Ptr(INT value);
	VOID Mov_Ebx_Ptr(INT value);
	VOID Mov_Ecx_Ptr(INT value);
	VOID Mov_Edx_Ptr(INT value);
	VOID Mov_Esi_Ptr(INT value);
	VOID Mov_Edi_Ptr(INT value);
	VOID Mov_Ebp_Ptr(INT value);
	VOID Mov_Esp_Ptr(INT value);

	VOID Mov_Ptr_Eax(INT value);
	VOID Mov_Ptr_Ebx(INT value);
	VOID Mov_Ptr_Ecx(INT value);
	VOID Mov_Ptr_Edx(INT value);
	VOID Mov_Ptr_Esi(INT value);
	VOID Mov_Ptr_Edi(INT value);
	VOID Mov_Ptr_Ebp(INT value);
	VOID Mov_Ptr_Esp(INT value);

	VOID Mov_Eax_Ptr_Eax();
	VOID Mov_Eax_Ptr_Ebx();
	VOID Mov_Eax_Ptr_Ecx();
	VOID Mov_Eax_Ptr_Edx();
	VOID Mov_Eax_Ptr_Esi();
	VOID Mov_Eax_Ptr_Edi();
	VOID Mov_Eax_Ptr_Ebp();
	VOID Mov_Eax_Ptr_Esp();

	VOID Mov_Ebx_Ptr_Eax();
	VOID Mov_Ebx_Ptr_Ebx();
	VOID Mov_Ebx_Ptr_Ecx();
	VOID Mov_Ebx_Ptr_Edx();
	VOID Mov_Ebx_Ptr_Esi();
	VOID Mov_Ebx_Ptr_Edi();
	VOID Mov_Ebx_Ptr_Ebp();
	VOID Mov_Ebx_Ptr_Esp();

	VOID Mov_Ecx_Ptr_Eax();
	VOID Mov_Ecx_Ptr_Ebx();
	VOID Mov_Ecx_Ptr_Ecx();
	VOID Mov_Ecx_Ptr_Edx();
	VOID Mov_Ecx_Ptr_Esi();
	VOID Mov_Ecx_Ptr_Edi();
	VOID Mov_Ecx_Ptr_Ebp();
	VOID Mov_Ecx_Ptr_Esp();

	VOID Mov_Edx_Ptr_Eax();
	VOID Mov_Edx_Ptr_Ebx();
	VOID Mov_Edx_Ptr_Ecx();
	VOID Mov_Edx_Ptr_Edx();
	VOID Mov_Edx_Ptr_Esi();
	VOID Mov_Edx_Ptr_Edi();
	VOID Mov_Edx_Ptr_Ebp();
	VOID Mov_Edx_Ptr_Esp();

	VOID Mov_Esi_Ptr_Eax();
	VOID Mov_Esi_Ptr_Ebx();
	VOID Mov_Esi_Ptr_Ecx();
	VOID Mov_Esi_Ptr_Edx();
	VOID Mov_Esi_Ptr_Esi();
	VOID Mov_Esi_Ptr_Edi();
	VOID Mov_Esi_Ptr_Ebp();
	VOID Mov_Esi_Ptr_Esp();

	VOID Mov_Edi_Ptr_Eax();
	VOID Mov_Edi_Ptr_Ebx();
	VOID Mov_Edi_Ptr_Ecx();
	VOID Mov_Edi_Ptr_Edx();
	VOID Mov_Edi_Ptr_Esi();
	VOID Mov_Edi_Ptr_Edi();
	VOID Mov_Edi_Ptr_Ebp();
	VOID Mov_Edi_Ptr_Esp();

	VOID Mov_Ebp_Ptr_Eax();
	VOID Mov_Ebp_Ptr_Ebx();
	VOID Mov_Ebp_Ptr_Ecx();
	VOID Mov_Ebp_Ptr_Edx();
	VOID Mov_Ebp_Ptr_Esi();
	VOID Mov_Ebp_Ptr_Edi();
	VOID Mov_Ebp_Ptr_Ebp();
	VOID Mov_Ebp_Ptr_Esp();

	VOID Mov_Esp_Ptr_Eax();
	VOID Mov_Esp_Ptr_Ebx();
	VOID Mov_Esp_Ptr_Ecx();
	VOID Mov_Esp_Ptr_Edx();
	VOID Mov_Esp_Ptr_Esi();
	VOID Mov_Esp_Ptr_Edi();
	VOID Mov_Esp_Ptr_Ebp();
	VOID Mov_Esp_Ptr_Esp();

	VOID Mov_Eax_Ptr_Edi_Add(int value);
	VOID Mov_Ebx_Ptr_Edi_Add(int value);
	VOID Mov_Ecx_Ptr_Edi_Add(int value);
	VOID Mov_Edx_Ptr_Edi_Add(int value);
	VOID Mov_Esi_Ptr_Edi_Add(int value);
	VOID Mov_Edi_Ptr_Edi_Add(int value);
	VOID Mov_Ebp_Ptr_Edi_Add(int value);
	VOID Mov_Esp_Ptr_Edi_Add(int value);

	VOID Mov_Eax_Ptr_Ebp_Add(int value);
	VOID Mov_Ebx_Ptr_Ebp_Add(int value);
	VOID Mov_Ecx_Ptr_Ebp_Add(int value);
	VOID Mov_Edx_Ptr_Ebp_Add(int value);
	VOID Mov_Esi_Ptr_Ebp_Add(int value);
	VOID Mov_Edi_Ptr_Ebp_Add(int value);
	VOID Mov_Ebp_Ptr_Ebp_Add(int value);
	VOID Mov_Esp_Ptr_Ebp_Add(int value);

	VOID Mov_Eax_Ptr_Esp_Add(int value);
	VOID Mov_Ebx_Ptr_Esp_Add(int value);
	VOID Mov_Ecx_Ptr_Esp_Add(int value);
	VOID Mov_Edx_Ptr_Esp_Add(int value);
	VOID Mov_Esi_Ptr_Esp_Add(int value);
	VOID Mov_Edi_Ptr_Esp_Add(int value);
	VOID Mov_Ebp_Ptr_Esp_Add(int value);
	VOID Mov_Esp_Ptr_Esp_Add(int value);
	//===========================ADD
	VOID Add_Ptr(INT ptr, INT value);

	VOID Add_Ptr_Eax(INT ptr);
	VOID Add_Ptr_Ebx(INT ptr);
	VOID Add_Ptr_Ecx(INT ptr);
	VOID Add_Ptr_Edx(INT ptr);
	VOID Add_Ptr_Esi(INT ptr);
	VOID Add_Ptr_Edi(INT ptr);
	VOID Add_Ptr_Ebp(INT ptr);
	VOID Add_Ptr_Esp(INT ptr);

	VOID Add_Eax(INT value);
	VOID Add_Ebx(INT value);
	VOID Add_Ecx(INT value);
	VOID Add_Edx(INT value);
	VOID Add_Esi(INT value);
	VOID Add_Edi(INT value);
	VOID Add_Ebp(INT value);
	VOID Add_Esp(INT value);
	//===========================SUB
	VOID Sub_Ptr(INT ptr, INT value);

	VOID Sub_Ptr_Eax(INT ptr);
	VOID Sub_Ptr_Ebx(INT ptr);
	VOID Sub_Ptr_Ecx(INT ptr);
	VOID Sub_Ptr_Edx(INT ptr);
	VOID Sub_Ptr_Esi(INT ptr);
	VOID Sub_Ptr_Edi(INT ptr);
	VOID Sub_Ptr_Ebp(INT ptr);
	VOID Sub_Ptr_Esp(INT ptr);

	VOID Sub_Eax(INT value);
	VOID Sub_Ebx(INT value);
	VOID Sub_Ecx(INT value);
	VOID Sub_Edx(INT value);
	VOID Sub_Esi(INT value);
	VOID Sub_Edi(INT value);
	VOID Sub_Ebp(INT value);
	VOID Sub_Esp(INT value);
	//===========================CALL
	VOID Call_Eax();
	VOID Call_Ebx();
	VOID Call_Ecx();
	VOID Call_Edx();
	VOID Call_Esi();
	VOID Call_Edi();
	VOID Call_Ebp();
	VOID Call_Esp();
	
	//===========================JMP
	VOID Jmp(int value);
	VOID Je(int value);
	VOID Jne(int value);
	VOID Jmp_Eax();
	VOID Jmp_Ebx();
	VOID Jmp_Ecx();
	VOID Jmp_Edx();
	VOID Jmp_Esi();
	VOID Jmp_Edi();
	VOID Jmp_Ebp();
	VOID Jmp_Esp();
	//===========================RET
	VOID Ret(int value = 0);

	VOID Cmp_Eax(INT value);
	VOID Cmp_Ebx(INT value);
	VOID Cmp_Ecx(INT value);
	VOID Cmp_Edx(INT value);
	VOID Cmp_Esi(INT value);
	VOID Cmp_Edi(INT value);
	VOID Cmp_Ebp(INT value);
	VOID Cmp_Esp(INT value);

};

