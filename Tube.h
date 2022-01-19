#include <SFML/graphics.hpp>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <vector>



using namespace std;



class Pipe : public sf::Sprite, public sf::Texture {
public:
	Pipe(const sf::Texture& texture) : sf::Sprite(texture) {

	};
	Pipe()
	{

	}

private:
	float x;
	float y;
};
