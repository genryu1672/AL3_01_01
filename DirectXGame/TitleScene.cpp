#include "TitleScene.h"
#include "GameScene.h"
void TitleScene::Initialize() {

	//dxCommon_ = DirectXCommon::GetInstance();
	//input_ = Input::GetInstance();
	//
	//modelFont_ = Model::CreateFromOBJ("titleFont");
	//modelPlayer_ = Model::CreateFromOBJ("player");
	//
	//viewProjection_.Initialize();
	//
	//worldTransformFont_.Initialize();
	//worldTransformPlayer_.Initialize();
}



void TitleScene::Update() {

	if (Input::GetInstance()->PushKey(DIK_SPACE))
	{
		finished_ = true;
	}




}

void TitleScene::Draw() {

	//コマンドリストの取得
	//ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	//3Dオブジェクト描画前処理
	//Model::PreDraw(commandList);

	//ここに３Dオブジェクトの描画処理を追加できる
	//modelFont_->Draw(worldTransformFont_, viewProjection_);
	//modelPlayer_->Draw(worldTransformPlayer_, viewProjection_);

	//3Dオブジェクト描画後処理
	//Model::PostDraw();
}
