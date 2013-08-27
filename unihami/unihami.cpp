#include <Windows.h>
#include <tchar.h>
BOOL WINAPI DllMain( HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved ){
	switch (dwReason)
	{
	case DLL_THREAD_ATTACH:
		break;
	case DLL_PROCESS_ATTACH:
		return true;
		break;
	}
	return true;
}
extern "C" __declspec(dllexport) int WINAPI doSkip(){
	HWND hWnd = GetForegroundWindow();
	if(hWnd!=NULL){
		WCHAR buff[512]={0};
		if(GetClassName(hWnd,buff,sizeof(buff))){
			if(lstrcmpW(buff,_T("ConsoleWindowClass"))){
				return true;
			}
		}
	}
	return false;
}