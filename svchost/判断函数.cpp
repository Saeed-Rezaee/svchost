#include "stdafx.h"
#include "判断函数.h"
#include "功能函数.h"
#include "读写函数.h"

BOOL 是否开门()
{
	if (解密(readInteger(readInteger(人物基址) + 地图偏移) + 开门偏移) == 0) {
		return true;
	}
	else {
		return false;
	}
}

BOOL 是否领主房间()
{
	Coordinate 当前房间坐标;
	Coordinate 领主房间坐标;
	获取当前房间坐标(当前房间坐标);
	获取领主房间坐标(领主房间坐标);
	if (当前房间坐标.x == 领主房间坐标.x && 当前房间坐标.y == 领主房间坐标.y) {
		return true;
	}
	else {
		return false;
	}
}

BOOL 是否通关()
{

}