#include "Enemy.h"
#include<numbers>
void Enemy::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position; // 初期配置

	worldTransform_.translation_.x = 1;
	worldTransform_.translation_.y = 1;

	model_ = model;

	viewProjection_ = viewProjection;

	// 初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / -2.0f;
}

void Enemy::Update() {}

void Enemy::Draw() { model_->Draw(worldTransform_, *viewProjection_); }
