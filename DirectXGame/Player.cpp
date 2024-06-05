#include "Player.h"
#include <cassert>
#include<numbers>
#include <Input.h>
#include"MathUtilityFortext.h"
#include<algorithm>
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

	worldTransform_.translation_.x = 1;
	worldTransform_.translation_.y = 1;

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
			//左移動中の右入力
			if (velocity_.x < 0.0f)
			{
				//速度と逆方向に入力中は急ブレーキ
				velocity_.x *= (1.0f - kAcceleration);	
			}
			acceleration.x += kAcceleration;	
		}
		else if (Input::GetInstance()->PushKey(DIK_LEFT)) {
			
			//右移動中の左入力
			if (velocity_.x > 0.0f)
			{
				// 速度と逆方向に入力中は急ブレーキ
				velocity_.x *= (1.0f - kAcceleration);
			}

			acceleration.x-=kAcceleration;
		}
		//加速/減速
		velocity_+=acceleration;	
	} else {
		// 非入力時は移動減衰をかける（kAccelerationは速度減衰率）
		velocity_.x *= (1.0f - kAttenuation);
	}

	




	//最大速度制限
	velocity_.x = std::clamp(velocity_.x, -kLimitRunSpeed, kLimitRunSpeed);



	//移動
	worldTransform_.translation_ +=velocity_;

	//行列計算
	worldTransform_.UpdateMatrix();
}

/// <summary>
/// 描画処理
/// </summary>
void Player::Draw() { model_->Draw(worldTransform_, *viewProjection_); }