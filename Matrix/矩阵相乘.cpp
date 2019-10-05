#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
class Matrix {
  private:
	int a_size;
	int b_size;
	double data[N][N];
	double det;//行列式结果
	void del_nan();
  public:
	Matrix();
	int get_b_size();
	int get_a_size();
	friend Matrix Multi(Matrix A, Matrix B);
	friend Matrix operator*(Matrix A, Matrix B);
	friend istream & operator>>(istream &in , Matrix &A);
	friend ostream & operator<<(ostream &out, const Matrix &A);
	bool is_Invertible()const;
	Matrix get_A_i_j(int mi, int mj);//get submatrix Aij 获取子矩阵Aij除去矩阵A的第i行和第j列
	Matrix inverse();
	Matrix GaussEli();
	Matrix tri_matrix();
	Matrix get_trans(int, int, int);
	double get_det();//计算行列式结果
	void operator=(Matrix A);
	void print();
};
Matrix :: Matrix() { // init with zero matrix;
	memset(data, 0, sizeof(data));
}
int Matrix :: get_b_size() {
	return b_size;
}
int Matrix :: get_a_size() {
	return a_size;
}
void Matrix::print() {
	cout << "the result:" << endl;
	for (int i = 0; i < a_size; i++) {
		for (int j = 0; j < b_size; j++) {
			printf("%3.2f ", data[i][j] );
		}
		cout << endl;
	}
}
istream & operator>>(istream &in, Matrix & A) {
	cout << "请输入矩阵的size m n:";
	in >> A.a_size >> A.b_size;
	cout << "输入矩阵信息:" << endl;
	for (int i = 0; i < A.a_size; i++)
		for (int j = 0; j < A.b_size; j++)
			in >> A.data[i][j];
	return in;
}
ostream & operator<<(ostream &out, const Matrix & A) {
	out << "the result:" << endl;
	for (int i = 0; i < A.a_size; i++) {
		for (int j = 0; j < A.b_size; j++)
			out << A.data[i][j] << " ";
		out << endl;
	}
	return out;
}
void Matrix :: operator=(Matrix A) {
	a_size = A.a_size;
	b_size = A.b_size;
	for (int i = 0; i < a_size; i++)
		for (int j = 0; j < b_size; j++)
			data[i][j] = A.data[i][j];
}

void Matrix :: del_nan() {
	/*c++ will print nan if number is small enough
	the code will define they with zero when they smaller than 1e-5*/
	for (int i = 0; i < a_size; i++)
		for (int j = 0; j < b_size; j++)
			if (abs(data[i][j]) < 1e-5)
				data[i][j] = 0;
}
Matrix Multi(Matrix A, Matrix B) {
	Matrix C;
	try {
		if (A.b_size != B.a_size)throw 1;
	} catch (int ex) {
		cout << "A's conlumn not equal B's row" << endl;
		return C;
	}
	for (int i = 0; i < A.a_size; i++)
		for (int j = 0; j < B.b_size; j++)
			for (int k = 0; k < A.b_size; k++)
				C.data[i][j] += A.data[i][k] * B.data[k][j];
	C.a_size = A.a_size;
	C.b_size = B.b_size;
	return C;
}
Matrix operator*(Matrix A, Matrix B) {
	return Multi(A, B);
}
Matrix Matrix :: get_trans(int size, int trans_x = 0, int trans_y = 0) { //获取元素为1的方阵，大小为size, 缺省为size * size的单位矩阵
	Matrix C;
	if (trans_x != trans_y) //once row interchange det = -det
		det = -det;
	C.a_size = C.b_size = size;
	for (int i = 0; i < size; i++)
		if (i == trans_y) C.data[trans_y][trans_x] = 1;
		else if (i == trans_x) C.data[trans_x][trans_y] = 1;
		else C.data[i][i] = 1;
	return C;
}
double Matrix :: get_det() {
	try {
		if (a_size != b_size) throw 1;
	} catch (int ex) {

		cout << "the matrix is not square matrix" << endl;
		return -1;
	}


	det = 1;//init det before tri_matrix
	//because det will be changed in row interchange
	Matrix C = tri_matrix();

	for (int i = 0; i < a_size; i++)
		det *= C.data[i][i];
	return det;
}
Matrix Matrix :: tri_matrix() {
	Matrix C;
	C = *this;
	int mx;//列最大
	for (int i = 0; i < a_size - 1; i++) { //进行a_size次消元, i为i-th row
		mx = i;
		for (int j = i + 1; j < a_size; j++) {
			if (C.data[j][i] > C.data[mx][i]) { //找到当前行以下的当前列的最大数的行下标
				mx = j;
			}
		}
		Matrix temp;
		temp = get_trans(C.a_size, i, mx);

		C =  temp * C;//wrap i-th row and mx-th row
		for (int j = i + 1; j < a_size; j++) {
			for (int k = i + 1; k < b_size; k++) //data[i][i]为主元
				C.data[j][k] -= C.data[i][k] * C.data[j][i] / C.data[i][i];//消元
			C.data[j][i] = 0;//将主元下面的元素归零
		}
		C.del_nan();//del nan
		cout << i << "th:\n" << C << endl;

	}
	
	return C;
}
bool Matrix :: is_Invertible()const {

	return false;
}
Matrix Matrix :: GaussEli() { //从上至下消元
	Matrix C;
	C = tri_matrix();
	for (int i = 0; i < a_size; i++) {
		double val = C.data[i][i];//记录
		C.data[i][i] = 1;//let leading entry equal 1
		for (int j = i + 1; j < b_size; j++) { //row-th(行下标)
			C.data[i][j] = C.data[i][j] / val;
			C.data[j][i] = 0;
		}
	}
	return C;
}
Matrix Matrix :: get_A_i_j(int mi, int mj) { //get submatrix A_i_j of *this
	Matrix C;
	mi--;
	mj--;
	C.a_size = a_size - 1;
	C.b_size = b_size - 1;
	int xi = 0, xj = 0;
	for (int i = 0; i < a_size; i++) {
		xj = 0;//submatrix conlum init with 0
		if (i == mi) continue; //跳过
		for (int j = 0; j < b_size; j++) {
			if (j != mj) { //not mi-th row and not mj-th conlum
				C.data[xi][xj] = data[i][j];
				xj++;//submatrix conlum++
			}
		}
		xi++;//submatrix row++
	}
	return C;
}

Matrix Matrix :: inverse() { //C_j_i but no influence
	double A_det = get_det();//get this det
	Matrix C;
	C.a_size = a_size;
	C.b_size = b_size;//row and conlum init
	for (int i  = 0; i < a_size; i++)
		for (int j = 0; j < b_size; j++) {
			int mi = i + 1, mj = j + 1;
			//get submatrix expanding in mi-th row and mj-th conlum 获取子空间
			Matrix A_i_j = get_A_i_j(mi, mj);
			C.data[i][j] = A_i_j.get_det() * pow(-1, mi + mj) / A_det;
		}
	return C;

}
int main() {
	// freopen("")
	Matrix A, B;
	int x, y;
	while (cin >> A)

		// while (cin >> x >> y)
		// 	cout << A.get_A_i_j(x, y) << endl;
		// cout << A.inverse() << endl;
		cout << A.tri_matrix() << endl;
	//cout << A.get_det() << endl;

	system("pause");
}
