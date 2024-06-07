#include"MathUtilityforText.h"
#include<cmath>
#include<numbers>


//アフィン変換行列の作成
//Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate)
//{
//	Vector3 dm;
//	dm = scale;
//	dm = rot;
//	
//	// 平行移動
//	/*Matrix4x4 result{1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, translate.x, translate.y, translate.z,
//                 1.0f};*/
//
//	//回転
//	Matrix4x4 RotateMatY = 
//	{ 
//		cosf(rot.y),0,-sinf(rot.y),0,0,1,0,0,
//	  sinf(rot.y),0,cosf(rot.y),0,0,0,0,1
//	};
//
//	//平行移動行列の作成
//	Matrix4x4 TranslatMat = {
//		1,0,0,0,
//		0,1,0,0,
//		0,0,1,0,
//		translate.x,translate.y,translate.z,1
//	};
//
//	// 回転＊平行移動だけをワールド変換行列に
//	Matrix4x4 ansMat = MatrixMultiply(RotateMatY, TranslatMat);
//
//
//	return ansMat;
//
//	//return result;
//}

//Vector3の足し算
Vector3& operator+=(Vector3& lhv, const Vector3& rhv) { 
	lhv.x += rhv.x; 
	lhv.y += rhv.y;
	lhv.z += rhv.z;
	return lhv;
}

//行列の掛け算
//縦横にかけて加算する
Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2)
{

	Matrix4x4 result;

	result.m[0][0] =
		m1.m[0][0] * m2.m[0][0]+ 
		m1.m[0][1] * m2.m[1][0]+
		m1.m[0][2] * m2.m[2][0]+
		m1.m[0][3] * m2.m[3][0];

	result.m[0][1] =
		m1.m[0][0] * m2.m[0][1]+ 
		m1.m[0][1] * m2.m[1][1]+
		m1.m[0][2] * m2.m[2][1]+
		m1.m[0][3] * m2.m[3][1];

	result.m[0][2] =
		m1.m[0][0] * m2.m[0][2]+ 
		m1.m[0][1] * m2.m[1][2]+
		m1.m[0][2] * m2.m[2][2]+
		m1.m[0][3] * m2.m[3][2];

	result.m[0][3] =
		m1.m[0][0] * m2.m[0][3]+ 
		m1.m[0][1] * m2.m[1][3]+
		m1.m[0][2] * m2.m[2][3]+
		m1.m[0][3] * m2.m[3][3];

	result.m[1][0] =
		m1.m[1][0] * m2.m[0][0]+ 
		m1.m[1][1] * m2.m[1][0]+
		m1.m[1][2] * m2.m[2][0]+
		m1.m[1][3] * m2.m[3][0];

	result.m[1][1] =
		m1.m[1][0] * m2.m[0][1]+ 
		m1.m[1][1] * m2.m[1][1]+
		m1.m[1][2] * m2.m[2][1]+
		m1.m[1][3] * m2.m[3][1];

	result.m[1][2] =
		m1.m[1][0] * m2.m[0][2]+ 
		m1.m[1][1] * m2.m[1][2]+
		m1.m[1][2] * m2.m[2][2]+
		m1.m[1][3] * m2.m[3][2];

	result.m[1][3] =
		m1.m[1][0] * m2.m[0][3]+ 
		m1.m[1][1] * m2.m[1][3]+
		m1.m[1][2] * m2.m[2][3]+
		m1.m[1][3] * m2.m[3][3];

	result.m[2][0] =
		m1.m[2][0] * m2.m[0][0]+ 
		m1.m[2][1] * m2.m[1][0]+
		m1.m[2][2] * m2.m[2][0]+
		m1.m[2][3] * m2.m[3][0];

	result.m[2][1] =
		m1.m[2][0] * m2.m[0][1]+ 
		m1.m[2][1] * m2.m[1][1]+
		m1.m[2][2] * m2.m[2][1]+
		m1.m[2][3] * m2.m[3][1];

	result.m[2][2] =
		m1.m[2][0] * m2.m[0][2]+ 
		m1.m[2][1] * m2.m[1][2]+
		m1.m[2][2] * m2.m[2][2]+
		m1.m[2][3] * m2.m[3][2];

	result.m[2][3] =
		m1.m[2][0] * m2.m[0][3]+ 
		m1.m[2][1] * m2.m[1][3]+
		m1.m[2][2] * m2.m[2][3]+
		m1.m[2][3] * m2.m[3][3];

	result.m[3][0] =
		m1.m[3][0] * m2.m[0][0]+ 
		m1.m[3][1] * m2.m[1][0]+
		m1.m[3][2] * m2.m[2][0]+
		m1.m[3][3] * m2.m[3][0];

	result.m[3][1] =
		m1.m[3][0] * m2.m[0][1]+ 
		m1.m[3][1] * m2.m[1][1]+
		m1.m[3][2] * m2.m[2][1]+
		m1.m[3][3] * m2.m[3][1];

	result.m[3][2] =
		m1.m[3][0] * m2.m[0][2]+ 
		m1.m[3][1] * m2.m[1][2]+
		m1.m[3][2] * m2.m[2][2]+
		m1.m[3][3] * m2.m[3][2];

	result.m[3][3] =
		m1.m[3][0] * m2.m[0][3]+ 
		m1.m[3][1] * m2.m[1][3]+
		m1.m[3][2] * m2.m[2][3]+
		m1.m[3][3] * m2.m[3][3];


	return result;

}

Matrix4x4 Multply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 ret = {};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				ret.m[i][j] += m1.m[i][k] * m2.m[k][j];
			}
		}
	}
	return ret;
}
// 1.平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 ret = {};
	ret.m[0][0] = 1.0f;
	ret.m[1][1] = 1.0f;
	ret.m[2][2] = 1.0f;
	ret.m[3][3] = 1.0f;
	ret.m[3][0] = translate.x;
	ret.m[3][1] = translate.y;
	ret.m[3][2] = translate.z;
	return ret;
}
// 2.拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 ret = {};
	ret.m[0][0] = scale.x;
	ret.m[1][1] = scale.y;
	ret.m[2][2] = scale.z;
	ret.m[3][3] = 1.0f;
	return ret;
}

// 1.X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 ret{
	    1.0f, 0.0f, 0.0f, 0.0f, 0.0f, std::cos(radian), std::sin(radian), 0.0f, 0.0f, std::sin(-radian), std::cos(radian), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	};
	return ret;
}
// 2.Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 ret{
	    std::cos(radian), 0.0f, std::sin(-radian), 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, std::sin(radian), 0.0f, std::cos(radian), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	};
	return ret;
}
// 3.Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 ret{
	    std::cos(radian), std::sin(radian), 0.0f, 0.0f, std::sin(-radian), std::cos(radian), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
	};
	return ret;
}




float EaseInOut(float x1, float x2, float t) {
	float easeT = -(std::cosf(std::numbers::pi_v<float> * t) - 1.0f) / 2.0f;
	return Lerp(x1, x2, easeT);
}

float Lerp(float x1, float x2, float t) { return (1.0f - t) * x1 + t * x2; }

Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t) { return Vector3(Lerp(v1.x, v2.y, t), Lerp(v1.y, v2.y, t), Lerp(v1.z, v2.z, t)); }






// 3次元アフィン変換行列
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
	Matrix4x4 rotateXYZMatrix = Multply(rotateXMatrix, Multply(rotateYMatrix, rotateZMatrix));
	Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);

	Matrix4x4 ret = Multply(scaleMatrix, Multply(rotateXYZMatrix, translateMatrix));

	return ret;
}
