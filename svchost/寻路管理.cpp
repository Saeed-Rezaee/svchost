#include "stdafx.h"
#include "寻路管理.h"
#include "读写函数.h"
#include "基址管理.h"

vector<Coordinate> open_list;
vector<Coordinate> close_list;
MapInfo map_info;
vector<vector<RoomInfo>> room_array;
vector<int> path;
unsigned char orientation_vector[16][4] = {
	// 左 右 上 下 
	{ 0, 0, 0, 0 },//0	无
	{ 0, 1, 0, 0 },//1	右
	{ 0, 0, 1, 0 },//2	上
	{ 0, 1, 1, 0 },//3	右	上
	{ 1, 0, 0, 0 },//4	左
	{ 1, 1, 0, 0 },//5	左	右
	{ 1, 0, 1, 0 },//6	左	上
	{ 1, 1, 1, 0 },//7	左	右	上
	{ 0, 0, 0, 1 },//8	下	
	{ 0, 1, 0, 1 },//9	右	下
	{ 0, 0, 1, 1 },//10	上	下
	{ 0, 1, 1, 1 },//11	右	上	下
	{ 1, 0, 0, 1 },//12	左	下
	{ 1, 1, 0, 1 },//13	左	右	下
	{ 1, 0, 1, 1 },//14	左	上	下
	{ 1, 1, 1, 1 } //15	左	右	上	下
};

void read_map_info()
{
	map_info.width = 4;
	map_info.height = 3;
	map_info.name = "ge lan di";
	map_info.channel = { 1,5,12,0,0,9,14,8,0,3,7,6 };
	map_info.start_coordinate.x = 1;
	map_info.start_coordinate.y = 1;
	map_info.end_coordinate.x = 3;
	map_info.end_coordinate.y = 1;
}

void create_room_array()
{
	RoomInfo temp_room_info;
	// 1.初始化容器大小
	room_array.clear();
	room_array.resize(map_info.height);
	for (int x = 0; x < map_info.height; x++)
	{
		room_array[x].resize(map_info.width);
	}
	// 2.生成
	int numbering = 0;
	for (int y = 0; y < map_info.height; y++)
	{
		for (int x = 0; x < map_info.width; x++) {
			temp_room_info.coordinate.x = x;
			temp_room_info.coordinate.y = y;
			temp_room_info.up = orientation_vector[map_info.channel[numbering]][2] == 1 ? true : false;
			temp_room_info.bottom = orientation_vector[map_info.channel[numbering]][3] == 1 ? true : false;
			temp_room_info.left = orientation_vector[map_info.channel[numbering]][0] == 1 ? true : false;
			temp_room_info.right = orientation_vector[map_info.channel[numbering]][1] == 1 ? true : false;
			temp_room_info.weight = abs(map_info.end_coordinate.x - x) + abs(map_info.end_coordinate.y - y);
			temp_room_info.numbering = numbering;
			room_array[y][x] = temp_room_info;
			numbering++;
		}
	}
}

bool has_close_list(RoomInfo room_info)
{
	for (unsigned i = 0; i < close_list.size(); i++)
	{
		if (close_list[i].x == room_info.coordinate.x && close_list[i].y == room_info.coordinate.y)
		{
			return true;
		}
	}
	return false;
}

bool has_open_list(RoomInfo room_info)
{
	for (unsigned i = 0; i < open_list.size(); i++)
	{
		if (open_list[i].x == room_info.coordinate.x && open_list[i].y == room_info.coordinate.y)
		{
			return true;
		}
	}
	return false;
}

int find_min_weight_key()
{
	int key = 0;
	int min_weight;
	int weight;
	for (unsigned i = 0; i < open_list.size(); i++)
	{
		weight = room_array[open_list[i].y][open_list[i].x].weight;
		if (i == 0 || weight < min_weight) {
			min_weight = weight;
			key = i;
		}
	}
	return key;
}

void backtrack(RoomInfo this_room_info)
{
	if (this_room_info.coordinate.x < this_room_info.parent_coordinate.x)
	{
		path.insert(path.begin(), 0);
	}
	else if (this_room_info.coordinate.x > this_room_info.parent_coordinate.x) {
		path.insert(path.begin(), 1);
	}
	else if (this_room_info.coordinate.y > this_room_info.parent_coordinate.y) {
		path.insert(path.begin(), 3);
	}
	else {
		path.insert(path.begin(), 2);
	}
	if (!(this_room_info.parent_coordinate.x == map_info.start_coordinate.x && this_room_info.parent_coordinate.y == map_info.start_coordinate.y)) {

		backtrack(room_array[this_room_info.parent_coordinate.y][this_room_info.parent_coordinate.x]);
	}

}

void path_arithmetic()
{
	Coordinate temp_coordinate;
	RoomInfo current_room_info;
	RoomInfo temp_room_info;
	int min_weight;
	//1.把起始房间坐标加入到开放列表
	open_list.insert(open_list.begin(), map_info.start_coordinate);
	min_weight = room_array[map_info.start_coordinate.y][map_info.start_coordinate.x].weight;
	while (open_list.size() > 0) {
		temp_coordinate = open_list[find_min_weight_key()];
		current_room_info = room_array[temp_coordinate.y][temp_coordinate.x];
		min_weight = current_room_info.weight;
		if (current_room_info.up) {
			temp_room_info = room_array[current_room_info.coordinate.y - 1][current_room_info.coordinate.x];
			if (!has_close_list(temp_room_info) && !has_open_list(temp_room_info))
			{
				open_list.insert(open_list.end(), temp_room_info.coordinate);
				room_array[temp_room_info.coordinate.y][temp_room_info.coordinate.x].parent_coordinate = current_room_info.coordinate;
			}
		}
		if (current_room_info.bottom) {
			temp_room_info = room_array[current_room_info.coordinate.y + 1][current_room_info.coordinate.x];
			if (!has_close_list(temp_room_info) && !has_open_list(temp_room_info))
			{
				open_list.insert(open_list.end(), temp_room_info.coordinate);
				room_array[temp_room_info.coordinate.y][temp_room_info.coordinate.x].parent_coordinate = current_room_info.coordinate;
			}
		}
		if (current_room_info.bottom) {
			temp_room_info = room_array[current_room_info.coordinate.y][current_room_info.coordinate.x - 1];
			if (!has_close_list(temp_room_info) && !has_open_list(temp_room_info))
			{
				open_list.insert(open_list.end(), temp_room_info.coordinate);
				room_array[temp_room_info.coordinate.y][temp_room_info.coordinate.x].parent_coordinate = current_room_info.coordinate;
			}
		}
		if (current_room_info.right) {
			temp_room_info = room_array[current_room_info.coordinate.y][current_room_info.coordinate.x + 1];
			if (!has_close_list(temp_room_info) && !has_open_list(temp_room_info))
			{
				open_list.insert(open_list.end(), temp_room_info.coordinate);
				room_array[temp_room_info.coordinate.y][temp_room_info.coordinate.x].parent_coordinate = current_room_info.coordinate;
			}
		}
		if (temp_room_info.coordinate.x == map_info.end_coordinate.x && temp_room_info.coordinate.y == map_info.end_coordinate.y) {
			backtrack(room_array[temp_room_info.coordinate.y][temp_room_info.coordinate.x]);
			printf("已找到\n"); break;
		}
		open_list.erase(open_list.begin());
		close_list.insert(close_list.begin(), current_room_info.coordinate);
	}
}

int get_direction()
{
	read_map_info();
	create_room_array();
	path_arithmetic();
	for (unsigned i = 0; i < path.size(); i++)
	{
		if (path[i] == 0)
		{
			printf("左\n");
		}
		else if (path[i] == 1) {
			printf("右\n");
		}
		else if (path[i] == 2) {
			printf("上\n");
		}
		else if (path[i] == 3) {
			printf("下\n");
		}
	}
	return path.front();
}
