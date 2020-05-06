#ifndef SNAKEONEWINDOW_MENU_H
#define SNAKEONEWINDOW_MENU_H
#include <SFML/Graphics.hpp>

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
    bool gamestate=false;
};

#endif //SNAKEONEWINDOW_MENU_H
