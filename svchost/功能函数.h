#pragma once


BOOL 返回角色();

INT 取角色数量();

INT 取当前角色下标();

INT 取游戏状态();

INT 取职业ID();

INT 取副本ID();

BOOL 获取当前房间坐标(Coordinate & 当前房间坐标);

BOOL 获取领主房间坐标(Coordinate & 领主房间坐标);

VOID 坐标CALL(int 对象指针, int x, int y, int z);

INT 解密(int address);

BOOL 选择角色();

BOOL 进入副本();

BOOL 选择副本();

INT 取剩余疲劳();
