#include"MathUtilityforText.h"
#include<cmath>
#include<numbers>


//アフィン変換行列の作成
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate)
{
	Vector3 dm;
	dm = scale;
	dm = rot;
	
	// 平行移動
	/*Matrix4x4 result{1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, translate.x, translate.y, translate.z,
                 1.0f};*/

	//回転
	Matrix4x4 RotateMatY = 
	{ 
		cosf(rot.y),0,-sinf(rot.y),0,0,1,0,0,
	  sinf(rot.y),0,cosf(rot.y),0,0,0,0,1
	};

	//平行移動行列の作成
	Matrix4x4 TranslatMat = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translate.x,translate.y,translate.z,1
	};

	// 回転＊平行移動だけをワールド変換行列に
	Matrix4x4 ansMat = MatrixMultiply(RotateMatY, TranslatMat);


	return ansMat;

	//return result;
}

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



// 3次元アフィン変換行列
//Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);
//Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
//	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(rotate.x);
//	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(rotate.y);
//	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(rotate.z);
//	Matrix4x4 rotateXYZMatrix = Multply(rotateXMatrix, Multply(rotateYMatrix, rotateZMatrix));
//	Matrix4x4 scaleMatrix = MakeScaleMatrix(scale);
//	Matrix4x4 translateMatrix = MakeTranslateMatrix(translate);
//
//	Matrix4x4 ret = Multply(scaleMatrix, Multply(rotateXYZMatrix, translateMatrix));
//
//	return ret;
//}
