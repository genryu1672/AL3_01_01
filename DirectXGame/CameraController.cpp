#include "CameraController.h"
#include"Player.h"
void CameraController::Initialize() {
	
	//ViewProjection*viewProjection=nullptr;
	viewProjection_.Initialize();
}

void CameraController::Update() {
	//追従対象のワールドトランスフォームを参照
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	//追従対象とオフセットからカメラの座標計算
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetoffset_;
	//行列を更新する
	viewProjection_.UpdateMatrix();
}

//追従対象のワールドトランスフォームを参照
void CameraController::Reset() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	// 追従対象とオフセットからカメラの座標を計算
	viewProjection_.translation_ = targetWorldTransform.translation_ + targetoffset_;
}
