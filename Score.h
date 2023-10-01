#pragma once

class Score {
private:



public:
	static void saveScores(int scorePlayer1, int scorePlayer2);
	static void loadScores(int& scorePlayer1, int& scorePlayer2);

	static int currentScore1;
	static int currentScore2;

};

