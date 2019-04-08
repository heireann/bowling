#pragma once
#include <vector>

class BowlingGame
{
public:
	BowlingGame() : currentRoll(0), rolls(MAX_ROLLS) {};
	~BowlingGame() {};
	void roll(int pins);
	int	getScore();
private:
	const static int MAX_ROLLS = 21;
	int currentRoll;
	std::vector<int> rolls;
	bool isSpare(int, int);
	bool isStrike(int);
};

bool BowlingGame::isSpare (int firstRollNumber, int secondRollNumber) {
	return rolls[firstRollNumber] + rolls[secondRollNumber] == 10;
}

bool BowlingGame::isStrike (int rollNumber) {
	return rolls[rollNumber] == 10;
}

void BowlingGame::roll(int pins) {
	rolls[currentRoll++] = pins;
}

int BowlingGame::getScore() {

	int score = 0;
	int rollNumber = 0;

	for (unsigned int frame = 0; frame < 10; frame++) {
		score += rolls[rollNumber];
		score += rolls[rollNumber+1];
		
		if (isSpare(rollNumber, rollNumber+1)) {
			score += rolls[rollNumber+2];
			rollNumber += 2;
		}
		else if (isStrike(rollNumber)){
			score += rolls[rollNumber+2];
			rollNumber += 1;
		}
		else {
			rollNumber+= 2;
		}
		 
	}
	return score;
}

