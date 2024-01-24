#pragma once
#include <wrl.h>
#include <dxgi1_6.h>
#include <d3d12.h>
#include "WinApp.h"
#include <vector>
#include <chrono>

class DirectXCommon
{

public:
	void Initialize(WinApp* winApp);

	// Getter
	ID3D12Device* GetDevice() const { return device.Get(); }
	ID3D12GraphicsCommandList* GetCommandList() const { return commandList.Get(); }

	// �`��O����
	void PreDraw();
	// �`��㏈��
	void PostDraw();

	// �X���b�v�`�F�[��
	DXGI_SWAP_CHAIN_DESC1 GetSwapChainDesc() { return swapChainDesc; }

	// RTV�f�B�X�N
	D3D12_RENDER_TARGET_VIEW_DESC GetRtvDesc() { return rtvDesc; }

	// SRV�f�B�X�N���v�^�q�[�v
	ID3D12DescriptorHeap* GetSrvDescriptorHeap() { return srvDescriptorHeap.Get(); }

private:
	void DeviceInitialize();
	void CommandInitialize();
	void SwapChainInitialize();
	void RenderTargetInitialize();
	void DepthBufferInitialize();
	void FenceInitialize();

	// �f�B�X�N���v�^�q�[�v�쐬
	ID3D12DescriptorHeap* CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescripots, bool shaderVisible);

	// FPS�Œ菉��������
	void InitializeFixFPS();
	// FPS�Œ�X�V����
	void UpdateFixFPS();

public:
	static const uint32_t kMaxSRVCount;

private:
	WinApp* winApp = nullptr;

	Microsoft::WRL::ComPtr<ID3D12Device> device;
	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList;
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> commandQueue;

	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc{};
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeap;
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;

	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuff;
	D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc{};
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	UINT64 fenceVal = 0;

	D3D12_RESOURCE_BARRIER barrierDesc{};

	// �L�^�p���Ԍv���̕ϐ�
	std::chrono::steady_clock::time_point reference_;

	// �����_�[�^�[�Q�b�g�r���[�̐ݒ�
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc{};

	// �f�B�X�N���v�^�q�[�v
	// RTV(�Q�[����ʂ�ۑ����Ă���)
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvDescriptorHeap;
	// SRV(�摜�Ȃǂ�ۑ����Ă�������)
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvDescriptorHeap;

};

