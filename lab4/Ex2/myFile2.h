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
    if(this->size == 0 ) {
        this->elem = new int[this->size]{a}; //creates array if none exists
        this->size++;
        return;
    }
    for (int i = 0; i < this->size; i++){
        if (this->elem[i] == a){        // Checks if element is already in the array
            cout << "Element already exists" << endl;
            return;
        }
    }
    this -> elem[this->size] = a; // adds element to the array if not already present
    size++;
}

void SetInt::remove(int a){
  for (int i = 0; i < this->size; i++){
      if (this->elem[i] == a) {     // finds element in the array
            for (int j = i; j < this->size - 1; j++) {
                this->elem[j] = this->elem[j + 1];  // overwrites element and shifts each element to prevent empty space
            }
            this->size--;
            if (this -> size == 0){
                delete[] this->elem; // if array is empty, deletes array
            }
            return;
      }
  }
}

bool SetInt::contains(int a) {
    for (int i = 0; i < this->size; i++) {
        if (this->elem[i] == a) {
            return true;
        }
    }
    return false;
}

int SetInt::nbElem() {
    return this->size;
}

int* SetInt::tabElem() {
    return this->elem;
}

bool SetInt::containsIn(int n, int& elem) {
    for (int i = 0; i < this->size; i++) {
        if (this->elem[i] == n) {  // gets position of element if it is present
            elem = i;
            return true;
        }
    }
    return false; // false if not present
}