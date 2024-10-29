/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"

int main()
{
	
	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
	int index;
	cout << "Enter index to place new element: ";
    bool valid;
	do{
          cin >> index;
          if (index > number || index < 1){ // First index is 1
            cout << endl << endl << "Index out of range" << endl << "Enter Valid Index" << endl;
            valid = false;
          }else{
            valid = true;
          }
	}while(!valid);
    char name[capacity];
    int grade;
    cout << "Enter name of new Student: ";
    cin.getline(name, capacity);
    cout << "Enter grade: ";
    cin >> grade;

    Evaluation* newel;
    newel->grade = grade;
    for(char i : name){
      newel->student[i] = i;
	}
	Evaluation* indexer = p;
   	for(int i = 1; i < number; i++){
          indexer = indexer->next;				//gets next element in list until 1 before requested index
   	}
  	newel->next = indexer->next;
   	indexer->next = newel;
    number++;
	return p;
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	int index;
	cout << "Enter index of element to remove: ";
	bool valid;
	do{
		cin >> index;
		if (index > number || index < 1){ // First index is 1
			cout << endl << endl << "Index out of range" << endl << "Enter Valid Index" << endl;
			valid = false;
		}else{
			valid = true;
		}
	}while(!valid);

    Evaluation* indexer = p;

    for(int i = 1; i < number; i++){
      indexer = indexer->next;
    }
    Evaluation* temp = indexer->next;
	indexer->next = temp->next;
    temp->next = nullptr;
    number--;
    return p;
}


/**
*display() Function *
**/
void display(Evaluation* p)
{
	for(Evaluation* i = p; i != nullptr; i = i->next){
		cout << "Student name: " << i->student << endl <<
			"Student grade: " << i->grade << endl << endl;
    }
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	int sum = 0;
	for(Evaluation* i = p; i != nullptr; i = i->next) {
		sum += i->grade;
	}
	const float average = (float)sum / (float)nbre;
	cout << "Average grade: " << average << endl << endl;
	return 1;
}






