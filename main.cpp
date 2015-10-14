//
//  main.cpp
//  RouletteWheel

#include <iostream>
#include <ctime>

using namespace std;

// define forward declarations below
int random_number();

// define the struct for data
struct data{
	int location;
	int frequency;
};

int main() {
	// set up a random seed
	srand(time(NULL));
	// declare array of data points
	data arr[35];

	return 0;
}

int random_number(){
	// returns a random number between 0 and 35
	return rand() % 36;
}
