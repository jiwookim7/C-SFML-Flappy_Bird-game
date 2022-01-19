#include "groundTest.hpp"

bool testGround::testingGround() {
	Ground testing;
	//I set the ground to red just to check if the rectangle functions worked on it and to test out it makes something
	testing.setFillColor(sf::Color::Red);
	if (testing.getFillColor() == sf::Color::Red) {
		return true;
	}
	return false;
}