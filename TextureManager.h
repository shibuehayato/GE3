#pragma once
#include "DirectXCommon.h"
#include <string>
#include "DirectXTex/DirectXTex.h"

class TextureManager
{
private:
	struct TextureData {
		std::wstring filePath;
		DirectX::TexMetadata metaData;
		Microsoft::WRL::ComPtr<ID3D12Resource> resource;
		D3D12_CPU_DESCRIPTOR_HANDLE srvHandleCPU;
		D3D12_GPU_DESCRIPTOR_HANDLE srvHandleGPU;
	};

public:
	// �V���O���g��
	static TextureManager* Getinstance();
	void Finalize();

	// ������
	void Initialize(DirectXCommon* dxCommon);

	// �摜�ǂݍ���
    void LoadTexture(const std::wstring& filePath);

	// �w�肵���摜���z��̉��Ԗڂɂ���̂��m�F
	uint32_t GetTextureIndexFilePath(const std::wstring& filePath);
	// �w�肵���v�f�ԍ���GPU�n���h�����󂯎��
	D3D12_GPU_DESCRIPTOR_HANDLE GetSrvHandleGPU(uint32_t textureIndex);

	// ���^�f�[�^�擾
	const DirectX::TexMetadata& GetMetaData(uint32_t textureIndex);

private:
	void UploadTextureData(ID3D12Resource* texture, const DirectX::ScratchImage& mipImages);
	static TextureManager* instance;
	static uint32_t kSRVIndexTop;

	TextureManager() = default;
	~TextureManager() = default;
	TextureManager(TextureManager&) = delete;
	TextureManager& operator =(TextureManager&) = delete;
	// �e�N�X�`���f�[�^
	std::vector<TextureData> textureDatas;
	DirectXCommon* dxCommon_ = nullptr;
};

