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
//zmienne
    int ii = 0;
    int menu = 0;
    int score = 0;
    int enemySpawnTimer = 0;
    int timerText = 0;
    int shootTimer = 0;
    int enemiesBulletsTimer = 0;
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 600), "My program");
    window.setFramerateLimit(60);

//FONT TEXT INIT
    sf::Font font, fontMenu, fontWin;
    font.loadFromFile("Fonts/OldGameFatty.ttf");
    fontMenu.loadFromFile("Fonts/RUBBBB__.ttf");
    fontWin.loadFromFile("Fonts/AT_SYS.ttf");

//ENEMY INIT

    std::vector<Enemy> enemies;
    std::vector<Bullet>bullets;
    std::vector<Winners>winner;

//INIT TEXTURE
    sf::Texture playerTex;
    playerTex.loadFromFile("Textures/ship.png");
    sf::Texture shootEnemyTex;
    shootEnemyTex.loadFromFile("Textures/shoote.png");
    sf::Texture enemyTex;
    enemyTex.loadFromFile("Textures/enemy.png");
    sf::Texture enemyTex1;
    enemyTex1.loadFromFile("Textures/enemy1.png");
    sf::Texture enemyTex2;
    enemyTex2.loadFromFile("Textures/enemy2.png");
    sf::Texture bulletTex;
    bulletTex.loadFromFile("Textures/missile.png");
    sf::Texture backin;
    backin.loadFromFile("Textures/back.jpg");
    sf::Texture backgroud;
    backgroud.loadFromFile("Textures/backgroud.jpg");
    sf::Texture playerHP;
    playerHP.loadFromFile("Textures/heart.png");

//INIT BACKGROUD
    sf::Sprite backgroud_Base;
    backgroud_Base.setTexture(backgroud);
    backgroud_Base.setPosition(0.0f, 0.0f);

    sf::Sprite backgroud1;
    backgroud1.setTexture(backin);
    backgroud1.setPosition(0.0f, 0.0f);

    sf::Sprite backgroud2;
    backgroud2.setTexture(backin);
    backgroud2.setPosition(window.getSize().x, 0.0f);

//TOP BAR INIT

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.0f, 5.0f);

    sf::RectangleShape TopBar;
    TopBar.setSize(sf::Vector2f(window.getSize().x+10, 30.0f));
    TopBar.setFillColor(sf::Color::Blue);
    TopBar.setPosition(-2,0);
    TopBar.setOutlineThickness(1);
    TopBar.setOutlineColor(sf::Color::White);

//MENU TEXT INIT
    sf::Text NewGame;
    NewGame.setFont(fontMenu);
    NewGame.setCharacterSize(40);
    NewGame.setFillColor(sf::Color::White);
    NewGame.setPosition(window.getSize().x/2-NewGame.getGlobalBounds().width, window.getSize().y/3*2);
    NewGame.setString("NEW GAME");

    sf::Text highScore;
    highScore.setFont(fontMenu);
    highScore.setCharacterSize(40);
    highScore.setFillColor(sf::Color::White);
    highScore.setPosition(NewGame.getPosition().x, NewGame.getPosition().y + NewGame.getGlobalBounds().height + highScore.getGlobalBounds().height+10);
    highScore.setString("High Score");

    sf::Text Options;
    Options.setFont(fontMenu);
    Options.setCharacterSize(40);
    Options.setFillColor(sf::Color::White);
    Options.setPosition(NewGame.getPosition().x, highScore.getPosition().y + highScore.getGlobalBounds().height + Options.getGlobalBounds().height+10);
    Options.setString("Options");

    sf::Text Credits;
    Credits.setFont(fontMenu);
    Credits.setCharacterSize(40);
    Credits.setFillColor(sf::Color::White);
    Credits.setPosition(NewGame.getPosition().x, Options.getPosition().y + Options.getGlobalBounds().height + Credits.getGlobalBounds().height+10);
    Credits.setString("Credits");

    sf::Text CreditsPage;
    CreditsPage.setFont(fontMenu);
    CreditsPage.setCharacterSize(25);
    CreditsPage.setFillColor(sf::Color::White);
    CreditsPage.setPosition(window.getSize().x/5, window.getSize().y/2);
    CreditsPage.setString("Created by Lukasz Kukulka");

    sf::Text OptionsPage;
    OptionsPage.setFont(fontMenu);
    OptionsPage.setCharacterSize(20);
    OptionsPage.setFillColor(sf::Color::White);
    OptionsPage.setPosition(window.getSize().x/5, window.getSize().y/2);
    OptionsPage.setString("In next update available");

    sf::Text rightButton;
    rightButton.setFont(fontMenu);
    rightButton.setCharacterSize(10);
    rightButton.setFillColor(sf::Color::White);
    rightButton.setPosition(window.getSize().x/5, window.getSize().y/8*7);
    rightButton.setString("Click right mouse button or ESC to back");

    sf::Text welcome;
    welcome.setFont(fontMenu);
    welcome.setCharacterSize(20);
    welcome.setFillColor(sf::Color::White);
    welcome.setPosition(window.getSize().x/6, window.getSize().y/3*2);
    welcome.setString("Welcome to war, what is your name");

    sf::Text winners;
    winners.setFont(fontMenu);
    winners.setCharacterSize(20);
    winners.setFillColor(sf::Color::Green);
    winners.setPosition(window.getSize().x/6, window.getSize().y/3);


//END GAME INIT TEXT
    sf::Text scoreEnd;
    scoreEnd.setFont(fontMenu);
    scoreEnd.setCharacterSize(20);
    scoreEnd.setFillColor(sf::Color::Green);
    scoreEnd.setPosition(window.getSize().x/6, window.getSize().y/3);

    sf::Text GameOver;
    GameOver.setFont(font);
    GameOver.setCharacterSize(30);
    GameOver.setFillColor(sf::Color::Red);
    GameOver.setPosition(100.0f, window.getSize().y/2);
    GameOver.setString("GAME OVER");


//PLAYER NAME ASK TEXT
    sf::String playerInput;
    sf::Text playerText;
    playerText.setFont(fontMenu);
    playerText.setCharacterSize(40);
    playerText.setFillColor(sf::Color::White);
    playerText.setPosition(window.getSize().x/4, window.getSize().y/4*3);

//PLAYER INIT
    Player player(&playerTex);

//INIT SCREEN

    sf::Time second = sf::seconds( 0.1f );
    sf::Clock clock;
    sf::Time elapsed = clock.getElapsedTime();

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(menu==0)
            {
                if(sf::Mouse::getPosition(window).x > NewGame.getPosition().x  && sf::Mouse::getPosition(window).x < NewGame.getPosition().x + NewGame.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > NewGame.getPosition().y  && sf::Mouse::getPosition(window).y < NewGame.getPosition().y + NewGame.getGlobalBounds().height)
                        NewGame.setFillColor(sf::Color::Red);
                else
                    NewGame.setFillColor(sf::Color::White);

                if(sf::Mouse::getPosition(window).x > highScore.getPosition().x  && sf::Mouse::getPosition(window).x < highScore.getPosition().x + highScore.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > highScore.getPosition().y  && sf::Mouse::getPosition(window).y < highScore.getPosition().y + highScore.getGlobalBounds().height)
                        highScore.setFillColor(sf::Color::Red);
                else
                    highScore.setFillColor(sf::Color::White);

                if(sf::Mouse::getPosition(window).x > Options.getPosition().x  && sf::Mouse::getPosition(window).x < Options.getPosition().x + Options.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > Options.getPosition().y  && sf::Mouse::getPosition(window).y < Options.getPosition().y + Options.getGlobalBounds().height)
                        Options.setFillColor(sf::Color::Red);
                else
                    Options.setFillColor(sf::Color::White);

                if(sf::Mouse::getPosition(window).x > Credits.getPosition().x  && sf::Mouse::getPosition(window).x < Credits.getPosition().x + Credits.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > Credits.getPosition().y  && sf::Mouse::getPosition(window).y < Credits.getPosition().y + Credits.getGlobalBounds().height)
                    Credits.setFillColor(sf::Color::Red);
                else
                    Credits.setFillColor(sf::Color::White);




                if(sf::Mouse::getPosition(window).x > NewGame.getPosition().x  && sf::Mouse::getPosition(window).x < NewGame.getPosition().x + NewGame.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > NewGame.getPosition().x  && sf::Mouse::getPosition(window).y < NewGame.getPosition().y + NewGame.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        menu=1;

                if(sf::Mouse::getPosition(window).x > Options.getPosition().x  && sf::Mouse::getPosition(window).x < Options.getPosition().x + Options.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > Options.getPosition().y  && sf::Mouse::getPosition(window).y < Options.getPosition().y + Options.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        menu=2;

                if(sf::Mouse::getPosition(window).x > Credits.getPosition().x  && sf::Mouse::getPosition(window).x < Credits.getPosition().x + Credits.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > Credits.getPosition().y  && sf::Mouse::getPosition(window).y < Credits.getPosition().y + Credits.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        menu=3;

                if(sf::Mouse::getPosition(window).x > highScore.getPosition().x  && sf::Mouse::getPosition(window).x < highScore.getPosition().x + highScore.getGlobalBounds().width &&
                   sf::Mouse::getPosition(window).y > highScore.getPosition().y  && sf::Mouse::getPosition(window).y < highScore.getPosition().y + highScore.getGlobalBounds().height && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        menu=4;
            }

        if(menu==3)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                menu=0;

        }

        if(menu==2)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                menu=0;
        }

        if(menu==1)
        {


                if(timerText<10)
                timerText++;
                if (event.type == sf::Event::TextEntered && timerText>=10 && playerInput.getSize()<8 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    playerInput +=event.text.unicode;
                    playerText.setString(playerInput);
                    timerText = 0;
                    //numberText = playerInput.length();
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && timerText>=10 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    playerInput.erase(playerInput.getSize()-1, 1);
                    playerText.setString(playerInput);
                    timerText = 0;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    welcome.setString("Hello COMANDER " + playerInput + ". Prepare for battle ");
                    welcome.setPosition(window.getSize().x/10, window.getSize().y/3*2);
                    window.draw(backgroud_Base);
                    window.draw(playerText);
                    window.draw(welcome);
                    window.display();
                    clock.restart();

                    while(elapsed.asSeconds()<5)
                    {
                        sf::Time elapsed = clock.getElapsedTime();
                        if(elapsed.asSeconds()>=3.0)
                        {
                            menu=5;
                            break;
                        }

                    }

                }
            //std::cout<<"Za IF "<<elapsed.asSeconds()<<std::endl;

            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                menu=0;
        }
        if(menu==4)
        {
            std::cout<<"TEST";
            while(winner.size()<=5)
                {
                    winner.push_back(Winners(window.getSize(), &fontWin, playerInput, "01.01.2020", score));
                }
            for(size_t i = 1; i < winner.size(); i++)
                {
                    winner[i].shapeA.setPosition(window.getSize().x/8, winner[i-1].shapeA.getPosition().y + winner[i-1].shapeA.getGlobalBounds().height);
                    winner[i].winnersA.setPosition(winner[i].shapeA.getPosition().x + 5, winner[i].shapeA.getPosition().y + 2);
                    winner[i].shapeB.setPosition(winner[i].shapeA.getPosition().x + winner[i].shapeA.getGlobalBounds().width, winner[i].shapeA.getPosition().y);
                    winner[i].winnersB.setPosition(winner[i].shapeB.getPosition().x + 5, winner[i].shapeB.getPosition().y + 5);
                    winner[i].shapeC.setPosition(winner[i].shapeB.getPosition().x + winner[i].shapeB.getGlobalBounds().width, winner[i].shapeA.getPosition().y);
                    winner[i].winnersC.setPosition(winner[i].shapeC.getPosition().x + 5, winner[i].shapeC.getPosition().y + 5);

                }
            for(int i = 0; i < winner.size(); i++)
                {
                    winner[i].load(i);
                    winner[i].sortWinner();

                }


            if(sf::Mouse::isButtonPressed(sf::Mouse::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))

            menu=0;
        }
        if(menu==5)
        {
        if(player.HP>0)
        {
//UPDATE BACKGROUD
        backgroud1.move(-5.0f, 0.0f);
        backgroud2.move(-5.0f, 0.0f);

        if(backgroud1.getPosition().x <= backgroud1.getGlobalBounds().width*(-1))
            backgroud1.setPosition(window.getSize().x, 0.0f);

        if(backgroud2.getPosition().x <= backgroud2.getGlobalBounds().width*(-1))
            backgroud2.setPosition(window.getSize().x, 0.0f);

//UPDATE PLAYER
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            player.shape.move(0.0f, -10.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            player.shape.move(0.0f, 10.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            player.shape.move(10.0f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            player.shape.move(-10.0f, 0.0f);

        if(player.shape.getPosition().x <=  player.shape.getGlobalBounds().width + 5 ) //LEFT
            player.shape.setPosition(0.0f + player.shape.getGlobalBounds().width+5, player.shape.getPosition().y);
        if(player.shape.getPosition().x >= window.getSize().x - 5) //RIGHT
            player.shape.setPosition(window.getSize().x - 5, player.shape.getPosition().y);
        if(player.shape.getPosition().y <= (5 + TopBar.getGlobalBounds().height)) //UP
            player.shape.setPosition(player.shape.getPosition().x, 5 + TopBar.getGlobalBounds().height + 5);
        if(player.shape.getPosition().y >=  window.getSize().y - player.shape.getGlobalBounds().height - 5) //DOWN
            player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height - 5);

        player.HPBar.setPosition(player.shape.getPosition().x - player.shape.getGlobalBounds().width - 1, player.shape.getPosition().y  - 10);
        player.HPBarback.setPosition(player.shape.getPosition().x - player.shape.getGlobalBounds().width - 1, player.shape.getPosition().y - 10);

//UPDATE CONTROLS

        if(shootTimer<=5)
            shootTimer++;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&& shootTimer >= 5 )  //shooting
            {

                bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                shootTimer = 0; //restet timmer
            }
        //std::cout<<playerText::Text();
        for(size_t i = 0; i < bullets.size(); i++)
            {
//MOVE
                bullets[i].singleShoot();

//OUT OF WINDOW BOUNDS
                if(bullets[i].shape.getPosition().x && bullets[i].shape1.getPosition().x && bullets[i].shape2.getPosition().x > window.getSize().x)
                {
                    bullets.erase(bullets.begin() + i);
                    break;
                }


//ENEMY COLISION
                for (size_t k = 0; k < enemies.size(); k++)
                {

                    if(bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds())
                                                                            || bullets[i].shape1.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds())
                                                                                                                                     || bullets[i].shape2.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                    {
                        if(enemies[k].HP <=1)
                        {
                            enemies[k].HP--;;
                            score+= enemies[k].HPMax;
                            enemies.erase(enemies.begin() + k);
                            bullets.erase(bullets.begin() + i);
                            break;
                        }

                        else
                        {
                            enemies[k].HP--; //ENEMY TAKE DAMAGE
                            enemies[k].enemyHPBar.setSize(sf::Vector2f(enemies[k].shape.getGlobalBounds().width/enemies[k].HPMax *enemies[k].HP, 3));
                            bullets.erase(bullets.begin() + i);
                            break;
                        }

                        break;

                    }
                }

            }

//UPDATE ENEMY
        if (enemySpawnTimer < 50)
				enemySpawnTimer++;

//ENEMY SPAWN
        if (enemySpawnTimer >= 50 && enemies.size() < 15)
        {

            int ene = rand() %3 +1;
            if(ene==1)
            {
                enemies.push_back(Enemy(&enemyTex, window.getSize(), ene));
                enemySpawnTimer = 0;
            }
            if(ene==2)
            {
                enemies.push_back(Enemy(&enemyTex1, window.getSize(), ene));
                enemySpawnTimer = 0;
            }

            if(ene==3)
            {
                enemies.push_back(Enemy(&enemyTex2, window.getSize(), ene));
                enemySpawnTimer = 0; //reset timer
            }
        }


        for (size_t i = 0; i < enemies.size(); i++)
			{

                if(enemies[i].HPMax==1)
                enemies[i].level1Enemy();
                if(enemies[i].HPMax==2)
                enemies[i].level2Enemy();
                if(enemies[i].HPMax==3)
                enemies[i].level3Enemy();



				if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
				{
					enemies.erase(enemies.begin() + i);
					enemySpawnTimer=0;
					break;
				}


				if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
				{
				    //bulletsEnemy.erase(bulletsEnemy.begin() + i);
					enemies.erase(enemies.begin() + i);
                    enemySpawnTimer=0;

					player.HP--; // PLAYER TAKE DAMAGE
					player.HPBar.setScale(player.HP/10, player.HPBar.getScale().y);
					break;
                }
			}

//UI UPDATE
        transform(playerInput.begin(), playerInput.end(), playerInput.begin(), toupper);


        scoreText.setString("COMANNDER " + playerInput + " SCORE: " + std::to_string(score));
        scoreEnd.setString("COMANNDER " + playerInput + " YOUR SCORE IS " + std::to_string(score));


        }

//INIT SCORE FILE
        else
        {

            while(ii<1)
            {


            clock.restart();
            ii++;

            while(elapsed.asSeconds()<5)
                {
                sf::Time elapsed = clock.getElapsedTime();
                std::cout<<elapsed.asSeconds()<<std::endl;
                if(elapsed.asSeconds()>=3.0)
                    {
                    menu=0;
                    winner.push_back(Winners(window.getSize(), &fontWin, playerInput, "01.01.2020", score));
                    winner[winner.size()-1].save();
                    break;
                    }

                }
            }
        }

    }
//DRAW
        window.clear();
        if(menu==0) //basic menu
        {
            window.draw(backgroud_Base);
            window.draw(NewGame);
            window.draw(highScore);
            window.draw(Credits);
            window.draw(Options);
            window.display();
        }
        if(menu==1)
        {
            window.draw(backgroud_Base);
            window.draw(playerText);
            window.draw(welcome);
            window.display();
        }
        if(menu==3)
        {
            window.draw(backgroud_Base);
            window.draw(CreditsPage);
            window.display();
        }
        if(menu==4)
        {
            window.draw(backgroud_Base);
            for(size_t i = 0; i < winner.size(); i++)
                {
                    window.draw(winner[i].shapeA);
                    window.draw(winner[i].shapeB);
                    window.draw(winner[i].shapeC);
                    window.draw(winner[i].winnersA);
                    window.draw(winner[i].winnersB);
                    window.draw(winner[i].winnersC);
                }
            window.display();

        }
        if(menu==2)
        {
            window.draw(backgroud_Base);
            window.draw(OptionsPage);
            window.draw(rightButton);
            window.display();
        }
        if(menu==5)
        {
            window.draw(backgroud1);
            window.draw(backgroud2);


//DRAW PLAYER
        window.draw(player.shape);
        window.draw(player.HPBarback);
        window.draw(player.HPBar);
////DRAW BULLETS
        for(size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i].shape);
            window.draw(bullets[i].shape1);
            window.draw(bullets[i].shape2);
        }
//DRAW UI

        window.draw(TopBar);
        window.draw(scoreText);
//DRAW ENEMIES
        for(size_t i = 0; i < enemies.size(); i++)
        {
            window.draw(enemies[i].shape);
            window.draw(enemies[i].enemyHPBarback);
            window.draw(enemies[i].enemyHPBar);
        }

        if(player.HP <= 0)
        {
            window.draw(scoreEnd);
            window.draw(GameOver);


        }


        window.display();
        }



    }
    return 0;
}
