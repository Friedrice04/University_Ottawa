/*myFile3.cpp : Ex3 a2 CSI2372A*/

#include <iostream>
using namespace std;

int** triangleInf(int n)
{
	int** pascal = new int*[n];

	for (int i = 0; i < n; ++i) {
		pascal[i] = new int[i + 1];  //Allocate i+1 elements for each row

		pascal[i][0] = 1;  //The first element of each row is 1
		pascal[i][i] = 1;  //The diagonal element of each row is 1

		//Fill in the values using Pascal's triangle rule
		for (int j = 1; j < i; j++) {
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];

		}
	}

	return pascal;
}

int main() {
	int** tab;
	const int size = 10;
	tab = triangleInf(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}