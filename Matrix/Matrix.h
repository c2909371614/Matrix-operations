#ifndef MATRIX_H
#define MATRIX_H
#include<bits/stdc++.h>
using namespace std;
const int N = 10;
class Matrix {
private:
	int a_size;
	int b_size;
	double data[N][N];
	double det;//����ʽ���
	void del_nan();
public:
	Matrix();
	int get_b_size();
	int get_a_size();

	friend Matrix Multi(Matrix A, Matrix B);
	friend Matrix operator*(Matrix A, Matrix B);
	friend istream& operator>>(istream& in, Matrix& A);
	friend ostream& operator<<(ostream& out, const Matrix& A);
	
	bool is_invertible();
	Matrix get_A_i_j(int mi, int mj);//get submatrix Aij ��ȡ�Ӿ���Aij��ȥ����A�ĵ�i�к͵�j��
	Matrix inverse();
	Matrix GaussEli();
	Matrix tri_matrix(const string & type = "no_dis_step");
	Matrix get_trans(int, int, int);

	double get_det();//��������ʽ���
	void operator=(Matrix A);
	void print();
};
void prompt();
#endif