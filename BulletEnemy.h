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
#include "Player.h"


#endif

class BulletEnemy
{
public:
    sf::Sprite shape;
    int bulletspawn;
    int withEnemy;

    BulletEnemy(sf::Texture *texture, sf::Vector2f pos, int enemy)
    {
        this->shape.setTexture(*texture);
        this->shape.setScale(0.1f, 0.1f);
        this->shape.setPosition(pos);
        this->withEnemy = enemy;
    }
    ~BulletEnemy(){}
};
