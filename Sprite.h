#pragma once
#include "DirectXCommon.h"
#include <d3d12.h>
#include <wrl.h>
#include "SpriteCommon.h"
#include <DirectXMath.h>

// 単体
class Sprite
{
public:
	void Initialize(DirectXCommon* dxCommon, SpriteCommon* common);
	void Update();
	void Draw();

private:
	struct Transform{
		DirectX::XMFLOAT3 scale;
		DirectX::XMFLOAT3 rotate;
		DirectX::XMFLOAT3 translate;
	};

	struct  VertexData{
		DirectX::XMFLOAT4 position;
		DirectX::XMFLOAT2 texcoord;
	};

private:
	void CreateVertex();
	void CreateMaterial();
	void CreateWVP();
private:
	DirectXCommon* dxCommon_ = nullptr;
	SpriteCommon* common_ = nullptr;

	// 頂点情報
	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};

	// マテリアル情報
	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource;
	
	// 行列情報
	Microsoft::WRL::ComPtr<ID3D12Resource> wvpResource;
	DirectX::XMMATRIX* wvpData = nullptr;

	D3D12_GPU_DESCRIPTOR_HANDLE textureSrvHandleGPU;

	// パラメータ
	DirectX::XMFLOAT4 color_ = { 1.0f,1.0f,1.0f,1.0f };

	Transform transform = { {1,1,1}, {0,0,0},{0,0,0} };

	// カメラ
	Transform cameraTransform{ {1,1,1},{0,0,0},{0,0,-5} };
};
