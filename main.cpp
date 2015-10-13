//
//  main.cpp
//  RouletteWheel

#include <iostream>
#include <ctime>

using namespace std;

// define forward declarations below
int rouletteGen();

int main() {
    // set up a random seed
    srand(time(NULL));
    
    return 0;
}

int rouletteGen(){
    // returns a random number between 0 and 35
    return rand() % 36;
}