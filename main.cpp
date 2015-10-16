//
//  main.cpp
//  RouletteWheel

#include <iostream>
#include <ctime>

using namespace std;

// define the struct for data
struct data{
	int location;
	int frequency;
};

// define forward declarations below
int random_number();
void fillMeUp(data arr[]);
void spinMeRound(data arr[], int spins);
void displayResults(data arr[], int spins);
void testingRoulette();
void theGambler();

int main() {
	// set up a random seed
	srand(time(NULL));
	// launch part 1
	//testingRoulette();
	// launch part 2
	theGambler();
	// stop the program and wait
	cout << "Please press enter to continue..." << endl;
	getchar();

	return 0;
}

void testingRoulette(){
	// declare array of data points
	data spin36[35], spin3600[35], spin36000[35];
	// fill the arrays with default values
	fillMeUp(spin36);
	fillMeUp(spin3600);
	fillMeUp(spin36000);
	// spin the roulette wheel
	spinMeRound(spin36, 36);
	spinMeRound(spin3600, 3600);
	spinMeRound(spin36000, 36000);
	// output the results
	displayResults(spin36, 36);
	displayResults(spin3600, 3600);
	displayResults(spin36000, 36000);
}

void theGambler(){
	// declare array to hold spin values
	// also declare an array to hold bets
	data spin1000[35], bets[35];
	// fill the array with default values
	fillMeUp(spin1000);
	fillMeUp(bets);
	// spin the roulette wheel/fill bets with random bets
	spinMeRound(spin1000, 1000);
	spinMeRound(bets, 1000);
	// process the results
	int bankroll = 1000;
	for (int i = 0; i < 35; i++){
		// find the number of wins
		int maxWins = spin1000[i].frequency,
		totalBets = bets[i].frequency,
		actualWins = totalBets > maxWins ? maxWins : totalBets;
		cout << "Total Bets Made: " << totalBets << " Total Times Number Came Up: " << maxWins << " Total Times He Wins: " << actualWins << endl;
		// process the bank roll
		bankroll -= totalBets; // -$1 for each bet
		bankroll += actualWins * 35; // +$35 for each win
	}
	cout << "After 1000 bets, the gambler has $" << bankroll << " remaining." << endl;
}

int random_number(){
	// returns a random number between 0 and 34
	// only need up to 34 as data.location at 0 is 1
	return rand() % 35;
}

void fillMeUp(data arr[]){
	for (int i = 0; i < 35; i++){
		arr[i].frequency = 0;
		arr[i].location = (i + 1);
	}
}

void spinMeRound(data arr[], int spins){
	for (int i = 0; i < spins; i++){
		int tmp = random_number();
		arr[tmp].frequency++;
	}
}

void displayResults(data arr[], int spins){
	// break a line
	cout << endl;
	// display the results
	for (int i = 0; i < 35; i++){
		cout << arr[i].location << " appeared " << arr[i].frequency << " times in the " << spins << " spin trial" << endl;
	}
}
