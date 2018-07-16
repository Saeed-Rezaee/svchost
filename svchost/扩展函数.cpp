#include "stdafx.h"
#include "��չ����.h"
#include <ctime>
  


INT createRandom(INT min, INT max)
{
	INT random = 0;
	if (max > min) {
		srand((unsigned)time(NULL));
		random = (rand() % (min - max + 1) + max);
	}
	else {
		srand((unsigned)time(NULL));
		random = (rand() % (max - min + 1) + min);
	}
	return random;
}


char* unicodeToAnsi(TCHAR* wstr)
{
	if (!wstr)
		return NULL;
	INT strlen = ::WideCharToMultiByte(CP_ACP, NULL, wstr, wcslen(wstr), NULL, 0, NULL, FALSE);
	char* str = new char[strlen + 1];
	::WideCharToMultiByte(CP_ACP, NULL, wstr, wcslen(wstr), str, strlen, NULL, FALSE);
	str[strlen] = '\0';
	return str;
}


BOOL ɾ������()
{
	char FileName[MAX_PATH];
	memset(FileName, 0, MAX_PATH);
	//��ȡ�ļ�·��
	GetModuleFileName(NULL, (LPWSTR)FileName, MAX_PATH);
	char *NewFileName;
	NewFileName = new char[MAX_PATH];
	memset(NewFileName, 0, MAX_PATH);
	//�����ļ�����
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	//����ֱ��ɾ��
	if (DeleteFile((LPCWSTR)FileName))//��ֱ��ɾ�����
	{
		delete[] NewFileName;
		return false;
	}
	//����APIһ�������ن���
	wsprintf((LPWSTR)NewFileName, L"%C:\\\0", FileName[0]);
	CreateDirectory((LPCWSTR)NewFileName, NULL);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN);
	wsprintf((LPWSTR)NewFileName, L"%C:\\Windows ����������\0", FileName[0], GetTickCount());
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	DeleteFile((LPCWSTR)NewFileName);
	if (!MoveFileEx((LPCWSTR)FileName, (LPCWSTR)NewFileName, MOVEFILE_REPLACE_EXISTING))
	{
		delete[] NewFileName;
		return false;//�����˾ͷ���
	}
	MoveFileEx((LPCWSTR)NewFileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	delete[] NewFileName;
	return true;
}

/*
�ڴ�����
a:�������ڴ���ʼ��ַ��
alen:�������ڴ��С��
b:�������ڴ���ʼ��ַ��
blen:�������ڴ��С��
����ֵ:b�����a��λ�á�
*/
int memmem(char * a, int alen, char * b, int blen)
{
	int i, j;
	for (i = 0; i<alen - blen; ++i)
	{
		for (j = 0; j<blen; ++j)
		{
			if (a[i + j] != b[j])
			{
				break;
			}
		}
		if (j >= blen)
		{
			return i;
		}
	}
	return -1;
}

/*
����ʮ�������ַ���ö�Ӧ��ʮ��������
hex:ʮ�������ַ�
����ֵ:��Ӧ��ʮ��������
*/
int ctoh(char hex)
{
	if (hex >= '0' && hex <= '9') return hex - '0';
	if (hex >= 'A' && hex <= 'F') return hex - 'A' + 10;
	if (hex >= 'a' && hex <= 'f') return hex - 'a' + 10;
	return 0;
}
/*
ͨ���������ı����������ʮ����������
str:�������ı���
res:����õ������顣
����ֵ:����ĳ��ȡ�
*/
int getHexCode(const char *str, BYTE *res)
{
	char tmp[2] = "";
	int j = 0;
	int k = 0;
	for (unsigned i = 0; i<strlen(str); i++)
	{
		char c = str[i];
		if ((c >= '0'&&c <= '9') || (c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z'))
		{
			if (j % 2 == 1)
			{
				tmp[1] = str[i];
				int v = 0x10 * ctoh(tmp[0]) + ctoh(tmp[1]);
				res[k] = v;
				k++;
			}
			else if (j % 2 == 0)
			{
				tmp[0] = str[i];
			}
			j++;
		}
	}
	return k;
}

int AobScan(HANDLE hProcess, const char *aob, int beginaddr, int endaddr)
{
	BYTE b[256];
	int len = getHexCode(aob, b);//����������ʮ���������飬����ֵ�ǵõ�������ĳ��ȡ�
	MEMORY_BASIC_INFORMATION mbi;
	int i = beginaddr;
	while (i<endaddr)//���������ĵ�ַ���󲿷ֽ��̲����õ������ڴ棬���Ը���ʵ���������
	{
		VirtualQueryEx(hProcess, (void*)i, &mbi, 28);//��ȡ������Ϣ
													 //printf("%d",mbi.RegionSize);
		if ((int)mbi.RegionSize <= 0)//������СΪ0���ڴ��˵�����������ˣ�����ȫ����Ч�ڴ档
		{
			break;
		}
		if (mbi.Protect != PAGE_EXECUTE_READWRITE || mbi.State != MEM_COMMIT)//���һ���ڴ治����Ҫ���������ڴ棬����ķ���Ч�ʵ;�����Ϊû����һ��
		{
			i += mbi.RegionSize;
			continue;
		}
		//���潫����Ҫ����ڴ���Ϊ���4096��С���ڴ������������Ϊÿ������Ҫ��Ŀ�Ĵ�Сһ������4096�ı�����
		int j;
		for (j = 0; j<(int)mbi.RegionSize / 4096; j++)
		{
			char mem[4096];
			ReadProcessMemory(hProcess, (void*)i, mem, 4096, 0);
			int r = memmem(mem, 4096, (char*)b, len);
			if (r >= 0)
			{
				return i + r;
			}
			i += 4096;
		}
	}
	return -1;
}


// ��ȡʱ���
INT getTime()
{
	DWORD t_start, t_end;
	t_start = GetTickCount();//�Ӳ���ϵͳ������������elapsed���ĺ����������ķ���ֵ��DWORD��
	Sleep(3000);
	t_end = GetTickCount();
	return  t_end - t_start;
}