#include <iostream>
#include <fstream>
#include "Score.h"

// Static variables must be initialized only once outside the class before usage 
int Score::currentScore1;
int Score::currentScore2;


void Score::saveScores(int scorePlayer1, int scorePlayer2) {

	std::ofstream* file = new std::ofstream;
	file->open("scores.txt");


		if (file->is_open()) {
			if (scorePlayer1 > currentScore1) {
				*file << scorePlayer1 << std::endl;
			}
			else {
				*file << currentScore1 << std::endl;
			}

			if (scorePlayer2 > currentScore2) {
				*file << scorePlayer2 << std::endl;
			}
			else {
				*file << currentScore2 << std::endl;
			}
			file->close();
		}
		else {
			throw std::runtime_error("Failed to open the file to save scores.");
		}
		
delete file;

}

void Score::loadScores(int& scorePlayer1, int& scorePlayer2) {

	std::ifstream* file = new std::ifstream;
	file->open("scores.txt");

		if (file->is_open()) {

			*file >> currentScore1;
			*file >> currentScore2;

			file->close();
		}
		else {
			throw std::runtime_error("Failed to open the file to load scores.");
		}

	delete file;

	scorePlayer1 = currentScore1;
	scorePlayer2 = currentScore2;


}
