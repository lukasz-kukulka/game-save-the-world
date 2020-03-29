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
#include "Winners.h"
#include <algorithm>

#endif


Winners::Winners(sf::Vector2u sizeWindows, sf::Font *font, std::string player_name, std::string date_record, int scores)//
    {
        this->winner = 1;
        this->no_line = 1;
        this->name = player_name;
        this->date = date_record;
        this->sco = scores;
        this->sizeWin = sizeWindows;

        this->shapeA.setFillColor(sf::Color(128, 128, 128, 128));
        this->shapeA.setPosition(sizeWin.x/8, sizeWin.y/2);
        this->shapeA.setSize(sf::Vector2f(sizeWin.x/8*2, 40.0f));
        this->shapeA.setOutlineThickness(1);
        this->shapeA.setOutlineColor(sf::Color::Black);
        this->winnersA.setFont(*font);
        this->winnersA.setCharacterSize(30);
        this->winnersA.setOutlineThickness(1);
        this->winnersA.setOutlineColor(sf::Color(255, 255, 255));
        this->winnersA.setFillColor(sf::Color(255, 255, 255));
        this->winnersA.setPosition(shapeA.getPosition().x + 5, shapeA.getPosition().y + 2);
        this->winnersA.setString("Player_1");

        this->shapeB.setFillColor(shapeA.getFillColor());
        this->shapeB.setPosition(shapeA.getPosition().x + shapeA.getGlobalBounds().width, shapeA.getPosition().y);
        this->shapeB.setSize(sf::Vector2f(shapeA.getSize().x, shapeA.getSize().y));
        this->shapeB.setOutlineThickness(shapeA.getOutlineThickness());
        this->shapeB.setOutlineColor(sf::Color(shapeA.getOutlineColor()));
        this->winnersB.setFont(*font);
        this->winnersB.setCharacterSize(winnersA.getCharacterSize());
        this->winnersB.setFillColor(sf::Color(winnersA.getFillColor()));
        this->winnersB.setString("01.01.2020");
        this->winnersB.setPosition(shapeB.getPosition().x + 5, shapeB.getPosition().y + 5);

        this->score = std::to_string(sco);
        this->shapeC.setFillColor(shapeA.getFillColor());
        this->shapeC.setPosition(shapeB.getPosition().x + shapeB.getGlobalBounds().width, shapeA.getPosition().y);
        this->shapeC.setSize(sf::Vector2f(shapeA.getSize().x, shapeA.getSize().y));
        this->shapeC.setOutlineThickness(shapeA.getOutlineThickness());
        this->shapeC.setOutlineColor(sf::Color(shapeA.getOutlineColor()));
        this->winnersC.setFont(*font);
        this->winnersC.setCharacterSize(winnersA.getCharacterSize());
        this->winnersC.setFillColor(sf::Color(winnersA.getFillColor()));
        this->winnersC.setString("0000000");
        this->winnersC.setPosition(shapeC.getPosition().x + 5, shapeC.getPosition().y + 5);
    }
Winners::~Winners(){}



void Winners::save()
{
    while(score.length()<=7)
        {
            score.insert(0, "0");
        }

    std::fstream filess;
    filess.open("score.txt", std::ios::out | std::ios::app);

    filess<<name<<std::endl;
    filess<<date<<std::endl;
    filess<<score<<std::endl;

    filess.close();
}

void Winners::load(int i)
    {
        std::fstream filess;
        filess.open("score.txt", std::ios::in);
        if(filess.good()==false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }
        readLine = i*3+1;
        while(getline(filess, line))
        {
            if (no_line==readLine) nameTab[i] = line;
            if (no_line==readLine+1) dateTab[i] = line;
            if (no_line==readLine+2) scoreTab[i] = line;
            no_line++;
        }
        filess.close();
        winnersA.setString(nameTab[i]);
        winnersB.setString(dateTab[i]);
        winnersC.setString(scoreTab[i]);
    }

int Winners::check()
{
    int quest = 0;
    std::fstream filess;
    filess.open("score.txt", std::ios::in);
        if(filess.good()==false)
        {
            std::cout<<"File not exist"<<std::endl;
            exit(0);
        }
    while(getline(filess, line))
    {
        quest++;
    }
    filess.close();
    return quest/3;
}

void Winners::sortWinner()
{
    int check =  Winners::check()-1;
    for(int i = 0; i<=check; i++)
        {
        std::fstream filess;
        readLine = i*3+1;
        no_line = 1;
        filess.open("score.txt", std::ios::in);
        if(filess.good()==false)
            {
                std::cout<<"File not exist"<<std::endl;
                exit(0);
            }
        while(getline(filess, line))
        {
            if (no_line==readLine) nameSort[i] = line;
            if (no_line==readLine+1) dateSort[i] = line;
            if (no_line==readLine+2) scoreSort[i] = line;
            no_line++;
        }
        filess.close();
        }
    for(int i = 0; i<=check; i++)
    {
        intTab[i] = std::atoi(scoreSort[i].c_str());
    }

    for(int i = 0; i<=check; i++)
    {

        for(int j = 0; j<check; j++)
        {

            if (intTab[j]<intTab[j+1])
            {
                std::swap(intTab[j], intTab[j+1]);
                std::swap(dateSort[j], dateSort[j+1]);
                std::swap(nameSort[j], nameSort[j+1]);
            }
        }

    }

    std::fstream filess;
    filess.open("score.txt", std::ios::out | std::ios::trunc);
    for(int i = 0; i<=check; i++)
    {
        scoreSort[i] = std::to_string(intTab[i]);
            while(scoreSort[i].length()<=7)
            {
                scoreSort[i].insert(0, "0");
            }
        filess<<nameSort[i]<<std::endl;
        filess<<dateSort[i]<<std::endl;
        filess<<scoreSort[i]<<std::endl;
    }
    filess.close();

}



