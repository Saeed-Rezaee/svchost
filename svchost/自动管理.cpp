#include "stdafx.h"
#include "自动管理.h"
#include "功能函数.h"
#include "鼠键函数.h"
#include "扩展函数.h"

DWORD dwThreadId;
BOOL 首图标记 = false;
INT 刷图计时;

VOID 打印收益统计()
{
	if (首图标记 == FALSE) {
		刷图计时 = getTime() - 刷图计时;
		首图标记 = TRUE;
		printf("自动 · [%d] ·次\n", 刷图计时);
	}
}

VOID 自动帕拉丁(int 副本ID)
{
	switch (副本ID)
	{
	case 格蓝迪:
		if (首图标记) {

		}
		break;
	default:
		break;
	}
}

VOID 自动格蓝迪() 
{
	switch (取职业ID())
	{
	case 帕拉丁:
		自动帕拉丁(格蓝迪);
		break;
	default:
		break;
	}
}

VOID 图内处理()
{
	switch (取副本ID())
	{
	case 格蓝迪:
		自动格蓝迪();
		break;
	default:
		break;
	}
}

VOID 自动()
{
	int 游戏状态 = 取游戏状态();
	switch (游戏状态)
	{
	case 0: 
		if (取当前角色下标()+1 > 取角色数量()) {
			//printf("所有角色刷图完毕,自动关闭\n");
			自动开关 = false;
		}
		else {
			选择角色();
		}
		break;
	case 1:
		if (取剩余疲劳() > 0) {
			进入副本();
		}
		else {
			返回角色();
		}
		break;
	case 2:
		if (取剩余疲劳() > 0) {
			选择副本(); 
		}
		else {
			doKeyPress(VK_ESCAPE);
		}
		break;
	case 3:
		if (首图标记 == TRUE) {
			刷图计时 = getTime();
			首图标记 = FALSE;
		}
		图内处理();
		break;
	default:
		break;
	}
}

VOID 自动线程()
{
	while (自动开关)
	{
		自动();
	}
	dwThreadId = 0;
	return;
}

VOID 自动管理(BOOL 自动开关)
{
	if (自动开关) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)自动线程, NULL, 0, &dwThreadId);
	}
	else {
		Sleep(1000);
		if (dwThreadId != 0) {
			ExitThread(dwThreadId);
		}
	}
}

