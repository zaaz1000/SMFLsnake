#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu()
{

    font.loadFromFile("../ariali.ttf");
    if(!font.loadFromFile("../ariali.ttf"))
    {
        std::cout<<"error"<<std::endl;
    }
    text[0].setFont (font);
    text[0].setFillColor(sf::Color::Red);
    text[0].setCharacterSize(40);
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f(200,80));

    text[1].setFont (font);
    text[1].setFillColor(sf::Color::White);
    text[1].setCharacterSize(40);
    text[1].setString("Exit");
    text[1].setPosition(sf::Vector2f(200,150));
    if(option==0)
        gamestate=true;
}

void Menu::Menu_display(sf::RenderWindow &window)
{
    for(int i=0; i<2; i++)
    {
        window.draw(text[i]);
    }
}

void Menu::MoveUp()
{
    if(option-1 <=0)
    {
        text[option].setFillColor(sf::Color::White);
        option--;
        text[option].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if(option +1 < 2)
    {
        text[option].setFillColor(sf::Color::White);
        option++;
        text[option].setFillColor(sf::Color::Red);
    }
}

int Menu::select()
{
    return option;
}
