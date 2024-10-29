#include <chrono>
#include <iostream>
#include <iomanip>
#include <math.h>
//
// Created by henry on 05/10/24.
//
using namespace std;

char toHex(int num) {
    if(num == 10) {return 'A';}
    if(num == 11) {return 'B';}
    if(num == 12) {return 'C';}
    if(num == 13) {return 'D';}
    if(num == 14) {return 'E';}
    if(num == 15) {return 'F';}
}

string baseN(int number, int base){
    string result;
    int remainder;
    while(number != 0) {
        remainder = number % base;
        number = floor(static_cast<double>(number) / base);
        if(remainder < 10) {
            result = static_cast<char>(remainder + '0') + result;
        }else {
            result = toHex(remainder) + result;
        }
    }
    if(result.empty()) {
        result = "0";
    }
    return(result);
}

double threePlaces(double number) {
    return floor(number * 1000)/1000;
}

int main(){

    cout << "Size in bytes of a Character: " << sizeof(char) << endl
    << "Size in bytes of an Integer: " << sizeof(int) << endl
    << "Size in bytes of an Float: " << sizeof(float) << endl
    << "Size in bytes of an Double: " << sizeof(double) << endl
    << "Size in bytes of a Short Integer: " << sizeof(short) << endl
    << "Size in bytes of a unsigned Integer: " << sizeof(unsigned int) << endl;

    int integer;
    double real;
    char character;

    cout << endl << "Enter an Integer: ";
    cin >> integer;

    cout<< endl
    << "Number in Decimal: " << integer << endl
    << "Number in Octal: " << baseN(integer, 8) << endl
    << "Number in Hex: " << baseN(integer, 16) << endl
    << endl
    << "Number in base 10: " << baseN(integer, 10) << endl
    << "Number in base 8: " << baseN(integer, 8) << endl
    << "Number in base 16: " << baseN(integer, 16) << endl;

    cout << endl << "Enter an Real Number: ";
    cin >> real;

    cout << "Number: " << threePlaces(real) << endl
    << endl;

    cout << endl << "Enter a character: ";
    cin >> character;
    cout << character << endl
    << static_cast<unsigned int>(character) << endl;

}
#include "myfile1.h"
