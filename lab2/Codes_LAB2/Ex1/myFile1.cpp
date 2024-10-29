#include <iostream>

using namespace std;

int main() {
    int tab[10];
    int* p;

    for (int i = 0;i < 10;i++) {
        tab[i] = i * i; //defines each index with the value of the index squared
    }
    tab[2] = tab[1];            //defines tab[2] to be equal to tab[1]
    tab[2] = *(tab + 1);        //defines tab[2] to be equal to the value held at the memory location of tab[1]
    *(tab + 2) = tab[1];        //defines the value held at the memory location of tab[2] to be equal to tab[1]
    *(tab + 2) = *(tab + 1);    //defines the value held at the memory location of tab[2] to be equal to the value held at the memory location of tab[1]
    p = &tab[0];                //defines p to be the memory location of tab[0]
    p = tab + 1;                //defines p to be the memory location of tab[1]
    tab[4] = *p;                //defines tab[4] to be the value held at the memory location of p
    cout << 4 << endl           //displays a series of numbers in command line
    << 1 << endl
    << 1 << endl
    << 1 << endl
    << 1 << endl
    << 1 << endl;
}

