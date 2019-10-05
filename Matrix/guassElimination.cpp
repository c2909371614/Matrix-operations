#include"Matrix.h"
Matrix Matrix :: tri_matrix(const string& type) {
	Matrix  C = *this;
	Matrix* C_point = &C;
	int mx;//列最大
	for (int i = 0; i < a_size - 1; i++) { //进行a_size次消元, i为i-th row
		mx = i;
		for (int j = i + 1; j < a_size; j++) {
			//找到当前行以下的当前列的绝对值最大数的行下标
			if (abs(C_point->data[j][i]) > abs(C_point->data[mx][i])) { 
				mx = j;
			}
		}
		Matrix temp;
		temp = get_trans(C_point->a_size, i, mx);

		*C_point = temp * (*C_point);//wrap i-th row and mx-th row
		int pivot = i;//pivot position

		//-----find pivot position----
		while (C_point->data[i][pivot] == 0 && pivot <= b_size)
			pivot++;
		
		for (int j = i + 1; j < a_size; j++) {
			
			for (int k = i + 1; k < b_size; k++) //data[i][i]为主元
				/*
					A[i][i]	A[i][k]	A[i][k] ······
					A[j][i]	A[j][k]	A[j][k] ······
					···
				*/
				C_point->data[j][k] -= C_point->data[i][k] * C_point->data[j][i] / C_point->data[i][pivot];//消元
			C_point->data[j][i] = 0;//将主元下面的元素归零
		}
		C_point->del_nan();//del nan

		//------用于求解矩阵---------
		if (type != "no_dis_step")
			cout << i << "th:\n" << *C_point << endl;
	}
	return *C_point;
}
Matrix Matrix::GaussEli() { //从上至下消元
	Matrix* C_point = new Matrix();
	*C_point = tri_matrix();
	/*
		2 4 5 7 8
		0 0 3 5 4
		0 0 0 0 5
	*/
	for (int i = 0; i < a_size; i++) {
		int pivot = i;//get pivot position 主元位置
		while (!C_point->data[i][pivot])
			pivot++;

		double val = C_point->data[i][pivot];//记录当前主元的值
		C_point->data[i][pivot] = 1;//let leading entry equal 1
		/*把主元的列上的元素全部 行变换 为零，主元 行变换 为1*/
		
		for (int j = pivot + 1; j < b_size; j++) { //row-th(行下标)
			
			C_point->data[i][j] = C_point->data[i][j] / val;//主元行变换为1
		}
		for (int j = i - 1; j >= 0; j--) {
		/*
			   ···
				j
			A[j][pivot]	A[j][k] ···
			A[i][pivot]	A[i][k]
		*/
			for (int k = pivot + 1; k < b_size; k++) {
				C_point->data[j][k] -= C_point->data[i][k];
			}
			C_point->data[j][pivot] = 0;
		}
	}
	return *C_point;
}