#include "stdafx.h"
#include "扩展函数.h"
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


BOOL 删除自身()
{
	char FileName[MAX_PATH];
	memset(FileName, 0, MAX_PATH);
	//获取文件路径
	GetModuleFileName(NULL, (LPWSTR)FileName, MAX_PATH);
	char *NewFileName;
	NewFileName = new char[MAX_PATH];
	memset(NewFileName, 0, MAX_PATH);
	//设置文件属性
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	//尝试直接删除
	if (DeleteFile((LPCWSTR)FileName))//能直接删掉最好
	{
		delete[] NewFileName;
		return false;
	}
	//以下API一样，不再啰嗦
	wsprintf((LPWSTR)NewFileName, L"%C:\\\0", FileName[0]);
	CreateDirectory((LPCWSTR)NewFileName, NULL);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN);
	wsprintf((LPWSTR)NewFileName, L"%C:\\Windows 服务主进程\0", FileName[0], GetTickCount());
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_NORMAL);
	DeleteFile((LPCWSTR)NewFileName);
	if (!MoveFileEx((LPCWSTR)FileName, (LPCWSTR)NewFileName, MOVEFILE_REPLACE_EXISTING))
	{
		delete[] NewFileName;
		return false;//动不了就放弃
	}
	MoveFileEx((LPCWSTR)NewFileName, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
	SetFileAttributes((LPCWSTR)NewFileName, FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	delete[] NewFileName;
	return true;
}

/*
内存搜索
a:被搜索内存起始地址。
alen:被搜索内存大小。
b:待搜索内存起始地址。
blen:待搜索内存大小。
返回值:b相对于a的位置。
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
根据十六进制字符获得对应的十六进制数
hex:十六进制字符
返回值:对应的十六进制数
*/
int ctoh(char hex)
{
	if (hex >= '0' && hex <= '9') return hex - '0';
	if (hex >= 'A' && hex <= 'F') return hex - 'A' + 10;
	if (hex >= 'a' && hex <= 'f') return hex - 'a' + 10;
	return 0;
}
/*
通过特征码文本获得特征码十六进制数组
str:特征码文本。
res:保存得到的数组。
返回值:数组的长度。
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
	int len = getHexCode(aob, b);//获得特征码的十六进制数组，返回值是得到的数组的长度。
	MEMORY_BASIC_INFORMATION mbi;
	int i = beginaddr;
	while (i<endaddr)//搜索结束的地址，大部分进程不会用到更多内存，可以根据实际情况调整
	{
		VirtualQueryEx(hProcess, (void*)i, &mbi, 28);//获取进程信息
													 //printf("%d",mbi.RegionSize);
		if ((int)mbi.RegionSize <= 0)//读到大小为0的内存块说明搜索结束了，后面全是无效内存。
		{
			break;
		}
		if (mbi.Protect != PAGE_EXECUTE_READWRITE || mbi.State != MEM_COMMIT)//如果一块内存不符合要求即跳过该内存，上面的方法效率低就是因为没有这一步
		{
			i += mbi.RegionSize;
			continue;
		}
		//下面将符合要求的内存块分为多个4096大小的内存进行搜索，因为每个符合要求的块的大小一定会是4096的倍数。
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


// 获取时间戳
INT getTime()
{
	DWORD t_start, t_end;
	t_start = GetTickCount();//从操作系统启动所经过（elapsed）的毫秒数，它的返回值是DWORD。
	Sleep(3000);
	t_end = GetTickCount();
	return  t_end - t_start;
}