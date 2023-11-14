#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Sprite.h"
#include "SpriteCommon.h"

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

    // スプライトコモン
    SpriteCommon* spriteCommon = new SpriteCommon();
    spriteCommon->Initialize();

    Sprite* sprite = new Sprite();
    sprite->Initialize();

    // ゲームループ
    while (true) {
        // 更新
        if (winApp_->Update() == true){
            break;
        }

        input_->Update();

        // 描画前処理
        dxCommon_->PreDraw();

        // 描画後処理
        dxCommon_->PostDraw();
    }

    delete input_;

    winApp_->Finalize();
    delete winApp_;
    delete dxCommon_;

    delete spriteCommon;
    delete sprite;

    return 0;
}