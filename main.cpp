#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"
#include "ImGuiManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ポインタ置き場
    Input* input_ = nullptr;
    WinApp* winApp_ = nullptr;
    DirectXCommon* dxCommon_ = nullptr;

// WindowsAPI初期化処理
    winApp_ = new WinApp();
    winApp_->Initialize();

// DirectX初期化処理
    dxCommon_ = new DirectXCommon();
    dxCommon_->Initialize(winApp_);

    input_ = new Input();
    input_->Initialize(winApp_);

    ImGuiManager* imgui = ImGuiManager::Create();
    ImGuiManager::Initialize(winApp_->GetHwnd(), dxCommon_);

    // スプライトコモン
    SpriteCommon* spriteCommon = new SpriteCommon();
    spriteCommon->Initialize(dxCommon_);

    Sprite* sprite = new Sprite();
    sprite->Initialize(dxCommon_,spriteCommon);

    // ゲームループ
    while (true) {
        // 更新
        if (winApp_->Update() == true){
            break;
        }
        ImGuiManager::NewFrame();
        imgui->ShowDemo();

        input_->Update();
        sprite->Update();
        // 描画前処理
        ImGuiManager::CreateCommand();
        dxCommon_->PreDraw();

        sprite->Draw();

        // 描画後処理
        ImGuiManager::CommandsExcute(dxCommon_->GetCommandList());
        dxCommon_->PostDraw();
    }
    delete input_;

    winApp_->Finalize();
    delete winApp_;
    delete dxCommon_;

    delete imgui;

    delete spriteCommon;
    delete sprite;

    return 0;
}