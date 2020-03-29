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


Player::Player(sf::Texture *texture)
    {
        this->HPMax = 10;
        this->HP = this->HPMax;

        this->texture = texture;
        this->shape.setTexture(*texture);
        this->shape.setScale(0.15f, 0.15f);
        this->shape.setRotation(90.0f);
        this->shape.setPosition(shape.getPosition().x+shape.getGlobalBounds().width +5, 300);
        this->shape.setOrigin(0.0f, 0.0f);

        this->HPBar.setSize(sf::Vector2f(shape.getGlobalBounds().width, 3.0f));
        this->HPBar.setFillColor(sf::Color::Red);
        this->HPBarback.setSize(sf::Vector2f(shape.getGlobalBounds().width +1, 3.0f));
        this->HPBarback.setFillColor(sf::Color::Black);
        this->HPBarback.setOutlineThickness(1);
        this->HPBarback.setOutlineColor(sf::Color(50,50,50));
    }

Player::~Player() {}
