/*myFile2.cpp : Ex2 a2 CSI2372A*/

#include "myFile2.h"

int main() {
	int myArray[sizeArray] = { 2,4,88,20,3,55,87,134,2,5 };

	cout << "Displaying the unsorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout <<  endl << endl;
	sort(myArray, sizeArray);
	cout << "Displaying the sorted array :" << endl;
	for (int i = 0; i < sizeArray; i++) {
		cout << myArray[i] << " ";
	}
	cout << endl;
}

void sort(int a[], int size)
{
  for (int i = 0; i < size; i++){
    for (int j = i; j < size; j++){
      if (a[i] > a[j]){			//identify number to be moved
        int temp = a[j];
      	//saving smaller number to place later
        for (int k = j; k > i; k--) {
	        a[k] = a[k-1];
        	//moving each number between the larger and smaller number up one place in the array
        }
        a[i] = temp;
      	//placing smaller number saved earlier before larger one
      }
    }
  }
}