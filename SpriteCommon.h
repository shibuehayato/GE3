#pragma once
#include <dxcapi.h>
#include <string>

// ‹¤’Ê
class SpriteCommon
{
public:
	void Initialize();

private:
	static IDxcBlob* CompileShader(
		const std::wstring& filePath,
		const wchar_t* profile,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler
		);
};

