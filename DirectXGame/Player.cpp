#include "Player.h"
#include <cassert>
// 関数の定義
void Player::Initialize(Model* model, uint32_t textureHandle) {
	// NULLポインタチェック
	assert(model);
	model_ = model;
	textureHandle_ = textureHandle;
	// ワールド変換の初期化
	worldTransform_.Initialize();
}

void Player::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Player::Draw(ViewProjection& viewProjection) { model_->Draw(worldTransform_, viewProjection, textureHandle_); }
