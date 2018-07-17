#include "stdafx.h"
#include "��д����.h"
#include "��չ����.h"

//=====================================��======================================//
BOOL readMemory(INT baseAddress, LPVOID lpBuffer, INT nSize)
{
	SIZE_T lpNumberOfBytesRead;
	if (!ReadProcessMemory(hProcess, (LPCVOID)baseAddress, lpBuffer, (SIZE_T)nSize, &lpNumberOfBytesRead)) {
		printf("��ȡ %x �ڴ�ʱʧ�ܣ�\n", baseAddress);
		PAUSE;
		return false;
	}
	if (lpNumberOfBytesRead != nSize) {
		printf("��ȡ %x �ڴ�ʱʵ�ʶ�ȡ�ĳ�����Ҫ��ȡ�ĳ��Ȳ�һ�£�\n", baseAddress);
		PAUSE;
		return false;
	}
	return true;
}

BYTE readByte(INT address)
{
	BYTE lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

SHORT readShort(INT address)
{
	SHORT lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

INT readInteger(INT address)
{
	INT lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

LONGLONG readLong(INT address)
{
	LONGLONG lpBuffer;
	readMemory(address, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

FLOAT readFloat(INT lpBaseAddress)
{
	FLOAT lpBuffer;
	readMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

DOUBLE readDouble(INT lpBaseAddress)
{
	DOUBLE lpBuffer;
	readMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
	return lpBuffer;
}

vector<byte> readBytes(INT lpBaseAddress, INT len)
{
	byte * lpBuffer;
	lpBuffer = new byte[len];
	memset(lpBuffer, 0, len);
	readMemory(lpBaseAddress, lpBuffer, len);
	vector<byte>  result;
	result.resize(len);
	for (INT i = 0; i < len; i++)
	{
		result[i] = lpBuffer[i];
	}
	delete[]lpBuffer;
	return result;
}

CHAR* readString(INT lpBaseAddress, INT len)
{
	TCHAR *lpBuffer;
	len = len * 2 + 2;
	lpBuffer = new TCHAR[len];
	readMemory(lpBaseAddress, lpBuffer, len);
	CHAR * str = unicodeToAnsi(lpBuffer);
	return str;
}

//=====================================д======================================//

BOOL writeMemory(INT lpBaseAddress, LPCVOID lpBuffer, INT nSize)
{
	SIZE_T lpNumberOfBytesRead;
	if (!WriteProcessMemory(hProcess, (LPVOID)lpBaseAddress, lpBuffer, (SIZE_T)(nSize), &lpNumberOfBytesRead)) {
		printf("д�� %x �ڴ�ʱʧ�ܣ�\n", lpBaseAddress);
		return false;
	}
	if (lpNumberOfBytesRead != nSize) {
		printf("д�� %x �ڴ�ʱʵ��д��ĳ�����Ҫд��ĳ��Ȳ�һ�£�\n", lpBaseAddress);
		return false;
	}
	return true;
}

BOOL writeByte(INT lpBaseAddress, BYTE lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeShort(INT lpBaseAddress, SHORT lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeInteger(INT lpBaseAddress, INT lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeLong(INT lpBaseAddress, LONGLONG lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeFloat(INT lpBaseAddress, FLOAT lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeDouble(INT lpBaseAddress, DOUBLE lpBuffer)
{
	return writeMemory(lpBaseAddress, &lpBuffer, sizeof(lpBuffer));
}

BOOL writeBytes(INT lpBaseAddress, vector<int> bytes)
{
	INT size = bytes.size();
	byte *lpBuffer = new byte[size];
	for (INT i = 0; i < size; i++)
	{
		lpBuffer[i] = bytes[i];
	}
	bool result = writeMemory(lpBaseAddress, lpBuffer, size);
	delete[]lpBuffer;
	return result;
}

BOOL writeString(INT lpBaseAddress, LPCWSTR lpBuffer)
{
	INT len = wcslen(lpBuffer) * 2 + 2;
	return writeMemory(lpBaseAddress, (LPCVOID)lpBuffer, len);
}
