#pragma once
#include "MathUtilityForText.h"
#include "ViewProjection.h"
// 前方宣言
class Player;

class CameraController {
public:
	//<summary>
	// 初期化
	//</summary>
	void Initialize();
	//<summary>
	// 初期化
	//</summary>

	void Update();

	// 対応するGetterを作成
	const ViewProjection& GetViewProjection() const { return viewProjection_; }

	void SetTarget(Player* target) { target_ = target; }

	void Reset();

private:
	// ビュープロジェクション
	ViewProjection viewProjection_;

	Player* target_ = nullptr;

	// 追従対象とカメラの座標の差(オフセット)
	Vector3 targetoffset_ = {0, 0, -15.0f};
};
