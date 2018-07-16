// svchost.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "扩展函数.h"

HWND hWnd;
DWORD dwProcessId;
HANDLE hProcess;

HHOOK g_hHook = NULL;
DWORD g_dwMainThreadId;
// 打开游戏进程 0成功 1 未找到窗口 2打开进程失败 
INT OpenGameProcess()
{
	hWnd = FindWindow(NULL,L"网易有道词典");
	if (!hWnd) {
		return 1;
	}
	GetWindowThreadProcessId(hWnd, &dwProcessId);
	hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, false, dwProcessId);
	if (!hProcess) {
		return 2;
	}
	return 0;
}

LRESULT CALLBACK KeyPress(int nCode, WPARAM wParam, LPARAM lParam)
{
	CWPSTRUCT* p = (CWPSTRUCT*)lParam;
	if (nCode == HC_ACTION)
	{
		switch (wParam) //wParam中是消息ID
		{
			// 键盘消息
			case WM_KEYDOWN:
			{
				printf("%d\n", p->lParam);
			}
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

BOOL WINAPI ConsoleCtrlhandler(DWORD dwCtrlType)
{
	if (dwCtrlType == CTRL_CLOSE_EVENT)
	{
		UnhookWindowsHookEx(g_hHook);
		PostThreadMessage(g_dwMainThreadId, WM_QUIT, 0, 0);
	}
	return TRUE;
}

VOID 全局键盘钩子开始()
{
	g_dwMainThreadId = GetCurrentThreadId();
	SetConsoleCtrlHandler(ConsoleCtrlhandler, TRUE);
	g_hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyPress, GetModuleHandle(NULL), NULL);
	if (g_hHook == NULL)
		printf("hook failure!");
}

VOID 全局键盘钩子结束()
{
	SetConsoleCtrlHandler(ConsoleCtrlhandler, FALSE);
}  

VOID 程序开始()
{
	删除自身();
	全局键盘钩子开始();
}

VOID 程序结束()
{
	删除自身();
	全局键盘钩子结束();
}

int main()
{
	程序开始();
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	程序结束();
	return 0;
}

