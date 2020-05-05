//
// Created by ludwi on 28.04.2020.
//
#include <SFML/Graphics.hpp>

#ifndef SNAKESFML_MENU_H
#define SNAKESFML_MENU_H

class Menu
{
    int option=0;
    sf::Font font;
    sf::Text text[2];
        public:

    Menu();
    void Menu_display(sf::RenderWindow &window);
    int select();
    void MoveUp();
    void MoveDown();

};

#endif //SNAKESFML_MENU_H
