#pragma once
#include <vector>

using namespace std;

struct ��Ļ�ֱ���
{
	int ��,��;
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

struct ��ͼ�ṹ
{
	int ��ͼ��ַ;
	int �׵�ַ;
	int β��ַ;
	int ��������;
};

struct �����ṹ
{
	int ������ַ;
	int �����׵�ַ;
	int ��Ʒ�׵�ַ;
};

struct ����ṹ
{
	int �����ַ;
	int �׵�ַ;
	int β��ַ;
	int ��������;
};

struct �ڴ�ṹ
{
	int first_addr;
	int size;
};