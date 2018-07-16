#pragma once
using namespace std;
// 读内存
BOOL readMemory(INT baseAddress, LPVOID lpBuffer, INT nSize);
// 读字节
BYTE readByte(INT address);
// 读短整形
SHORT readShort(INT address);
// 读整形
INT readInteger(INT address);
// 读长整形
LONGLONG readLong(INT address);
// 读单浮点型
FLOAT readFloat(INT lpBaseAddress);
// 读双浮点型
DOUBLE readDouble(INT lpBaseAddress);
// 读字节数组
vector<byte> readBytes(INT lpBaseAddress, INT len);
// 读字符串
CHAR * readString(INT lpBaseAddress, INT len);
// 写内存
BOOL writeMemory(INT lpBaseAddress, LPCVOID lpBuffer, INT nSize);
// 写字节
BOOL writeByte(INT lpBaseAddress, BYTE lpBuffer);
// 写短整形
BOOL writeShort(INT lpBaseAddress, SHORT lpBuffer);
// 写整形
BOOL writeInteger(INT lpBaseAddress, INT lpBuffer);
// 写长整形
BOOL writeLong(INT lpBaseAddress, LONGLONG lpBuffer);
// 写单浮点
BOOL writeFloat(INT lpBaseAddress, FLOAT lpBuffer);
// 写双浮点
BOOL writeDouble(INT lpBaseAddress, DOUBLE lpBuffer);
// 写字节数组
BOOL writeBytes(INT lpBaseAddress, vector<byte> bytes);
// 写字符串
BOOL writeString(INT lpBaseAddress, LPCWSTR lpBuffer);
