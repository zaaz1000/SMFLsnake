#include <iostream>
#include <string>
#include <fstream>
#ifndef SNAKESFML_GAME_H
#define SNAKESFML_GAME_H

class Game {

    sf::RectangleShape block;
    sf::RectangleShape SnakeBlock;
    sf::RectangleShape FruitBlock;
    sf::Font font;
    sf::Text text, points, score;
    std::fstream plik;
    std::string line;

    int wynik;
    int width = 30;
    int height = 20;
    int size = 16;
    int direction;
    int lenght=1;
    int pt=0;
    int nr_linii;

    struct snake
    {
        int x,y;
    }snake[1000];

    struct Fruit
    {
        int x,y;
    } fruit;

public:
    Game();
    void Snake();
    void Turn();
    void Update(sf::RenderWindow &w);
    void Game_display(sf::RenderWindow &w);
    void wnd(sf::RenderWindow &wnd);
    //void Score();
    //void DrawScore(sf::RenderWindow &wnd);
    void SavePoints();
    bool gameover=false;
};

#endif //SNAKESFML_GAME_H
