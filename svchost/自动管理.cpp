#include "stdafx.h"
#include "自动管理.h"
#include "功能函数.h"
#include "鼠键函数.h"
#include "扩展函数.h"
#include "读写函数.h"
#include "判断函数.h"

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
	Coordinate current_room;
	int 人物地址 = readInteger(人物基址);
	int i = 0;
	获取当前房间坐标(current_room);
	switch (副本ID)
	{
	case 格蓝迪:
		if (current_room.x == 0 && current_room.y == 0){
			Sleep(1000);
			doKeyPress(VK_F);
			Sleep(800);
			doKeyPress(VK_Y);
			Sleep(2000);
		}
		else if (current_room.x == 1 and current_room.y == 0) {
			坐标CALL(人物地址, 345 + createRandom(-10, 10), 216 + createRandom(-10, 10), 0);
			Sleep(200);
			doKeyPress(VK_A);
			Sleep(2000);
		}
		else if (current_room.x == 2 and current_room.y == 0) {
			坐标CALL(人物地址, 582 + createRandom(-10, 10), 241 + createRandom(-10, 10), 0);
			Sleep(200);
			doKeyPress(VK_A,1000);
			Sleep(800);
		}
		else if (current_room.x == 2 and current_room.y == 1) {
			doKeyPress(VK_NUMPAD1);
			Sleep(200);
			坐标CALL(人物地址, 521 + createRandom(-10, 10), 200 + createRandom(-10, 10), 0);
			Sleep(500);
			doKeyPress(VK_R);
			Sleep(1000);
		}
		else if (current_room.x == 2 and current_room.y == 2) {
			坐标CALL(人物地址, 611 + createRandom(-10, 10), 201 + createRandom(-10, 10), 0);
			Sleep(300);
			doKeyPress(VK_T);
			Sleep(1000);
			坐标CALL(人物地址, 550 + createRandom(-10, 10), 335 + createRandom(-10, 10), 0);
			Sleep(300);
			doKeyPress(VK_A);
			Sleep(500);
			跟随();
			Sleep(300);
			doKeyPress(VK_Q);
			Sleep(800);
		}
		else if (current_room.x == 3 and current_room.y == 2) {
			坐标CALL(人物地址, 343 + createRandom(-10, 10), 273 + createRandom(-10, 10), 0);
			Sleep(300);
			doKeyPress(VK_A,1000);
			Sleep(800);
		}
		else if (current_room.x == 3 and current_room.y == 1) {
			doKeyPress(VK_NUMPAD3);
			doKeyPress(VK_W);
			Sleep(2000);
			if (!是否开门())
			{
				跟随();
				doKeyPress(VK_H);
			}
		}
		if (是否开门())
		{
			return;
		}
		跟随();
		Sleep(200);
		doKeyPress(VK_S);
		Sleep(1000);
		if (是否开门())
		{
			return;
		}
		跟随();
		Sleep(200);
		doKeyPress(VK_E);
		Sleep(1000);
		if (是否开门())
		{
			return;
		}
		跟随();
		Sleep(200);
		doKeyPress(VK_G);
		Sleep(2000);
		if (是否开门())
		{
			return;
		}
		跟随();
		Sleep(200);
		doKeyPress(VK_H);
		Sleep(2000);
		if (是否开门())
		{
			return;
		}
		跟随();
		Sleep(200);
		doKeyPress(VK_S);
		Sleep(1000);
		if (是否开门())
		{
			return;
		}
		i = 0;
		while (是否开门() == false)
		{
			if(readInteger(对话基址) == 1){
				doKeyPress(VK_RETURN);
			}
			跟随();
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
	
	if (是否开门())
	{
		捡物();
		if (是否领主房间()) {
			Sleep(500);
			if (是否开门() == false)return;
			if (确认通关() == false)return;
			Sleep(1000);
			doKeyPress(VK_I);
			脚本卖物();
			doKeyPress(VK_ESCAPE);
			通关处理();
			return;
		}
		else {
			移动到下个房间();
		}
	}
	else {
		switch (取副本ID())
		{
		case 格蓝迪:
			自动格蓝迪();
			break;
		default:
			break;
		}
	}
	
}

VOID 自动()
{
	int 游戏状态 = 取游戏状态();
	switch (游戏状态)
	{
	case 0: 
		if (取当前角色下标()+1 > 取角色数量()) {
			printf("所有角色刷图完毕,自动关闭\n");
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

