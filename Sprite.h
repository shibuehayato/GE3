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

	//Getter/Setter
	DirectX::XMFLOAT3 GetPosition() { return position; }

	void SetPosition(DirectX::XMFLOAT3 pos) { position = pos; }

private:
	struct Transform{
		DirectX::XMFLOAT3 scale;
		DirectX::XMFLOAT3 rotate;
		DirectX::XMFLOAT3 translate;
	};

	// ���_���
	struct  VertexData{
		DirectX::XMFLOAT4 position;
		DirectX::XMFLOAT2 texcoord;
	};

	// �}�e���A��
	struct MaterialData{
		DirectX::XMFLOAT4 color;
		DirectX::XMMATRIX uvTransform;
	};

private:
	// ���_���쐬
	void CreateVertex();
	// �C���f�b�N�X���쐬
	void CreateIndex();
	// �}�e���A�����쐬
	void CreateMaterial();
	// �s����쐬
	void CreateWVP();
private:
	DirectXCommon* dxCommon_ = nullptr;
	SpriteCommon* common_ = nullptr;

	// ���_���
	Microsoft::WRL::ComPtr<ID3D12Resource> vertexResource;
	D3D12_VERTEX_BUFFER_VIEW vertexBufferView{};

	// �C���f�b�N�X
	Microsoft::WRL::ComPtr<ID3D12Resource> indexResource;
	D3D12_INDEX_BUFFER_VIEW indexBufferView{};

	// �}�e���A�����
	Microsoft::WRL::ComPtr<ID3D12Resource> materialResource;
	MaterialData* materialData = nullptr;

	// �s����
	Microsoft::WRL::ComPtr<ID3D12Resource> wvpResource;
	DirectX::XMMATRIX* wvpData = nullptr;

	D3D12_GPU_DESCRIPTOR_HANDLE textureSrvHandleGPU;

	// �p�����[�^
	DirectX::XMFLOAT4 color_ = { 1.0f,1.0f,1.0f,1.0f };
	// UV���W
	Transform uvTransform = { {1,1,1},{0,0,0},{0,0,0} };

	Transform transform = { {1,1,1}, {0,0,0},{0,0,0} };
	DirectX::XMFLOAT3 position = { 0,0,0 };

	// �J����
	Transform cameraTransform{ {1,1,1},{0,0,0},{0,0,-5} };
};
