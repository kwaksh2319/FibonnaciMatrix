#include<stdio.h>
#include<Windows.h>

typedef unsigned __int64 BLONG;
#include"Fi"
struct Matrix {

	BLONG Data[2][2];

};

Matrix Multiply(Matrix a, Matrix b) {

	Matrix r;

	r.Data[0][0]= a.Data[0][0]*b.Data[0][0]+a.Data[0][1]*b.Data[1][0];
	r.Data[0][1] = a.Data[0][0] * b.Data[1][0] + a.Data[0][1] * b.Data[1][1];
	r.Data[1][0] = a.Data[1][0] * b.Data[0][0] + a.Data[1][1] * b.Data[1][0];
	r.Data[1][1] = a.Data[1][0] * b.Data[1][0] + a.Data[1][1] + b.Data[1][1];

	return r;
}
Matrix Power(Matrix m, int n) {
	if (n > 1) {

		m = Power(m, n / 2);

		m = Multiply(m, m);
		
		if (n & 1) {
			Matrix b;
			b.Data[0][0] = 1; b.Data[0][1] = 1;
			b.Data[1][0] = 1; b.Data[1][1] = 0;
			m = Multiply(m, b);
		}
	}

	return m;

}
BLONG Fibonacci(int n) {


	Matrix m;
	m.Data[0][0] = 1; m.Data[0][1] = 1;
	m.Data[1][0] = 1; m.Data[1][1] = 0;

	m = Power(m, n);
	return m.Data[0][1];

}
void main() {

	BLONG temp = 0;
	temp = Fibonacci(10);
	printf("%lu\n", temp);
	printf("\n");
	//¹Ýº¹¹®
	int left = 1, right = 1;
	temp = 0;
	for (int i = 3; i <= 10; i++) {

		temp = left + right;
		left = right;
		right = temp;
	}
	printf("%lu\n", temp);
	
	
	
	system("pause");





}