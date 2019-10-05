#include"Matrix.h"
Matrix Matrix::get_trans(int size, int trans_x = 0, int trans_y = 0) { //获取元素为1的方阵，大小为size, 缺省为size * size的单位矩阵
	Matrix* C_point = new Matrix();
	if (trans_x != trans_y) //once row interchange det = -det
		det = -det;
	C_point->a_size = C_point->b_size = size;
	for (int i = 0; i < size; i++)
		if (i == trans_y) C_point->data[trans_y][trans_x] = 1;
		else if (i == trans_x) C_point->data[trans_x][trans_y] = 1;
		else C_point->data[i][i] = 1;
	return *C_point;
}
double Matrix::get_det() {
	try {
		if (a_size != b_size) throw 1;
	}
	catch (int ex) {

		cout << "the matrix is not square matrix" << endl;
		return -1;
	}
	det = 1;//init det before tri_matrix
	//because det will be changed in row interchange
	Matrix* C_point = &(tri_matrix());

	for (int i = 0; i < a_size; i++)
		det *= C_point->data[i][i];
	return det;
}
Matrix Matrix::get_A_i_j(int mi, int mj) { //get submatrix A_i_j of *this
	Matrix* C_point = new Matrix();
	mi--;
	mj--;
	C_point->a_size = a_size - 1;
	C_point->b_size = b_size - 1;
	int xi = 0, xj = 0;
	for (int i = 0; i < a_size; i++) {
		xj = 0;//submatrix conlum init with 0
		if (i == mi) continue; //跳过
		for (int j = 0; j < b_size; j++) {
			if (j != mj) { //not mi-th row and not mj-th conlum
				C_point->data[xi][xj] = data[i][j];
				xj++;//submatrix conlum++
			}
		}
		xi++;//submatrix row++
	}
	return *C_point;
}