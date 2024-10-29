#include <cstdlib> 
using namespace std;

class SetInt
{
public:
	SetInt() : elem(NULL), size(0) {};
	SetInt(int[], int);
	~SetInt();
	SetInt(const SetInt&);  // copy constructor
	void add(int);
	void remove(int);
	bool contains(int);
	int nbElem();
	int* tabElem();
private:
	int* elem;
	int size;
	bool containsIn(int n, int&);
};

SetInt::SetInt(int a[], int n){
  this -> elem = new int[n];
  this -> size = n;
  for (int i = 0; i < n; i++){
    this -> elem[i] = a[i];
  }
}

SetInt::~SetInt(){
  delete [] elem;
}

SetInt::SetInt(const SetInt& a){
  elem = new int[a.size];
  for (int i = 0; i < a.size; i++){
    this -> elem[i] = a.elem[i];
  }
  this->size = a.size;
}

void SetInt::add(int a){
  for (int i = 0; i < this->size; i++){
    if (this->elem[i] == a){
    	cout << "Element already exists" << endl;
    }
  }
}