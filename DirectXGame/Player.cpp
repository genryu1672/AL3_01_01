#include "Player.h"
#include <cassert>
#include<numbers>
#include <Input.h>
#include"MathUtilityFortext.h"
/// <summary>
/// 初期化
/// </summary>
void Player::Initialize(Model* model, ViewProjection* viewProjection,const Vector3&position) {
	// Nullポインタチェック
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	viewProjection_ = viewProjection;

	// ワールド変換の初期化
	worldTransform_.Initialize();
	worldTransform_.translation_ = position;//初期配置

	worldTransform_.translation_.x = 7;
	worldTransform_.translation_.y = 7;

	//初期回転
	worldTransform_.rotation_.y = std::numbers::pi_v<float> / 2.0f;
}

/// <summary>
/// 更新処理
/// </summary>
void Player::Update() {
	// 行列を更新して定数バッファに転送
	worldTransform_.UpdateMatrix();

	//移動入力
	//左右移動
	if (Input::GetInstance()->PushKey(DIK_RIGHT) ||
		Input::GetInstance()->PushKey(DIK_LEFT))
	{
		//左右加速
		Vector3 acceleration = {};
		if (Input::GetInstance()->PushKey(DIK_RIGHT))
		{
			acceleration.x += kAcceleration;
		}
		else if (Input::GetInstance()->PushKey(DIK_LEFT) {
			acceleration.x-=kAcceleration;
		}
		//加速/減速
		velocity_+=acceleration;	
	}






	//移動
	worldTransform_.translation_ +=velocity_;

	//行列計算
	worldTransform_.UpdateMatrix();
}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() { model_->Draw(worldTransform_, *viewProjection_); }