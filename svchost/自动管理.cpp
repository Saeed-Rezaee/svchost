#include "stdafx.h"
#include "�Զ�����.h"
#include "���ܺ���.h"
#include "�������.h"
#include "��չ����.h"
#include "��д����.h"
#include "�жϺ���.h"

DWORD dwThreadId;
BOOL ��ͼ��� = false;
INT ˢͼ��ʱ;

VOID ��ӡ����ͳ��()
{
	if (��ͼ��� == FALSE) {
		ˢͼ��ʱ = getTime() - ˢͼ��ʱ;
		��ͼ��� = TRUE;
		printf("�Զ� �� [%d] ����\n", ˢͼ��ʱ);
	}
}

VOID �Զ�������(int ����ID)
{
	Coordinate current_room;
	int �����ַ = readInteger(�����ַ);
	int i = 0;
	��ȡ��ǰ��������(current_room);
	switch (����ID)
	{
	case ������:
		if (current_room.x == 0 && current_room.y == 0){
			Sleep(1000);
			doKeyPress(VK_F);
			Sleep(800);
			doKeyPress(VK_Y);
			Sleep(2000);
		}
		else if (current_room.x == 1 and current_room.y == 0) {
			����CALL(�����ַ, 345 + createRandom(-10, 10), 216 + createRandom(-10, 10), 0);
			Sleep(200);
			doKeyPress(VK_A);
			Sleep(2000);
		}
		else if (current_room.x == 2 and current_room.y == 0) {
			����CALL(�����ַ, 582 + createRandom(-10, 10), 241 + createRandom(-10, 10), 0);
			Sleep(200);
			doKeyPress(VK_A,1000);
			Sleep(800);
		}
		else if (current_room.x == 2 and current_room.y == 1) {
			doKeyPress(VK_NUMPAD1);
			Sleep(200);
			����CALL(�����ַ, 521 + createRandom(-10, 10), 200 + createRandom(-10, 10), 0);
			Sleep(500);
			doKeyPress(VK_R);
			Sleep(1000);
		}
		else if (current_room.x == 2 and current_room.y == 2) {
			����CALL(�����ַ, 611 + createRandom(-10, 10), 201 + createRandom(-10, 10), 0);
			Sleep(300);
			doKeyPress(VK_T);
			Sleep(1000);
			����CALL(�����ַ, 550 + createRandom(-10, 10), 335 + createRandom(-10, 10), 0);
			Sleep(300);
			doKeyPress(VK_A);
			Sleep(500);
			����();
			Sleep(300);
			doKeyPress(VK_Q);
			Sleep(800);
		}
		else if (current_room.x == 3 and current_room.y == 2) {
			����CALL(�����ַ, 343 + createRandom(-10, 10), 273 + createRandom(-10, 10), 0);
			Sleep(300);
			doKeyPress(VK_A,1000);
			Sleep(800);
		}
		else if (current_room.x == 3 and current_room.y == 1) {
			doKeyPress(VK_NUMPAD3);
			doKeyPress(VK_W);
			Sleep(2000);
			if (!�Ƿ���())
			{
				����();
				doKeyPress(VK_H);
			}
		}
		if (�Ƿ���())
		{
			return;
		}
		����();
		Sleep(200);
		doKeyPress(VK_S);
		Sleep(1000);
		if (�Ƿ���())
		{
			return;
		}
		����();
		Sleep(200);
		doKeyPress(VK_E);
		Sleep(1000);
		if (�Ƿ���())
		{
			return;
		}
		����();
		Sleep(200);
		doKeyPress(VK_G);
		Sleep(2000);
		if (�Ƿ���())
		{
			return;
		}
		����();
		Sleep(200);
		doKeyPress(VK_H);
		Sleep(2000);
		if (�Ƿ���())
		{
			return;
		}
		����();
		Sleep(200);
		doKeyPress(VK_S);
		Sleep(1000);
		if (�Ƿ���())
		{
			return;
		}
		i = 0;
		while (�Ƿ���() == false)
		{
			if(readInteger(�Ի���ַ) == 1){
				doKeyPress(VK_RETURN);
			}
			����();
			if (i%7 == 0)
			{
				doKeyPress(VK_X,2000);
			}
			i += 1;
		}
		break;
	default:
		break;
	}
}

VOID �Զ�������() 
{
	switch (ȡְҵID())
	{
	case ������:
		�Զ�������(������);
		break;
	default:
		break;
	}
}

VOID ͼ�ڴ���()
{
	
	if (�Ƿ���())
	{
		����();
		if (�Ƿ���������()) {
			Sleep(500);
			if (�Ƿ���() == false)return;
			if (ȷ��ͨ��() == false)return;
			Sleep(1000);
			doKeyPress(VK_I);
			�ű�����();
			doKeyPress(VK_ESCAPE);
			ͨ�ش���();
			return;
		}
		else {
			�ƶ����¸�����();
		}
	}
	else {
		switch (ȡ����ID())
		{
		case ������:
			�Զ�������();
			break;
		default:
			break;
		}
	}
	
}

VOID �Զ�()
{
	int ��Ϸ״̬ = ȡ��Ϸ״̬();
	switch (��Ϸ״̬)
	{
	case 0: 
		if (ȡ��ǰ��ɫ�±�()+1 > ȡ��ɫ����()) {
			printf("���н�ɫˢͼ���,�Զ��ر�\n");
			�Զ����� = false;
		}
		else {
			ѡ���ɫ();
		}
		break;
	case 1:
		if (ȡʣ��ƣ��() > 0) {
			���븱��();
		}
		else {
			���ؽ�ɫ();
		}
		break;
	case 2:
		if (ȡʣ��ƣ��() > 0) {
			ѡ�񸱱�(); 
		}
		else {
			doKeyPress(VK_ESCAPE);
		}
		break;
	case 3:
		if (��ͼ��� == TRUE) {
			ˢͼ��ʱ = getTime();
			��ͼ��� = FALSE;
		}
		ͼ�ڴ���();
		break;
	default:
		break;
	}
}

VOID �Զ��߳�()
{
	while (�Զ�����)
	{
		�Զ�();
	}
	dwThreadId = 0;
	return;
}

VOID �Զ�����(BOOL �Զ�����)
{
	if (�Զ�����) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)�Զ��߳�, NULL, 0, &dwThreadId);
	}
	else {
		Sleep(1000);
		if (dwThreadId != 0) {
			ExitThread(dwThreadId);
		}
	}
}

