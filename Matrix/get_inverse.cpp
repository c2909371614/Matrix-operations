#include"Matrix.h"
Matrix Matrix::inverse() { //
	if (!is_invertible()) {
		cout << "the matrix has not a inverse" << endl;
		return *this;
	}
	double A_det = get_det();//get this det
	Matrix* C_point = new Matrix();
	C_point->a_size = a_size;
	C_point->b_size = b_size;//row and conlum init
	for (int i = 0; i < a_size; i++)
		for (int j = 0; j < b_size; j++) {
			int mi = i + 1, mj = j + 1;
			//get submatrix expanding in mi-th row and mj-th conlum 获取子空间
			Matrix A_i_j = get_A_i_j(mi, mj);
			C_point->data[i][j] = A_i_j.get_det() * pow(-1, mi + mj) / A_det;
		}
	return *C_point;
}
bool Matrix :: is_invertible() {
	//-----judge matrix is invertible---
	//invertiable matrix 's determinant euqal zero 
	if ((int)get_det() == 0) return false;
	else return true;
}