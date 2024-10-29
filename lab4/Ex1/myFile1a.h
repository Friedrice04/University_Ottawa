/*myFile1a, Ex1 a4 CSI2372A*/

#include <iostream>
using namespace std;

class Course {
    int num;
    int hours;
public:
    Course(int, int); 	//constructor
    int getNum();
    int getHours();
};

Course::Course(int num, int h) {
    this -> hours = h;
    this -> num = num;
}

int Course::getNum() {
  return this -> num;
}

int Course::getHours() {
  return this -> hours;
}