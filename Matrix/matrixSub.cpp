#include"Matrix.h"

Matrix :: Matrix() { // init with zero matrix;
	memset(data, 0, sizeof(data));
	a_size = -1;
	b_size = -1;
	det = -1;
}

int Matrix::get_b_size() {
	return b_size;
}

int Matrix::get_a_size() {
	return a_size;
}

void Matrix::print() {
	cout << "the result:" << endl;
	for (int i = 0; i < a_size; i++) {
		for (int j = 0; j < b_size; j++) {
			printf("%3.2f ", data[i][j]);
		}
		cout << endl;
	}
}

istream& operator>>(istream& in, Matrix& A) {
	cout << "enter A like [1 2 3;1 1 1;4 5 6]:" << endl;
	string s;
	getline(std::cin, s);//读取空格
	//cout << s << endl;
	int pos = 0, i =0, j= 0;
	//------将矩阵读取到object中------
	while (s[pos] != '\0') {
		bool flag = true;
		if (s[pos] == '-') {
			flag = false;
			pos++;
		}
		int cnt = 0;
		while (s[pos] && s[pos] <= '9' && s[pos] >= '0')//transform string to int 
			cnt = (cnt * 10 + s[pos++] - '0');
		if (cnt)A.data[i][j++] = flag ? cnt : -cnt; //deal with negative number	
		if (s[pos] == ';') {
			A.b_size = j;
			j = 0;//init j with zero
			i++;
		}
		if (!s[pos])break;
		pos++;
	}
	A.a_size = i+1;//get the size of coulmn
	printf("A.size = (%d, %d)\n", A.get_a_size(), A.get_b_size());
	return in;
}

ostream& operator<<(ostream& out, const Matrix& A) {
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
