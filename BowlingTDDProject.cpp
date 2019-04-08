#include "catch/catch.hpp"
#include "BowlingGame.h"

class SimpleCalculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

void rollManyTimes(BowlingGame& game, int howMany, int number) {
	for (int i = 0; i < howMany; ++i)
	{
		game.roll(number);
	}
}

TEST_CASE("SimpleCalculator_add_test") {
    SimpleCalculator testObj;

    REQUIRE(testObj.add(2, 2) == 4);
    REQUIRE(testObj.add(2, 4) == 6);
}

TEST_CASE("OneRoundWithZeroPinsShouldGiveScoreZero") {
	BowlingGame game;
	rollManyTimes(game, 2, 0);

	REQUIRE(game.getScore() == 0);
}

TEST_CASE("OneRoundWithTwoPinsShouldGiveScoreTwo") {
	BowlingGame game;
	rollManyTimes(game, 2, 1);
	
	REQUIRE(game.getScore() == 2);
}

TEST_CASE("10RoundsWith2PinsEachRoundshouldGiveScore20") {
	BowlingGame game;
	rollManyTimes(game, 10, 2);

	REQUIRE(game.getScore() == 20);
}

TEST_CASE("SpareShouldGiveABonus") {
	BowlingGame game;

	// First frame
	game.roll(6);
	game.roll(4);

	// Second frame
	rollManyTimes(game, 2, 1);

	REQUIRE(game.getScore() == 13);
}

TEST_CASE("StrikeShouldGiveABonus") {
	BowlingGame game;

	// First frame
	game.roll(10);

	// Second frame
	rollManyTimes(game, 2, 1);

	REQUIRE(game.getScore() == 14);
}

TEST_CASE("PerfectGameShouldScore300") {
	BowlingGame game;

	// Second frame
	rollManyTimes(game, 12, 10);

	REQUIRE(game.getScore() == 300);
}