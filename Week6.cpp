#include<iostream>

#include<iomanip>

#include<fstream>

using namespace std;

//Defining global constants
#define NUMPLAYERS 10
#define GAMESPLAYED 5


//Function for getting BowlingData
bool getBowlingData(string playName[], int scores[][GAMESPLAYED], int& n) {
	ifstream in("BowlingScores.txt");
	//Creating loop to read BowlingScores.txt and import data to the one-dimensional and two-dimensional array
	if (!in.fail()) {
		while (!in.eof()) {
			in >> playName[n] >> scores[n][0] >> scores[n][1] >> scores[n][2] >> scores[n][3] >> scores[n][4];
			n++;
		}
		return true;
	}
	return false;
}

//Function for calculating the average scores for each player
void getAverageScore(int scores[][GAMESPLAYED], double averageScore[], int n) {
	//Grabs the four scores for each player, adds them up, and divides by 4
	for (int i = 0; i < n; i++) {
		averageScore[i] = 0;

		for (int j = 0; j < GAMESPLAYED; j++) {
			averageScore[i] += scores[i][j];
		}

		averageScore[i] = averageScore[i] / GAMESPLAYED;

	}

}

void prettyPrintResults(string playName[], int scores[][GAMESPLAYED], double averageScore[], int n) {
	//Welcome Letter
	cout << string(55, '*') << endl;
	cout << string(10, '*') << " Justin's Bowling League " << string(20, '*') << endl;
	cout << string(55, '*') << endl;

	//Bowling League Results
	cout << left << setw(10) << "Name" << "Score1\tScore2\tScore3\tScore4\tScore5\tAvg_Score" << endl;
	//loop for printing player name
	for (int i = 0; i < n; i++) {
		cout << left << setw(10) << playName[i] << "\t";
		//nested loop for printing scores/averages
		for (int j = 0; j < GAMESPLAYED; j++)
			cout << scores[i][j] << "\t";
			cout << averageScore[i] << endl;
	}
}

int main() {
	//defining local arrays
	string playNames[NUMPLAYERS];
	int scores[NUMPLAYERS][GAMESPLAYED];
	double averageScore[NUMPLAYERS];
	//defining local counter
	int n = 0;

	//summoning functions - if getBowlingData is successful, executes the averageScore and prints the results.
	if (getBowlingData(playNames, scores, n)) {

		getAverageScore(scores, averageScore, n);
		prettyPrintResults(playNames, scores, averageScore, n);
	}	
}

