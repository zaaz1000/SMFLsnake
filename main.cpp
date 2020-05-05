#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "game.h"
#include <SFML/Window.hpp>
#include <time.h>
#include <windows.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600,400), "Snake Menu", sf::Style::Titlebar | sf::Style::Close);
    Menu text;
    sf::Event event;
    while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            text.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            text.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (text.select())
                            {
                                case 0:
                                    window.close();
                                    sf::RenderWindow w(sf::VideoMode(480, 320), "Snake Game", sf::Style::Titlebar | sf::Style::Close);
                                    sf::Clock clock;
                                    Game snake;
                                    sf::Event eve;
                                    float timer = 0;
                                    float delay = 0.1;
                                    while (w.isOpen()) {
                                        float time = clock.getElapsedTime().asSeconds();
                                        clock.restart();
                                        timer += time;
                                        if (eve.type == sf::Event::Closed)
                                            w.close();
                                        if (timer > delay) {
                                            timer = 0;
                                            snake.Snake();
                                            snake.Turn();
                                        }
                                        w.clear();
                                        snake.Game_display(w);
                                        snake.Update(w);
                                        if (snake.gameover)
                                        {
                                            w.close();
                                            sf::RenderWindow wnd(sf::VideoMode(600, 400), "Snake",
                                                                 sf::Style::Titlebar | sf::Style::Close);
                                            sf::Event e;
                                            while (wnd.isOpen())
                                            {
                                                if (e.type == sf::Event::Closed)
                                                {
                                                    wnd.close();
                                                }
                                                snake.SavePoints();
                                                //snake.Score();
                                                wnd.clear();
                                                snake.wnd(wnd);
                                                //snake.DrawScore(wnd);
                                                wnd.display();
                                                Sleep(5000);
                                                wnd.close();
                                            }
                                        }
                                        w.display();
                                    }
                            }
                            break;
                        case 1:
                            window.close();
                            break;
                    }
                            if (event.type == sf::Event::Closed)
                                window.close();
            }
            window.clear();
            text.Menu_display(window);
            window.display();
        }
    }
    return 0;
}
