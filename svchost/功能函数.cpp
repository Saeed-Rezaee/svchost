#include "stdafx.h"
#include "���ܺ���.h"
#include "��д����.h"
#include "��������.h"
#include "��չ����.h"
#include "Ѱ·����.h"
#include "�������.h"
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

BOOL ��ȡ����(int ����,Coordinate ����)
{
	����.x = (int)readFloat(���� + x����);
	����.y = (int)readFloat(���� + y����);
	����.z = (int)readFloat(���� + z����);
}

VOID ����()
{
	int ����ָ��;
	��ͼ�ṹ _��ͼ�ṹ;
	Coordinate ��Ʒ����;
	
	����ָ�� = readInteger(�����ַ);
	������ͼ(_��ͼ�ṹ);
	for (size_t i = _��ͼ�ṹ.��������; i >= 0; i--)
	{
		_��ͼ�ṹ.�����ַ = readInteger(_��ͼ�ṹ.�׵�ַ + 4 * i);
		if (_��ͼ�ṹ.�����ַ)
		{
			_��ͼ�ṹ.�������� = readInteger(_��ͼ�ṹ.�����ַ + ����ƫ��);
			_��ͼ�ṹ.������Ӫ = readInteger(_��ͼ�ṹ.�����ַ + ��Ӫƫ��);
			if (_��ͼ�ṹ.������Ӫ == 200 && _��ͼ�ṹ.�������� == 289)
			{
				��ȡ����(_��ͼ�ṹ.�����ַ,��Ʒ����);
				����CALL(����ָ��, ��Ʒ����.x, ��Ʒ����.y,0);
				Sleep(50);
				doKeyPress(VK_X);
				Sleep(100);
			}
		}
	}
}

VOID ����()
{
	��ͼ�ṹ _��ͼ�ṹ;
	Coordinate ��������;
	Coordinate ��������;
	INT �����ַ;

	�����ַ = readInteger(�����ַ);
	������ͼ(_��ͼ�ṹ);

	for (int i = 0; i < _��ͼ�ṹ.��������; i++)
	{
		_��ͼ�ṹ.�����ַ = readInteger(_��ͼ�ṹ.�׵�ַ + 4 * i);
		if (_��ͼ�ṹ.�����ַ)
		{
			_��ͼ�ṹ.�������� = readInteger(_��ͼ�ṹ.�����ַ + ����ƫ��);
			if (_��ͼ�ṹ.�������� == 273 && _��ͼ�ṹ.�������� == 529)
			{
				_��ͼ�ṹ.����Ѫ�� = readInteger(_��ͼ�ṹ.�����ַ + ��ǰѪ��);
				if (_��ͼ�ṹ.����Ѫ�� > 0)
				{
					_��ͼ�ṹ.������Ӫ = readInteger(_��ͼ�ṹ.�����ַ + ��Ӫƫ��);
					if (
						_��ͼ�ṹ.������Ӫ == 100 ||
						_��ͼ�ṹ.������Ӫ == 101 ||
						_��ͼ�ṹ.������Ӫ == 110 ||
						_��ͼ�ṹ.������Ӫ == 120 ||
						_��ͼ�ṹ.������Ӫ == 50
						)
					{
						��ȡ����(�����ַ, ��������);
						��ȡ����(_��ͼ�ṹ.�����ַ, ��������);
						if (
							abs(��������.x - ��������.x) > 150 ||
							abs(��������.y - ��������.y) > 30 
							)
						{
							if (��������.x > ��������.x)
							{
								doKeyPress(VK_NUMPAD1);
								Sleep(500);
								����CALL(�����ַ, ��������.x + 100, ��������.y , 0);
							}
							else {
								doKeyPress(VK_NUMPAD3);
								Sleep(500);
								����CALL(�����ַ, ��������.x - 100, ��������.y, 0);
							}
						}
					}
				}
			}
		}
	}
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

VOID �����ͼ(int ����,int ����ָ��)
{
	int �Žṹ��ַ;
	int x, y, xF, yF, cx, cy = 0;
	�Žṹ��ַ = (readInteger(readInteger(readInteger(�̵��ַ - 8) + ʱ���ַ) + 140)) + ((���� + ���� * 8) * 4) + 5936 + ���� * 4;
	x  = readInteger(�Žṹ��ַ + 0); //x ��ʼ
	y  = readInteger(�Žṹ��ַ + 4); //y ��ʼ
	xF = readInteger(�Žṹ��ַ + 8); //x ����
	yF = readInteger(�Žṹ��ַ + 12); //y ����
	if (���� == 0)
	{
		cx = x + xF + 20;
		cy = y + yF / 2;
		x = x + createRandom(-10, 0);
		y = y + createRandom(80, 100);
	}
	else  if (���� == 1)
	{
		cx = x - 20;
		cy = y + yF / 2;
		x = x + createRandom(0, 10);
		y = y + createRandom(80, 100);
	}
	else if (���� == 2)
	{
		cx = x + xF / 2;
		cy = y + yF + 20;
		x = x + createRandom(-30, 30);
		y = y + createRandom(-10, 0);
	}
	else if (���� == 3)
	{
		cx = x + xF / 2;
		cy = y - 20;
		x = x + createRandom(-30, 30);
		y = y + createRandom(0, 10);
	}
	if (����ָ�� == 0)
	{
		����ָ�� = readInteger(�����ַ);
	}
	����CALL(����ָ��, cx + createRandom(-10, 10), cy + createRandom(-10, 10), 0);
	Sleep(200);
	����CALL(����ָ��, x + xF / 2, y, 0);
}

VOID �ƶ����¸�����()
{
	�����ͼ(getDirection());
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

INT ��ȡ������Ʒ����(const char *��Ʒ����)
{
	�����ṹ _�����ṹ;
	��������(_�����ṹ);
	for (size_t i = 0; i < 279; i++)
	{
		_�����ṹ.��Ʒ��ַ = readInteger(_�����ṹ.��Ʒ�׵�ַ + i * 4);
		if (_�����ṹ.��Ʒ��ַ)
		{
			_�����ṹ.��Ʒ���� = readString(_�����ṹ.��Ʒ��ַ,100);
			if (strcmp(��Ʒ����, _�����ṹ.��Ʒ����) == 0)
			{
				return i + 9;
			}
		}
	}
	printf("%s δ�ҵ�\n", ��Ʒ����);
	return -1;
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

VOID Send_����CALL(Asm _Asm,int head)
{
	_Asm.Push(head);
	_Asm.Mov_Ecx(������ַ);
	_Asm.Mov_Eax(����CALL);
	_Asm.Call_Eax();
}

VOID Send_�ܰ�CALL(Asm _Asm, int param, int len)
{
	int temp_var = 0;
	if (len == 1)
	{
		temp_var = ����CALL;
	}
	else if (len == 2) {
		temp_var = ����CALL + 0x30;
	}
	else if (len == 3) {
		temp_var = ����CALL + 0x60;
	}
	else if (len == 4) {
		temp_var = ����CALL + 0x90;
	}
	_Asm.Push(param);
	_Asm.Mov_Ecx(������ַ);
	_Asm.Mov_Eax(temp_var);
	_Asm.Call_Eax();
}

VOID Send_����CALL(Asm _Asm)
{
	_Asm.Mov_Eax(����CALL);
	_Asm.Call_Eax();
	_Asm.Ret();
}

VOID ������Ʒ������ȡ��Ʒλ��(��Ϸ���� _��Ϸ����, Coordinate ��ʼ����,int index, Coordinate &��Ʒλ��)
{
	int x, y = 0;
	if (index >= 0 and index <= 7)
	{
		x = index * 30;
		y = 0;
	}
	if (index >= 8 and index <= 15)
	{
		x = (index - 8) * 30;
		y = 30;
	}
	if (index >= 16 and index <= 23)
	{
		x = (index - 16) * 30;
		y = 60;
	}
	if (index >= 24 and index <= 31)
	{
		x = (index - 24) * 30;
		y = 90;
	}
	if (index >= 32 and index <= 39)
	{
		x = (index - 32) * 30;
		y = 120;
	}
	if (index >= 40 and index <= 47)
	{
		x = (index - 40) * 30;
		y = 150;
	}
	if (index >= 48 and index <= 55)
	{
		x = (index - 48) * 30;
		y = 180;
	}
	��Ʒλ��.x = x + _��Ϸ����.left + ��ʼ����.x;
	��Ʒλ��.y = y + _��Ϸ����.top + ��ʼ����.y;

}

VOID �ű�����()
{
	�����ṹ _�����ṹ;
	��Ϸ���� _��Ϸ����;
	Coordinate ��Ʒλ��;
	Coordinate ��ʼ����;

	��������(_�����ṹ);
	��ȡ��Ϸ����(_��Ϸ����);
	
	if (_��Ϸ����.width == 1600 && _��Ϸ����.height == 900)
	{
		��ʼ����.x = 890;
		��ʼ����.y = 458;
		setMouseCoord(_��Ϸ����.left + 899 , _��Ϸ����.top + 426);
	}
	else if (_��Ϸ����.width == 1280 && _��Ϸ����.height == 720)
	{
		��ʼ����.x = 729;
		��ʼ����.y = 366;
		setMouseCoord(_��Ϸ����.left + 633, _��Ϸ����.top + 280);
	}
	else if (_��Ϸ����.width == 1067 && _��Ϸ����.height == 600)
	{
		��ʼ����.x = 625;
		��ʼ����.y = 310;
		setMouseCoord(_��Ϸ����.left + 633, _��Ϸ����.top + 280);
	}
	else {
		printf("�����ô��ڷֱ��� Ϊ 1280x720 ���� 1600x900 ���� 1067x600 �Զ��ѹر�\n");
		�Զ����� = false;
	}
	writeInteger(0x0606b540, 5);
	for (size_t i = 0; i < 55; i++)
	{
		_�����ṹ.��Ʒ��ַ = readInteger(_�����ṹ.��Ʒ�׵�ַ + i * 4);
		if (_�����ṹ.��Ʒ��ַ)
		{
			_�����ṹ.��Ʒ���� = readInteger(_�����ṹ.��Ʒ��ַ + װ��Ʒ��);
			_�����ṹ.��Ʒ���� = readString(_�����ṹ.��Ʒ��ַ, 100);
			string temp_str(_�����ṹ.��Ʒ����);
			if (
				temp_str.find("����", 0) != -1 &&
				temp_str.find("����", 0) != -1 &&
				temp_str.find("�", 0) != -1 
				)
			{
				if (
					װ������ == 0 || 
					װ������ == 1 || 
					װ������ == 2
					) {
					printf(">>> ���� װ������ %d װ������ %s \n", װ������, temp_str.c_str());
					������Ʒ������ȡ��Ʒλ��(_��Ϸ����,��ʼ����,i,��Ʒλ��);
					setMouseCoord(��Ʒλ��.x, ��Ʒλ��.y);
					mouseDoubleClick();
				}
			}
		}
	}
	writeInteger(0x0606b540, 0);
}