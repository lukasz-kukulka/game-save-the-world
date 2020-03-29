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
#include "Bullet.h"

#endif

Bullet::Bullet(sf::Texture *texture, sf::Vector2f pos)
    {
        this->shape.setTexture(*texture);
        this->shape.setScale(0.15f, 0.15f);
        this->shape.setPosition(pos);

        this->shape1.setTexture(*texture);
        this->shape1.setScale(0.15f, 0.15f);
        this->shape1.setPosition(pos);

        this->shape2.setTexture(*texture);
        this->shape2.setScale(0.15f, 0.15f);
        this->shape2.setPosition(pos);
    }

Bullet::~Bullet(){}

void Bullet::singleShoot()
    {
        shape.move(40.0f, 0.0f);
        shape1.setScale(0.0f,0.0f);
        shape1.move(40.0f, 0.0f);
        shape2.setScale(0.0f,0.0f);
        shape2.move(40.0f, 0.0f);
    }
void Bullet::doubleShoot()
    {
        shape.setScale(0.0f,0.0f);
        shape1.setRotation(-10.0f);
        shape1.move(35.0f, -5.0f);
        shape2.setRotation(10.0f);
        shape2.move(35.0f, 5.0f);
    }
void Bullet::tripleShoot()
    {
        shape.move(40.0f, 0.0f);
        shape1.setRotation(-20.0f);
        shape1.move(30.0f, -10.0f);
        shape2.setRotation(20.0f);
        shape2.move(30.0f, 10.0f);
    }
