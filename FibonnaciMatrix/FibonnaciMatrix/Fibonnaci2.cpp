#include<stdio.h>
#include<Windows.h>
typedef unsigned __int64 BLONG;
#include"Fibonnachi.h"

BLONG Dynammic_Fibonnacci(int n) {

	if (n == 0 || n == 1)
		return n;

	BLONG *table = new BLONG[n + 1];
	table[0] = 0;
	table[1] = 1;
	for (int i = 2; i <= n; i++)
		table[i] = table[i - 1] + table[i - 2];

	BLONG result = table[n];
	delete[] table;
	
	return result;
}



void main() {

	BLONG temp = 0;
	temp = Dynammic_Fibonnacci(10);
	printf("%d\n",temp);




	system("pause");
}