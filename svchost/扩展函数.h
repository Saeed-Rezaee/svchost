#pragma once

// ���������
INT createRandom(INT min, INT max);

char * unicodeToAnsi(TCHAR * wstr);

BOOL ɾ������();
/*
hProcess:Ŀ����̾����
aob:��Ҫ�����������룬������"6A 1B 4E"�������ַ�������Ȼ�ո����ʡ�ԡ�
beginaddr:������ʼ��ַ��
����ֵ:�鵽��������ĵ�ַ��û�в鵽����-1��
*/
int AobScan(HANDLE hProcess, const char * aob, int beginaddr, int endaddr = 0x7fffffff);

INT getTime();

vector<int> IntToBytes(int value, int len = 8);

int allocMemory(const char * name, int size);

bool freeMemory(const char * name);

void freeAllAlloc();
