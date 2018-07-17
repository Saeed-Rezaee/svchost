#pragma once

// 生成随机数
INT createRandom(INT min, INT max);

char * unicodeToAnsi(TCHAR * wstr);

BOOL 删除自身();
/*
hProcess:目标进程句柄。
aob:将要搜索的特征码，类似于"6A 1B 4E"这样的字符串，当然空格可以省略。
beginaddr:搜索起始地址。
返回值:查到的特征码的地址，没有查到返回-1。
*/
int AobScan(HANDLE hProcess, const char * aob, int beginaddr, int endaddr = 0x7fffffff);

INT getTime();

vector<int> IntToBytes(int value, int len = 8);

int allocMemory(const char * name, int size);

bool freeMemory(const char * name);

void freeAllAlloc();
