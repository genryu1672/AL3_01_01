#define NOMINMIN
#define NOMINMAX
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
	
	//移動範囲制限
	viewProjection_.translation_.x = std::max(viewProjection_.translation_.x, movableArea_.left);
	viewProjection_.translation_.x = std::min(viewProjection_.translation_.x, movableArea_.right);
	viewProjection_.translation_.y = std::max(viewProjection_.translation_.y, movableArea_.bottom);
	viewProjection_.translation_.y = std::min(viewProjection_.translation_.y, movableArea_.top);
	//行列を更新する
	viewProjection_.UpdateMatrix();

}

//追従対象のワールドトランスフォームを参照
void CameraController::Reset() {
	const WorldTransform& targetWorldTransform = target_->GetWorldTransform();
	// 追従対象とオフセットからカメラの座標を計算
	//viewProjection_.translation_ = targetWorldTransform.translation_ + targetoffset_;
	
	// 追従対象とオフセットからカメラの目標座標を計算
	targetCoordinates = targetWorldTransform.translation_ + targetoffset_;

	//座標補間によりゆったり追従
	viewProjection_.translation_ = Lerp(viewProjection_.translation_, targetCoordinates, kInterpolationRate);

	//移動範囲制限

	//行列を更新する

}
