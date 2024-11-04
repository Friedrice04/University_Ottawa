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
    for (int i = 0; i < 52; i++) {

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
    Card k = set[number];
}
