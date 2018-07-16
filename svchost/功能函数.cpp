#include "stdafx.h"
#include "功能函数.h"
#include "读写函数.h"


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

VOID 捡物()
{

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

VOID 坐标CALL()
{

}