#include "stdafx.h"
#include "�Զ�����.h"
#include "���ܺ���.h"
#include "�������.h"
#include "��չ����.h"

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
	switch (����ID)
	{
	case ������:
		if (��ͼ���) {

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
	switch (ȡ����ID())
	{
	case ������:
		�Զ�������();
		break;
	default:
		break;
	}
}

VOID �Զ�()
{
	int ��Ϸ״̬ = ȡ��Ϸ״̬();
	switch (��Ϸ״̬)
	{
	case 0: 
		if (ȡ��ǰ��ɫ�±�()+1 > ȡ��ɫ����()) {
			//printf("���н�ɫˢͼ���,�Զ��ر�\n");
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

