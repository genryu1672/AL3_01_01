#include "DeathParticles.h"
#include<cassert>
#include<algorithm>
#include"MathUtilityFortext.h"
void DeathParticles::Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position) {


	// Nullポインタチェック
	assert(model);

	model_ = model;
	viewProjection_ = viewProjection;

	//ワールド変換の初期化
	for (auto& WorldTransform : worldTransforms_)
	{
		WorldTransform.Initialize();
		WorldTransform.translation_ = position;
	}



}

void DeathParticles::Update() {

	//ワールド変換の更新
	for (uint32_t i = 0; i < kNumParticles; ++i)
	{
		//基本となる速度ベクトル
		Vector3 velocity = {kSpeed, 0, 0};
		//回転角を計算する
		float angle = kAngleUnit * i;
		//z軸まわり回転行列
		Matrix4x4 matrixRotation = MakeRotateZMatrix(angle);
		//基本ベクトルを回転させて速度ベクトルを得る
		//velocity = Transform(velocity, matrixRotation);
		//移動処理
		//WorldTransforms_[i].translation_ += velocity;

		//worldTransforms_[i]->Up

	}


	for (auto& WorldTransform : worldTransforms_) {
		WorldTransform.UpdateMatrix();
		
	}






}

void DeathParticles::Draw() {

	//終了なら何もしない
	//if (isFinished_)
	//{
	//
	//}

	//3Dモデルを描画
	for (auto& worldtransform : worldTransforms_)
	{
		model_->Draw(worldtransform,*viewProjection_);
		//model_->Draw(worldtransform, *viewProjection_, &objectColor_);
	}



}
