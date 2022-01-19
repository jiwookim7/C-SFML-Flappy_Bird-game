#include "pipeTest.hpp"


bool testPipe::pipeTest() {
	sf::Texture test;
	Pipe testing(test);
	//This is checking if the sprite functions with the Pipe class work by checking if it doesn't load, 
	//if it doesn't then it returns false and true if it does
	if (!testing.loadFromFile("flappyBirdPipe.png")) {
		return false;
	}
	return true;
}