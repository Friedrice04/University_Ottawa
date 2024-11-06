#include <iostream>
using namespace std;
#include <cassert> //for assert()

enum color { club, diamond, heart, spade };

class Card {
public:
    Card(color c = club, int v = 1);
    int value() { return val; }
    void write();
private:
    color col;
    int val;
    char* getColor(color c);
};

/*Constructor*/
Card::Card(color c, int v) {
    assert(v >= 1 && v <= 13); //we use a standard function void assert (int expression)
    //which indicates an error message if the expression is false.
    col = c;
    val = v;
}

void Card::write() {
    char* colr = getColor(col);
    switch(val) {
        default:
            cout << value() << " of " << colr << endl;
        case 1:
            cout << "Ace of " << colr << endl;
        case 11:
            cout << "Jack of " << colr << endl;
        case 12:
            cout << "Queen of " << colr << endl;
        case 13:
            cout << "King of " << colr << endl;
    }
}

char* Card::getColor(color c) {
    switch (c) {
        case club:
            char car[] = "club";
            return car[0]*;
        case diamond:
            return "diamond";
        case heart:
            return "heart";
        case spade:
            return "spade";
    }
}
