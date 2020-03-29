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
#include "Player.h"


#endif

class Enemy
{
public:
    sf::Sprite shape;

    sf::RectangleShape enemyHPBar;  //HP ENEMIES
    sf::RectangleShape enemyHPBarback;  //HP ENEMIES

    int HP;
    int HPMax;
    int windows;
    int direction;
    float radian;
    float moveShapeX;
    float moveShapeY;
    float moveShapeXbegin;
    float moveShapeYbegin;
    float circle;
    float lvl3;



    Enemy(sf::Texture *texture, sf::Vector2u windowSize, int HPRandom);
    ~Enemy();

    void level1Enemy();
    void level2Enemy();
    void level3Enemy();
        //int pos = shape.getPosition();
    };
