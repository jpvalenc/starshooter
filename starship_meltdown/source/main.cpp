#include "../include/def.hpp"
#include "../include/asteroid.hpp"
#include "../include/background.hpp"
#include "../include/boss.hpp"
#include "../include/player.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

int main(){
	
    Player star_ship;
    Background background;
    std::vector<Asteroid> asteroidField(15);
    Asteroid a1;
    Boss boss;
    
    sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "STARSHIP MELTDOWN");
    window.setFramerateLimit(60);
    sf::Event event;
    sf::Clock clock;
    
    
  
    while(window.isOpen()){
        for(int i = 0; i < asteroidField.size(); i++)
		asteroidField[i].sendAsteroid();

		while(window.pollEvent(event)){
			switch(event.type){
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				clock.restart();
				break;
			}	
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
			window.close();
		}	
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			star_ship.moveUp();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			star_ship.moveLeft();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			star_ship.moveDown();
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			star_ship.moveRight();
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			star_ship.shoot();
		}
		
        window.clear();
	//Game Over Conditions
	for(int i = 0; i < asteroidField.size(); i++)
		if(asteroidField[i].getSprite().getGlobalBounds().intersects(star_ship.getSprite().getGlobalBounds())){
			std::cout << "Game Over" << std::endl;
		}
	background.backMove();	
	boss.movement();
	window.draw(background.getSprite2());
	window.draw(background.getSprite());
        window.draw(star_ship.getSprite());
	for(int i = 0; i < asteroidField.size(); i++)
	        window.draw(asteroidField[i].getSprite());
	star_ship.update(window);	
	window.draw(boss.getShip());
	window.draw(boss.getBar());
	window.draw(boss.getHealthBar());
        window.display();
    }

return 0;


}
