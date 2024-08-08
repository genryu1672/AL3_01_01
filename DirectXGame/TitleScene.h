#pragma once
#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <vector>
#include "MapChipField.h"
#include"DeathParticles.h"
class TitleScene {

	public: // 引数を書くところ
	/// <summary>
	/// 初期化
	/// </summary>
	// 初期化

	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
	// デスフラグのgetter
	bool IsFinished() const { return finished_; }
	private:

	//終了フラグ
	bool finished_ = false;
	Model* modelFont_ = nullptr;
	Model* modelPlayer_ = nullptr;

	//ビュープロジェクション
	ViewProjection viewProjection_;

	WorldTransform worldTransformFont_;
	WorldTransform worldTransformPlayer_;

	DirectXCommon* dxCommon_ = nullptr;

	float timer_ = 0.0f;
	static inline const float kMotionTime = 1.0f;
};
