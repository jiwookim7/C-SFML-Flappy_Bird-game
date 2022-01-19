#include "backroundTest.hpp"

bool testBackround::backroundTest() {
	sf::Texture test;
	Backround testing(test);
	//This is checking if the sprite functions with the Backround class work by checking if it doesn't load, 
	//if it doesn't then it returns false and true if it does
	if (!testing.loadFromFile("flappyBirdBackround.png")) {
		return false;
	}

	return true;
}