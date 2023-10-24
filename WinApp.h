#pragma once
#include <Windows.h>

// WindowsAPI
class WinApp
{
public: 
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void Initialize();
	void Update();
};