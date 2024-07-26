#include "Enemy.h"

void Enemy::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position; // 初期配置

	worldTransform_.translation_.x = 1;
	worldTransform_.translation_.y = 1;

	


}
