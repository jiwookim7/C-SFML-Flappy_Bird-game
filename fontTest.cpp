#include "fontTest.hpp"


bool testFont::testingFont() {
	Font testing;
	//This is testing if the font functions work on it by using a font and checking if it doesn't load it returns false and true otherwise
	if (!testing.loadFromFile("flappyBirdStartFont.ttf")) {
		return false;
	}
	return true;
}