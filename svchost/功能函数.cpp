#include "stdafx.h"
#include "���ܺ���.h"
#include "��д����.h"
#include "Asm.h"


INT ����(int address)
{
	int eax, esi, edx, i;
	eax = readInteger(address);
	esi = readInteger(���ܻ�ַ);
	edx = eax >> 16;
	edx = readInteger(esi + edx * 4 + 36);
	eax = eax & 65535;
	eax = readInteger(edx + eax * 4 + 8468);
	edx = eax & 65535;
	esi = edx << 16;
	esi = esi | edx;
	i = readInteger(address + 4);
	esi = esi ^ i;
	return esi;
}

VOID ��ͼ()
{

}

VOID ����()
{

}

BOOL ѡ���ɫ()
{

}

BOOL ���븱��() 
{

}

BOOL ѡ�񸱱�()
{

}

INT ȡʣ��ƣ��()
{
	return ����(���ƣ��) - ����(��ǰƣ��);
}

VOID ����()
{

}

VOID ����()
{

}

VOID ���()
{

}

VOID ���س���()
{

}

BOOL ���ؽ�ɫ()
{

}


INT ȡ��ɫ����()
{

}

INT ȡ��ǰ��ɫ�±�()
{

}


INT ȡ��Ϸ״̬()
{
	INT ״̬;
	״̬ = readInteger(��Ϸ״̬);
	return ״̬;
}

// ���޹���
INT ȡְҵID()
{
	return ������;
}

// ���޹���
INT ȡ����ID()
{
	return ������;
}

BOOL ��ȡ��ǰ��������(Coordinate &��ǰ��������)
{
	int ��ʱ��ַ;
	��ʱ��ַ = readInteger(readInteger(readInteger(������) + ʱ���ַ) + ����ƫ��);
	if (!��ʱ��ַ) {
		printf("��ȡ��ǰ�������� ��ʱ��ַ error!\n");
		return false;
	}
	��ǰ��������.x = readInteger(��ʱ��ַ + ��ǰ����x);
	��ǰ��������.y = readInteger(��ʱ��ַ + ��ǰ����y);
	return true;
}

BOOL ��ȡ������������(Coordinate &������������)
{
	int ��ʱ��ַ;
	��ʱ��ַ = readInteger(readInteger(readInteger(������) + ʱ���ַ) + ����ƫ��);
	if (!��ʱ��ַ) {
		printf("��ȡ������������ ��ʱ��ַ error!\n");
		return false;
	}
	������������.x = readInteger(��ʱ��ַ + ��������x);
	������������.y = readInteger(��ʱ��ַ + ��������y);
	return true;
}




VOID ����CALL(int ����ָ��, int x, int y, int z)
{
	Asm _Asm;
	_Asm.Mov_Esi(����ָ��);
	_Asm.Mov_Edi_Ptr_Esi();
	_Asm.Push(z);
	_Asm.Push(y);
	_Asm.Push(x);
	_Asm.Mov_Eax_Ptr_Edi_Add(0xA8);
	_Asm.Mov_Ecx_Esi();
	_Asm.Call_Eax();
	_Asm.Ret();
	_Asm.RemoteCAll("����CALL");
}