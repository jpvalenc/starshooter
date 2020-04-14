#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "def.hpp"
#include <vector>

class Bullet{

	private:
		int damage;

		float posX, posY;
		bool isActive;
	public:
		sf::Texture bulletTexture;

		sf::Sprite bulletPlayer, bulletBoss;
		Bullet(float x, float y);
		void setPos(float x, float y);
		sf::Sprite getbulletPlayer(), getbulletBoss();
		void setActive();
		void bulletFired();
		bool GetActiveStatus();
		

};
