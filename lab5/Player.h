#include <algorithm>

class Player {
public:
    Player(CardsSet& cardPacket, bool isComputer) : packet(cardPacket), computer
    (isComputer) {}
    int play();
private:
    CardsSet inHand;
    CardsSet& packet;
    const bool computer;
    int countPoints();

    Card takeCard();
    void showPoints();
    const int bigAce = 13;
};

int Player::play() {

    char ans[3];
    bool cont = false;

    if(computer) {
        while(countPoints() < 18) {
            takeCard();
        }
        return countPoints();
    }
    do{
        Card card = takeCard();
        cout << "You got: ";
        card.write();
        cout << endl;
        showPoints();
        if(countPoints() > 21) {
            //cout << "You went bust!" << endl;
            break;
        }
        if(countPoints() == 21) {
            //cout << "You went Win!" << endl;
            break;
            }
        cout << "Draw another card?  " << "(y/n)" << endl;
        cin >> ans;
        cont = ans == "y";
    }while(cont);
    return countPoints();
}

int Player::countPoints() {
    int count = 0;
    for(int i=1; i <= inHand.numCards(); i++) {
        count += inHand.lookIn(i).value();
    }
    if(count + bigAce > 21) return count;
    return count+bigAce;
}

Card Player::takeCard() {
    Card c = packet.take();
    inHand.put(c);
    return c;
}

void Player::showPoints() {
    int aceCount = countPoints()+bigAce;
    if(aceCount > 21) cout << "You now have " << aceCount << " points" << endl;
    else cout << "You now have " << countPoints() << " points" << endl;
}