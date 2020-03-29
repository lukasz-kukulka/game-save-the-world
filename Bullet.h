#ifndef head_I
#define head_I
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "Enemy.h"
#include "Player.h"

#endif


class Bullet
{
public:
    sf::Sprite shape;
    sf::Sprite shape1;
    sf::Sprite shape2;


    Bullet(sf::Texture *texture, sf::Vector2f pos);

    ~Bullet();
    void singleShoot();
    void doubleShoot();
    void tripleShoot();

};
