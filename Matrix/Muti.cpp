#include"Matrix.h"

void Matrix :: del_nan() {
	/*c++ will print nan if number is small enough
	the code will define they with zero when they smaller than 1e-5*/
	for (int i = 0; i < a_size; i++)
		for (int j = 0; j < b_size; j++)
			if (abs(data[i][j]) < 1e-5)
				data[i][j] = 0;
}
Matrix Multi(Matrix A, Matrix B) {
	Matrix* C_point = new Matrix();
	try {
		if (A.b_size != B.a_size)throw 1;
	}
	catch (int ex) {
		cout << "A's conlumn not equal B's row" << endl;
		return *C_point;
	}
	for (int i = 0; i < A.a_size; i++)
		for (int j = 0; j < B.b_size; j++)
			for (int k = 0; k < A.b_size; k++)
				C_point->data[i][j] += A.data[i][k] * B.data[k][j];
	C_point->a_size = A.a_size;
	C_point->b_size = B.b_size;
	return *C_point;
}
Matrix operator*(Matrix A, Matrix B) {
	return Multi(A, B);
}
