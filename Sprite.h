#pragma once
#include "DirectXCommon.h"
#include <d3d12.h>
#include <wrl.h>
#include "SpriteCommon.h"
#include <DirectXMath.h>

// �P��
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

	// ���_���
	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};

	// �}�e���A�����
	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource;
	
	// �s����
	Microsoft::WRL::ComPtr<ID3D12Resource> wvpResource;
	DirectX::XMMATRIX* wvpData = nullptr;

	// �p�����[�^
	DirectX::XMFLOAT4 color_ = { 1.0f,0.0f,0.0f,1.0f };

	Transform transform = { {1,1,1}, {0,0,0},{0,0,0} };

	// �J����
	Transform cameraTransform{ {1,1,1},{0,0,0},{0,0,-5} };
};
