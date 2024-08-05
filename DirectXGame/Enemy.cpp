#include "Enemy.h"
#include<numbers>
#include<cassert>
#include"MathUtilityFortext.h"
void Enemy::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {

	assert(model);
	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position; // 初期配置

	/*worldTransform_.translation_.x = 1;
	worldTransform_.translation_.y = 1;*/

	model_ = model;

	viewProjection_ = viewProjection;

	// 初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / -2.0f;

	//速度を設定する
	velocity_ = {-kWalkSpeed, 0, 0};

	walkTimer_ = 0.0f;

}

void Enemy::Update() { 
	
	//移動
	worldTransform_.translation_ += velocity_;
	
	walkTimer_ += 1.0f / 60.0f;

	//回転アニメーション
	worldTransform_.rotation_.x = std::sin(2 * std::numbers::pi_v<float> * walkTimer_ / kWalkMotionTime);

	worldTransform_.UpdateMatrix();


}

void Enemy::Draw() { model_->Draw(worldTransform_, *viewProjection_); }

void Enemy::OnCollision(const Player* player)
{
	(void)player; }

void Enemy::GetAABB() {}
