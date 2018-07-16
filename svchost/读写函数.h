#pragma once
using namespace std;
// ���ڴ�
BOOL readMemory(INT baseAddress, LPVOID lpBuffer, INT nSize);
// ���ֽ�
BYTE readByte(INT address);
// ��������
SHORT readShort(INT address);
// ������
INT readInteger(INT address);
// ��������
LONGLONG readLong(INT address);
// ����������
FLOAT readFloat(INT lpBaseAddress);
// ��˫������
DOUBLE readDouble(INT lpBaseAddress);
// ���ֽ�����
vector<byte> readBytes(INT lpBaseAddress, INT len);
// ���ַ���
CHAR * readString(INT lpBaseAddress, INT len);
// д�ڴ�
BOOL writeMemory(INT lpBaseAddress, LPCVOID lpBuffer, INT nSize);
// д�ֽ�
BOOL writeByte(INT lpBaseAddress, BYTE lpBuffer);
// д������
BOOL writeShort(INT lpBaseAddress, SHORT lpBuffer);
// д����
BOOL writeInteger(INT lpBaseAddress, INT lpBuffer);
// д������
BOOL writeLong(INT lpBaseAddress, LONGLONG lpBuffer);
// д������
BOOL writeFloat(INT lpBaseAddress, FLOAT lpBuffer);
// д˫����
BOOL writeDouble(INT lpBaseAddress, DOUBLE lpBuffer);
// д�ֽ�����
BOOL writeBytes(INT lpBaseAddress, vector<byte> bytes);
// д�ַ���
BOOL writeString(INT lpBaseAddress, LPCWSTR lpBuffer);
