#pragma once
#include <Windows.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>
#include <wrl.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

class Input
{
public:
	// ������
	void Initialize(HINSTANCE hInstance, HWND hwnd);
	// �X�V
	void Update();

	// �C�ӂ̃{�^�����������Ƃ�
	bool PushKey(BYTE keyNumber);
	// �C�Ӄ{�^���������ꂽ�u��
	bool TriggerKey(BYTE keyNumber);
	// �C�Ӄ{�^���������ꂽ�u��

private:
	Microsoft::WRL::ComPtr<IDirectInputDevice8> keyboard;
	Microsoft::WRL::ComPtr<IDirectInput8> directInput;
	BYTE key[256] = {};
	BYTE keyPre[256] = {};
};

