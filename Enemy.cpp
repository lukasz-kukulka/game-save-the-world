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


Enemy::Enemy(sf::Texture *texture, sf::Vector2u windowSize, int HPRandom = 3)
    {
        this->HPMax = HPRandom;
        this->HP = this->HPMax;
        this->shape.setTexture(*texture);
        this->lvl3 = 0;
        this->windows = (int)(windowSize.y);


        this->radian=0.0175;
        this->moveShapeX = -1.0;
        this->moveShapeY = 1.0;

        this->shape.setScale(0.2f, 0.2f);
        this->shape.setPosition(windowSize.x, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height - 35)+35);
        this->enemyHPBar.setPosition(shape.getPosition().x, shape.getPosition().y-2);
        this->enemyHPBarback.setPosition(shape.getPosition().x, shape.getPosition().y-2);

        this->moveShapeXbegin = shape.getPosition().x;
        this->moveShapeYbegin = shape.getPosition().y;

        this->enemyHPBar.setSize(sf::Vector2f(this->shape.getGlobalBounds().width, 3));
        this->enemyHPBar.setFillColor(sf::Color::Red);

        this->enemyHPBarback.setSize(sf::Vector2f(this->shape.getGlobalBounds().width, 3));
        this->enemyHPBarback.setFillColor(sf::Color::Black);
        this->enemyHPBarback.setOutlineThickness(1);
        this->enemyHPBarback.setOutlineColor(sf::Color(50,50,50));
    }
Enemy::~Enemy()
{
}
void Enemy::level1Enemy()
    {
        enemyHPBar.move(moveShapeX, moveShapeY-1);
        enemyHPBarback.move(moveShapeX, moveShapeY-1);
        shape.move(moveShapeX, moveShapeY-1);
    }
void Enemy::level2Enemy()
    {
        if(shape.getPosition().y<=0 || shape.getPosition().y>windows-shape.getGlobalBounds().width)
            moveShapeY = moveShapeY*(-1);
        direction = rand()% 300;
        if(direction == 50)
            moveShapeY = moveShapeY*(-1);

        enemyHPBar.move(moveShapeX*5.0, moveShapeY);
        enemyHPBarback.move(moveShapeX*5.0, moveShapeY);
        shape.move(moveShapeX*5.0, moveShapeY);
        //std::cout<<" ______________ "<<moveShapeX<<std::endl;
    }
void Enemy::level3Enemy()
    {
        const float M_PI = 3.1415;
        if(moveShapeYbegin >= windows-shape.getGlobalBounds().height-100)
        {
            //shape.setPosition(shape.getPosition().x, shape.getPosition().y-10);
            moveShapeYbegin=shape.getGlobalBounds().height-101;
        }
        else if(moveShapeYbegin <= shape.getGlobalBounds().height+100)
        {
            //shape.setPosition(shape.getPosition().x, shape.getPosition().y+10);
            moveShapeYbegin=shape.getGlobalBounds().height+101;
        }
        else
        {
            moveShapeX = moveShapeXbegin + sin (radian * M_PI *2) *100;
            moveShapeY = moveShapeYbegin + cos (radian * M_PI *2) *100;
            shape.setPosition(moveShapeX, moveShapeY);
            enemyHPBar.setPosition(moveShapeX, moveShapeY);
            enemyHPBarback.setPosition(moveShapeX, moveShapeY);
            moveShapeXbegin--;
            radian= radian+0.0035;

        }

    }
