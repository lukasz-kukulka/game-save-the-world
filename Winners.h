#ifndef head_I
#define head_I
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <algorithm>

#endif

class Winners
{
public:
    std::string nameTab[1000], dateTab[1000], scoreTab[1000];
    std::string nameSort[1000], dateSort[1000], scoreSort[1000];
    std::string name, date, line, score;
    int no_line, winner, sco, intTab[1000], readLine;
    sf::Text winnersA, winnersB, winnersC;
    sf::RectangleShape shapeA, shapeB, shapeC;
    sf::Vector2u sizeWin;
    sf::Font font;

    Winners(sf::Vector2u, sf::Font *font, std::string, std::string, int);  //Constructor

    ~Winners(); //destructor

    void load(int); // load records from file
    void save();   // save record from file
    void sortWinner(); // load from file, sort to the best score and save in the same file
    int check(); //check how many record is


};
