#include "birdTest.hpp"


bool TestBird::birdTest(){
	sf::Texture test;
	Bird testing(test);
	//This is checking if the sprite functions with the Bird class work by checking if it doesn't load, 
	//if it doesn't then it returns false and true if it does
	if (!testing.loadFromFile("flap.png")) {
		return false;
	}
	return true;
}