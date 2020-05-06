//
// Created by ludwi on 29.04.2020.
//

#include <SFML/Graphics.hpp>
#include "game.h"
#include <iostream>

Game::Game()
{
    font.loadFromFile("ariali.ttf");
    if(!font.loadFromFile("ariali.ttf"))
    {
        std::cout<<"error"<<std::endl;
    }

    block.setSize(sf::Vector2f(size,size));
    block.setFillColor(sf::Color::Black);
    block.setOutlineThickness(1);
    block.setOutlineColor(sf::Color::White);

    SnakeBlock.setSize(sf::Vector2f(size,size));
    SnakeBlock.setFillColor(sf::Color::Red);
    SnakeBlock.setOutlineThickness(1);
    SnakeBlock.setOutlineColor(sf::Color::White);

    FruitBlock.setSize(sf::Vector2f(size,size));
    FruitBlock.setFillColor(sf::Color::Green);
    FruitBlock.setOutlineThickness(1);
    FruitBlock.setOutlineColor(sf::Color::White);

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(40);
    text.setString("Gameover");
    text.setPosition(sf::Vector2f(210,80));

    srand(time(NULL));
    fruit.x=rand()%width;
    fruit.y=rand()%height;

}

void Game::Game_display(sf::RenderWindow &w)
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            block.setPosition(i*size,j*size);
            w.draw(block);
        }
    }
}

void Game::Update(sf::RenderWindow &w)
{
    for(int i=0; i<lenght; i++)
    {
        SnakeBlock.setPosition(snake[i].x*size, snake[i].y*size);
        w.draw(SnakeBlock);
    }
    FruitBlock.setPosition(fruit.x*size, fruit.y*size);
    w.draw(FruitBlock);
}

void Game::Turn()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction=1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction=2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        direction=3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        direction=0;
}

void Game::Snake()
{
    for (int i=lenght; i>0; --i)
    {
        snake[i].x=snake[i-1].x;
        snake[i].y=snake[i-1].y;
    }
    if (direction == 0)
        snake[0].y += 1;
    if (direction == 1)
        snake[0].x -= 1;
    if (direction == 2)
        snake[0].x += 1;
    if (direction == 3)
        snake[0].y -= 1;

    if (snake[0].x > width)
        snake[0].x = 0;
    if (snake[0].x < 0)
        snake[0].x = width;
    if (snake[0].y > height)
        snake[0].y = 0;
    if (snake[0].y < 0)
        snake[0].y = height;

    if ((snake[0].x == fruit.x) && (snake[0].y == fruit.y))
    {
        lenght++;
        pt++;
        fruit.x = rand() % width;
        fruit.y = rand() % height;
    }


    for(int i=1; i<lenght; i++)
    {
        if(snake[0].x == snake[i].x && snake[0].y==snake[i].y)
        {
            gameover=true;
        }
    }

    points.setFont(font);
    points.setFillColor(sf::Color::Red);
    points.setCharacterSize(40);
    points.setString("Score: "+std::to_string(pt));
    points.setPosition(sf::Vector2f(210,150));

}

void Game::wnd(sf::RenderWindow &wnd)
{
    wnd.draw(text);
    wnd.draw(points);
}

void Game::SavePoints()
{
    std::fstream plik("../wyniki.txt", std::ios::out | std::ios_base::app);
    if(plik.good()==false)
        std::cout<<"ERROR";
    plik<<pt<<std::endl;
    plik.close();
}

/*void Game::Score()
{
    plik.open("wyniki.txt", std::ios::in);
    while(getline(plik,line))
    {
        switch(nr_linii)
        {
            case 1:
                wynik=atoi(line.c_str());
                break;
        }
        nr_linii=27;
    }
    plik.close();

    score.setFont(font);
    score.setFillColor(sf::Color::Red);
    score.setCharacterSize(20);
    score.setString("Last score: "+ std::to_string(wynik));
    score.setPosition(sf::Vector2f(210,300));

}

void Game::DrawScore(sf::RenderWindow &wnd)
{
        wnd.draw(score);
}*/
