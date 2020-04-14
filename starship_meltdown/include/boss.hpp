#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"

class Boss{

	private:
		//values
		int speed;
		int dir;

		//Ship
		sf::Texture BigBoss;
		sf::Sprite ship;

		//Health Bar
		sf::RectangleShape HealthBar, Bar;

	public:
		Boss();
		sf::Sprite getShip();
		sf::RectangleShape getBar();
		sf::RectangleShape getHealthBar();
		void movement();
		void setSpeed(int s);
		int getSpeed();
		void setDir(int d);
		int getDir();

};
