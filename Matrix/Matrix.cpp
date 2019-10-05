#include"Matrix.h"
void prompt() {// print mian menu
	cout << "-------------operation menu---------" << endl
			<< "1.get A_i_j of A" << endl
			<< "2.get the inverse of A" << endl
			<< "3.get the echelon form of A" << endl
			<< "4.get determinat of A" << endl
			<< "5.get the reduced echelon form" << endl
			<< "6.judge the matrix is invarible" << endl
			<< "7.display the matrix" << endl
			<< "8.display the operation menu" << endl
			<< "---------------------------------------" << endl;
	cout <<
		"you can using the number to operator or enter:\n" <<
		" A_i_j \n inv \n ech_form \n det \n re_ech_form \n is_inv \n dis \n menu\n" <<
		"to invoking the operation" << endl;
}
int main() {
	// freopen("")//更改文件输入输出流
	Matrix A, B;
	int x, y;
	cout << "enter the matrix :" << endl;
	cin >> A;
	prompt();//显示菜单
	string choice;
	//-------------操作栏-------------
	while (true) {
		cout << "enter your choice:" ;
		cin >> choice;
		if (choice == "1" || choice == "A_i_j") {//1
			cout << "please the i and j to get A_i_j" << endl;
			cin >> x >> y;
			cout << A.get_A_i_j(x, y) << endl;
		}
		else if (choice == "2" || choice == "inv") {//2
			cout << "A^-1:" << endl;
			cout << A.inverse() << endl;
		}
		else if (choice == "3" || choice == "ech_form") {//3
			A.tri_matrix("display");
		}
		else if (choice == "4" || choice == "det")//4
			cout << "det A = " << A.get_det() << endl;
		else if (choice == "5" || choice == "re_ech_form") {//5
			cout << "the reduced echelon form of A" << endl;
			cout << A.GaussEli() << endl;
		}
		else if (choice == "6" || choice == "is_inv")//6
			if (A.is_invertible()) cout << "invertible " << endl;
			else cout << "not invertilbe" << endl;
		else if (choice == "7" || choice == "dis")//7
			cout << "A = \n" << A << endl;
		else if (choice == "8" || choice == "menu") {//8
			prompt();
		}
	}
	system("pause");
	//exit(0);
}