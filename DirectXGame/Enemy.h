#pragma once
#include"WorldTransform.h"
#include"Model.h"
//敵
class Enemy {

	public://引数を書くところ
	
	/// <summary>
	/// 初期化
	/// </summary>
	//初期化
	void Initialize(Model* model, ViewProjection* viewProjection, const Vector3& position);
	   
	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();


	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	private:

	// ワールド変換データ
	WorldTransform worldTransform_;

	 // 敵モデル
	Enemy* enemy_ = nullptr;

	//ビュープロジェクションのポインタ
	ViewProjection* viewProjection_ = nullptr;



};
