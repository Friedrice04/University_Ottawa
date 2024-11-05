#include <cstdlib>
#include <ctime>

class CardsSet {
public:
    CardsSet() : number(0) {}
    void novSet();
    void shuffle();
    int numCards() { return number; }
    Card take();
    void put(Card k);
    Card lookIn(int no);
    void empty() { number = 0; }
private:
    Card set[52];
    int number;
};

void CardsSet::novSet() {
    int color = 0;
    for(int i = 0; i < 52; i++) {
        switch(color) {
            case 0:
                set[i] = Card(club, i%13);
            case 1:
                set[i] = Card(diamond, i%13);
            case 2:
                set[i] = Card(heart, i%13);
            case 3:
                set[i] = Card(spade, i%13);
        }
        color++;
    }
}

void CardsSet::shuffle() {
    for(int j=0; j < 2; j++) {
        for (Card & i : set) {
            int r = rand() % 52;
            swap(i, set[r]);
        }
    }
}

Card CardsSet::take() {
    // int r = rand() % number;
    // Card c = set[r];
    // for(int i = r; i < number; i++) {
    //     set[i] = set[i+1];
    // }
    number--;
    return set[number-1];;

}

void CardsSet::put(Card k) {
    set[number] = k;
    number++;
}

Card CardsSet::lookIn(int no) {
    if (no > number || no < 1) {cout << "Invalid card number" << endl; exit(1);}
    return set[number-no];
}

