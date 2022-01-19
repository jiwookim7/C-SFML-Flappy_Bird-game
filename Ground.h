#include <SFML/Graphics.hpp>
#include <iostream>

//This is the class that inherites from the rectange shape class
class Ground : public sf::RectangleShape
{
public:

	Ground(const sf::Vector2f& siZe = sf::Vector2f(1200 * 2, 500)) : sf::RectangleShape(siZe) {

	};

	

};