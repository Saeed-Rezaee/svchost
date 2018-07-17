#include "stdafx.h"
#include "功能函数.h"
#include "读写函数.h"
#include "遍历数据.h"
#include "扩展函数.h"
#include "寻路管理.h"
#include "鼠键函数.h"
#include "Asm.h"

INT 解密(int address)
{
	int eax, esi, edx, i;
	eax = readInteger(address);
	esi = readInteger(解密基址);
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

VOID 过图()
{

}

VOID 翻牌()
{

}

BOOL 选择角色()
{

}

BOOL 进入副本() 
{

}

BOOL 选择副本()
{

}

INT 取剩余疲劳()
{
	return 解密(最大疲劳) - 解密(当前疲劳);
}

BOOL 获取坐标(int 对象,Coordinate 坐标)
{
	坐标.x = (int)readFloat(对象 + x坐标);
	坐标.y = (int)readFloat(对象 + y坐标);
	坐标.z = (int)readFloat(对象 + z坐标);
}

VOID 捡物()
{
	int 人物指针;
	地图结构 _地图结构;
	Coordinate 物品坐标;
	
	人物指针 = readInteger(人物基址);
	遍历地图(_地图结构);
	for (size_t i = _地图结构.对象数量; i >= 0; i--)
	{
		_地图结构.对象地址 = readInteger(_地图结构.首地址 + 4 * i);
		if (_地图结构.对象地址)
		{
			_地图结构.对象类型 = readInteger(_地图结构.对象地址 + 类型偏移);
			_地图结构.对象阵营 = readInteger(_地图结构.对象地址 + 阵营偏移);
			if (_地图结构.对象阵营 == 200 && _地图结构.对象类型 == 289)
			{
				获取坐标(_地图结构.对象地址,物品坐标);
				坐标CALL(人物指针, 物品坐标.x, 物品坐标.y,0);
				Sleep(50);
				doKeyPress(VK_X);
				Sleep(100);
			}
		}
	}
}

VOID 跟随()
{
	地图结构 _地图结构;
	Coordinate 人物坐标;
	Coordinate 怪物坐标;
	INT 人物地址;

	人物地址 = readInteger(人物基址);
	遍历地图(_地图结构);

	for (int i = 0; i < _地图结构.对象数量; i++)
	{
		_地图结构.对象地址 = readInteger(_地图结构.首地址 + 4 * i);
		if (_地图结构.对象地址)
		{
			_地图结构.对象类型 = readInteger(_地图结构.对象地址 + 类型偏移);
			if (_地图结构.对象类型 == 273 && _地图结构.对象类型 == 529)
			{
				_地图结构.对象血量 = readInteger(_地图结构.对象地址 + 当前血量);
				if (_地图结构.对象血量 > 0)
				{
					_地图结构.对象阵营 = readInteger(_地图结构.对象地址 + 阵营偏移);
					if (
						_地图结构.对象阵营 == 100 ||
						_地图结构.对象阵营 == 101 ||
						_地图结构.对象阵营 == 110 ||
						_地图结构.对象阵营 == 120 ||
						_地图结构.对象阵营 == 50
						)
					{
						获取坐标(人物地址, 人物坐标);
						获取坐标(_地图结构.对象地址, 怪物坐标);
						if (
							abs(人物坐标.x - 怪物坐标.x) > 150 ||
							abs(人物坐标.y - 怪物坐标.y) > 30 
							)
						{
							if (人物坐标.x > 怪物坐标.x)
							{
								doKeyPress(VK_NUMPAD1);
								Sleep(500);
								坐标CALL(人物地址, 怪物坐标.x + 100, 怪物坐标.y , 0);
							}
							else {
								doKeyPress(VK_NUMPAD3);
								Sleep(500);
								坐标CALL(人物地址, 怪物坐标.x - 100, 怪物坐标.y, 0);
							}
						}
					}
				}
			}
		}
	}
}

VOID 卖物()
{

}

VOID 打怪()
{

}

VOID 返回城镇()
{

}

BOOL 返回角色()
{

}

INT 取角色数量()
{

}

INT 取当前角色下标()
{

}

VOID 坐标过图(int 方向,int 对象指针)
{
	int 门结构地址;
	int x, y, xF, yF, cx, cy = 0;
	门结构地址 = (readInteger(readInteger(readInteger(商店基址 - 8) + 时间基址) + 140)) + ((方向 + 方向 * 8) * 4) + 5936 + 方向 * 4;
	x  = readInteger(门结构地址 + 0); //x 开始
	y  = readInteger(门结构地址 + 4); //y 开始
	xF = readInteger(门结构地址 + 8); //x 结束
	yF = readInteger(门结构地址 + 12); //y 结束
	if (方向 == 0)
	{
		cx = x + xF + 20;
		cy = y + yF / 2;
		x = x + createRandom(-10, 0);
		y = y + createRandom(80, 100);
	}
	else  if (方向 == 1)
	{
		cx = x - 20;
		cy = y + yF / 2;
		x = x + createRandom(0, 10);
		y = y + createRandom(80, 100);
	}
	else if (方向 == 2)
	{
		cx = x + xF / 2;
		cy = y + yF + 20;
		x = x + createRandom(-30, 30);
		y = y + createRandom(-10, 0);
	}
	else if (方向 == 3)
	{
		cx = x + xF / 2;
		cy = y - 20;
		x = x + createRandom(-30, 30);
		y = y + createRandom(0, 10);
	}
	if (对象指针 == 0)
	{
		对象指针 = readInteger(人物基址);
	}
	坐标CALL(对象指针, cx + createRandom(-10, 10), cy + createRandom(-10, 10), 0);
	Sleep(200);
	坐标CALL(对象指针, x + xF / 2, y, 0);
}

VOID 移动到下个房间()
{
	坐标过图(getDirection());
}

INT 取游戏状态()
{
	INT 状态;
	状态 = readInteger(游戏状态);
	return 状态;
}
// 暂无功能
INT 取职业ID()
{
	return 帕拉丁;
}
// 暂无功能
INT 取副本ID()
{
	return 格蓝迪;
}

BOOL 获取当前房间坐标(Coordinate &当前房间坐标)
{
	int 临时地址;
	临时地址 = readInteger(readInteger(readInteger(房间编号) + 时间基址) + 门型偏移);
	if (!临时地址) {
		printf("获取当前房间坐标 临时地址 error!\n");
		return false;
	}
	当前房间坐标.x = readInteger(临时地址 + 当前房间x);
	当前房间坐标.y = readInteger(临时地址 + 当前房间y);
	return true;
}

BOOL 获取领主房间坐标(Coordinate &领主房间坐标)
{
	int 临时地址;
	临时地址 = readInteger(readInteger(readInteger(房间编号) + 时间基址) + 门型偏移);
	if (!临时地址) {
		printf("获取领主房间坐标 临时地址 error!\n");
		return false;
	}
	领主房间坐标.x = readInteger(临时地址 + 领主房间x);
	领主房间坐标.y = readInteger(临时地址 + 领主房间y);
	return true;
}

INT 获取背包物品索引(const char *物品名称)
{
	背包结构 _背包结构;
	遍历背包(_背包结构);
	for (size_t i = 0; i < 279; i++)
	{
		_背包结构.物品地址 = readInteger(_背包结构.物品首地址 + i * 4);
		if (_背包结构.物品地址)
		{
			_背包结构.物品名称 = readString(_背包结构.物品地址,100);
			if (strcmp(物品名称, _背包结构.物品名称) == 0)
			{
				return i + 9;
			}
		}
	}
	printf("%s 未找到\n", 物品名称);
	return -1;
}

VOID 坐标CALL(int 对象指针, int x, int y, int z)
{
	Asm _Asm;
	_Asm.Mov_Esi(对象指针);
	_Asm.Mov_Edi_Ptr_Esi();
	_Asm.Push(z);
	_Asm.Push(y);
	_Asm.Push(x);
	_Asm.Mov_Eax_Ptr_Edi_Add(0xA8);
	_Asm.Mov_Ecx_Esi();
	_Asm.Call_Eax();
	_Asm.Ret();
	_Asm.RemoteCAll("坐标CALL");
}

VOID Send_缓冲CALL(Asm _Asm,int head)
{
	_Asm.Push(head);
	_Asm.Mov_Ecx(发包基址);
	_Asm.Mov_Eax(缓冲CALL);
	_Asm.Call_Eax();
}

VOID Send_密包CALL(Asm _Asm, int param, int len)
{
	int temp_var = 0;
	if (len == 1)
	{
		temp_var = 加密CALL;
	}
	else if (len == 2) {
		temp_var = 加密CALL + 0x30;
	}
	else if (len == 3) {
		temp_var = 加密CALL + 0x60;
	}
	else if (len == 4) {
		temp_var = 加密CALL + 0x90;
	}
	_Asm.Push(param);
	_Asm.Mov_Ecx(发包基址);
	_Asm.Mov_Eax(temp_var);
	_Asm.Call_Eax();
}

VOID Send_发包CALL(Asm _Asm)
{
	_Asm.Mov_Eax(发包CALL);
	_Asm.Call_Eax();
	_Asm.Ret();
}

VOID 根据物品索引获取物品位置(游戏窗口 _游戏窗口, Coordinate 开始坐标,int index, Coordinate &物品位置)
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
	物品位置.x = x + _游戏窗口.left + 开始坐标.x;
	物品位置.y = y + _游戏窗口.top + 开始坐标.y;

}

VOID 脚本卖物()
{
	背包结构 _背包结构;
	游戏窗口 _游戏窗口;
	Coordinate 物品位置;
	Coordinate 开始坐标;

	遍历背包(_背包结构);
	获取游戏窗口(_游戏窗口);
	
	if (_游戏窗口.width == 1600 && _游戏窗口.height == 900)
	{
		开始坐标.x = 890;
		开始坐标.y = 458;
		setMouseCoord(_游戏窗口.left + 899 , _游戏窗口.top + 426);
	}
	else if (_游戏窗口.width == 1280 && _游戏窗口.height == 720)
	{
		开始坐标.x = 729;
		开始坐标.y = 366;
		setMouseCoord(_游戏窗口.left + 633, _游戏窗口.top + 280);
	}
	else if (_游戏窗口.width == 1067 && _游戏窗口.height == 600)
	{
		开始坐标.x = 625;
		开始坐标.y = 310;
		setMouseCoord(_游戏窗口.left + 633, _游戏窗口.top + 280);
	}
	else {
		printf("请设置窗口分辨率 为 1280x720 或者 1600x900 或者 1067x600 自动已关闭\n");
		自动开关 = false;
	}
	writeInteger(0x0606b540, 5);
	for (size_t i = 0; i < 55; i++)
	{
		_背包结构.物品地址 = readInteger(_背包结构.物品首地址 + i * 4);
		if (_背包结构.物品地址)
		{
			_背包结构.物品属性 = readInteger(_背包结构.物品地址 + 装备品质);
			_背包结构.物品名称 = readString(_背包结构.物品地址, 100);
			string temp_str(_背包结构.物品名称);
			if (
				temp_str.find("传承", 0) != -1 &&
				temp_str.find("周年", 0) != -1 &&
				temp_str.find("活动", 0) != -1 
				)
			{
				if (
					装备属性 == 0 || 
					装备属性 == 1 || 
					装备属性 == 2
					) {
					printf(">>> 卖出 装备属性 %d 装备名称 %s \n", 装备属性, temp_str.c_str());
					根据物品索引获取物品位置(_游戏窗口,开始坐标,i,物品位置);
					setMouseCoord(物品位置.x, 物品位置.y);
					mouseDoubleClick();
				}
			}
		}
	}
	writeInteger(0x0606b540, 0);
}