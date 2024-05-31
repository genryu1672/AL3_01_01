#pragma once
#include "Model.h"
#include "WorldTransform.h"

/// <summary>
///	自キャラ
/// </summary>
class Player {

public://引数を書くところ
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textureHandle">テクスチャハンドル</param>
	void Initialize(Model* model, ViewProjection* viewProjection,const Vector3&position);//void Initialize(Model* model, ViewProjection* viewProjection);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

private://関数（メンバ変数）
	// ワールド変換データ
	WorldTransform worldTransform_;

	// モデル
	Model* model_ = nullptr;
	
	//速度
	Vector3 velocity_ = {};
	
	//慣性移動
	static inline const float kAcceleration=0.5;
	
	//速度減衰
	static inline const float kAttenuation = 0.5;

	ViewProjection* viewProjection_ = nullptr;
};
