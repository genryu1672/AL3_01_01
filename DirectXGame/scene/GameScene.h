#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Player.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <vector>
#include "MapChipField.h"
#include "CameraController.h"
/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数(引数）
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();






	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void GenerateBlocks();

	





private: // メンバ変数（関数）
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// マップチップフィールド
	MapChipField* mapChipField_;



	// ビュープロジェクション生成
	ViewProjection viewProjection_;

	// 3Dモデルの生成
	Model* model_ = nullptr;

	// プレイヤーの生成
	Player* player_ = nullptr;

	// 天球の生成
	Skydome* skydome_ = nullptr;

	// 3Dモデル
	Model* modelSkydome_ = nullptr;

	// プレイヤーモデル
	Model* modelPlayer_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// ブロックのモデルを読み込む
	Model* modelBlock_ = 0;

	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;

	// デバッグカメラの有効
	bool isDebugCameraActive_ = false;

	// デバッグカメラの生成
	DebugCamera* debugCamera_ = nullptr;

	//カメラコントローラー
	CameraController* cameraController_;


	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
