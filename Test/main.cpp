#include <iostream>

using namespace std;

int main()
{
    int tab[][2] = { 1,2,3,4,5,6 };
    cout << (*(tab+2))[1] << endl;
    return 0;
}
