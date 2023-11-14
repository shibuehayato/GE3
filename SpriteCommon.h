#pragma once
#include <wrl.h>
#include <string>
#include <dxcapi.h>

// ‹¤’Ê
class SpriteCommon
{
public:
	void Initialize();

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
		);
};

