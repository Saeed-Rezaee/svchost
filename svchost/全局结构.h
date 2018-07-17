#pragma once
#include <vector>

using namespace std;

struct 屏幕分辨率
{
	int 宽,高;
};

struct Coordinate {
	int x, y, z;
};

struct RoomInfo {
	Coordinate coordinate;
	Coordinate parent_coordinate;
	int weight;
	int numbering;
	bool up;
	bool bottom;
	bool left;
	bool right;
};

struct MapInfo {
	int width;
	int height;
	const char * name;
	vector<int> channel;
	Coordinate start_coordinate;
	Coordinate end_coordinate;
};

struct 地图结构
{
	int 地图地址;
	int 首地址;
	int 尾地址;
	int 对象数量;
	int 对象地址;
	int 对象阵营;
	int 对象类型;
	int 对象血量;
};

struct 背包结构
{
	int 背包地址;
	int 背包首地址;
	int 物品首地址;
	int 物品地址;
	int 物品属性;
	const char *物品名称;
};

struct 任务结构
{
	int 任务地址;
	int 首地址;
	int 尾地址;
	int 任务数量;
};

struct 内存结构
{
	int first_addr;
	int size;
};

struct 游戏窗口
{
	int top;
	int bottom;
	int left;
	int right;
	int width;
	int height;
};