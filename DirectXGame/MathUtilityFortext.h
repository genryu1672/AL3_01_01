#pragma once

#include<math.h>
#include"Matrix4x4.h"
#include"Vector3.h"


Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate);

//代入演算子オーバーロード
//Vector3の足し算
Vector3& operator+=(Vector3& lhs, const Vector3& rhv);


//行列の掛け算
Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2);