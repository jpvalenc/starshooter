#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include "bullet.hpp"
#include "def.hpp"

class Player{
    private:
        //Player's x and y coordinates
        int x, y;

        //Player's lives
        int player_lives;

        //The player's ship health
        int ship_health;

        //the player's score
        int score;

        //The player's starting position
        sf::Vector2f ship_position;

        //Player's body
        sf::Sprite spriteStarship;

        //Player's skin
        sf::Texture textureStarship;

	std::vector<Bullet*> bVect;
	Bullet *bPtr;

    public:
        Player();
	~Player();
        sf::Sprite getSprite();
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
	void stop();
	
	void shoot();
	void update(sf::RenderWindow &window);

};
