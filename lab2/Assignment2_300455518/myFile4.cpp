/*myFile4.cpp : Ex4 a2 CSI2372A*/

#include "myFile4.h"

int main()
{
	int i;
	char *chain[nb_ch];		//array of pointers on char
	char choice;			//variable for the choice entered in menu()

	cout << endl << "Enter the 5 character strings ending with a tab and a line return" << endl ;

	for (i=0;i<nb_ch;i++)
		{
		chain[i]=new char[size_ch];		// memory allocation
		cin.getline(chain[i],size_ch,'\t');	//seizure of the string
		cin.ignore(INT_MAX,'\n');		// ignore line return
		}

	display(chain,nb_ch);					

	while(1)
		{
		choice=menu();
	
		switch(choice)
			{
			case '1':	display(chain,nb_ch);
				break;
			case '2':	replace(chain,nb_ch,size_ch);	
				break;
			case '3':	sort(chain,nb_ch);
				break;
			case '4':	exit(0);
			default:	break;
			}
		}
}




/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice  */
/********************************************************************************/

char menu()
{
	char choice;

	cout << endl << endl << "\t\tMenu" << endl <<endl;
	cout << "1) Strings display." <<endl;
	cout << "2) Replacement of a string by an other one"<<endl;
	cout << "3) Sorting strings"<< endl;
	cout << "4) Exit of the program"<<endl<<endl;
	cout << "Your choice :";
	cin >> choice;

	return(choice);

}


/********************************************************************************/
/*Function display which displays the strings*/
/********************************************************************************/
void display(char* tab[], int const& nbre)
{
	for(int i=0;i<nbre;i++) {
		cout << "String " << i << " is: " << tab[i] <<endl;	//prints each word in tab
	}
}


/********************************************************************************
*
The replace function that replaces one string by another. 
It takes as arguments an array of pointers on the strings "tab", 
the number of elements of this array of pointers "nbre" and 
the maximum size of the strings "size" 
*
********************************************************************************/

void replace(char* tab[], int const& nbre, int const& size) {
	int numero;		//the string to modify

	do{
		cout << endl << "Enter the string number to modify: ";
		cin >> numero;
		if(numero>nbre || numero<0) { cout << "Not a valid string number" << endl; }
	}while(numero>nbre || numero<0); //asks for valid number until recieved

	char* newWord[size];
	cout << endl << "Enter the new word: ";
	cin.getline(newWord[0],size,'\t');	//takes in new word to swap into place
	cin.ignore(INT_MAX,'\n');

	tab[numero] = newWord[0];	//replaces old word with new one
}

/********************************************************************************/
/*Function sort to sort strings */
/********************************************************************************/
void sort(char* tab[], int const& nbre)
{
	for(int i=0;i<nbre;i++) {
		for(int j=i;j<nbre;j++) {
			if(strcmp(tab[i],tab[j]) > 0) {		//identifies if words need to be moved
				char* temp=tab[j];
				//saves word that is overwritten
				for(int k=j; k>i; k--) {	//moves words to make space for word being moved
					tab[k]=tab[k-1];
				}
				tab[i]=temp;
				//places lower valued word in front of others
			}
		}
	}
}

