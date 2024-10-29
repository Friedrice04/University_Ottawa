/*Ex1a - a3 CSI2372A*/

#include <iostream>
using namespace std;

enum Color { club, diamond, spades, heart };
enum Face { seven, eight, nine, ten, jack, queen, king, ace };



struct Card{
	Color color;
	Face face;
};

int main(){
	Card game[32];
	Color Colors[] = {club, diamond, spades, heart};
	Face Faces[] = {seven, eight, nine, ten, jack, queen, king, ace};
    int cardNum = 0;
	for(Color i : Colors){
          for(Face j : Faces){
            game[cardNum].color = i;
            game[cardNum].face = j;
            cardNum++;
          }
    }
}
