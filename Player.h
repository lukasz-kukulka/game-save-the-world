#ifndef head_I
#define head_I
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Bullet.h"
#include "Enemy.h"

#endif

class Player
{
public:
    sf::RectangleShape HPBar;
    sf::RectangleShape HPBarback;

    sf::Sprite shape;
    sf::Texture *texture;

    float HP;
    float HPMax;

    //std::vector<Bullet>bullets;

    Player(sf::Texture *texture);


    ~Player();
};
