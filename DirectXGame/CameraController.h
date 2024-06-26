#pragma once
#include "ViewProjection.h"
#include"MathUtilityForText.h"
//前方宣言
class Player;

class CameraController {
public:
	//<summary>
	//初期化
	//</summary>
	void Initialize();
	//<summary>
	// 初期化
	//</summary>

	void Update();

	private:
	// ビュープロジェクション
	ViewProjection viewProjection_;

	Player* target_ = nullptr;

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

	//追従対象とカメラの座標の差(オフセット)
	Vector3 targetoffset_ = {0, 0, -15.0f};

		

};
