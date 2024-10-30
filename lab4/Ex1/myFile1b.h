/*myFile1b.h, Ex1 a4 CSI2372A*/


#include <iostream>
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	Student(int, int); 	//constructor
	~Student(); 		//destructor
	double average();
	int totalHours();
	bool addCourse(Course*, int);
};

Student::Student(int numID, int maxCourses) {
	this->numID = numID;
	this->maxCourses = maxCourses;
	this->List_grades = new int[maxCourses];
	this->List_courses = new Course*[maxCourses];
}

Student::~Student() {
  delete[] this -> List_grades;
  delete[] this -> List_courses;

}

double Student::average() { // Adds all grades of each course of a student and divides by the nubmer of courses
  double sum = 0;
  for (int i = 0; i < this -> nbCourses; i++) {
    sum += this -> List_grades[i];
  }
  return  sum / nbCourses;
}

int Student::totalHours(){ //sums hours from each course for a student and retuns the total
  int sum = 0;
  for (int i = 0; i < this -> nbCourses; i++) {
    sum += this -> List_courses[i] -> getHours();
  }
  return sum;
}

bool Student::addCourse(Course *course, int grade) {
  	if (this -> nbCourses >= this -> maxCourses) { cout << "Max number of courses reached" << endl; return false;}
    this -> List_courses[this -> nbCourses] = course;
    this -> List_grades[this -> nbCourses] = grade;
    this -> nbCourses++;
    return true;
}