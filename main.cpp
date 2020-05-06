#include "Menu.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int main()
{
    sf::RenderWindow window(sf::VideoMode(480, 320), "Snake", sf::Style::Titlebar | sf::Style::Close);
    Menu text;
    Game snake;
    sf::Clock clock;
    sf::Event event;
    float timer = 0;
    float delay = 0.1;
    text.gamestate=false;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!text.gamestate)
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
                                    text.gamestate = true;
                                    break;
                                case 1:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
            }
            window.clear();
            text.Menu_display(window);
            window.display();
        }
        if (text.gamestate)
        {
            window.clear();
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            if (timer > delay)
            {
                timer = 0;
                snake.Snake();
            }
            snake.Turn();
            snake.Game_display(window);
            snake.Update(window);
            window.display();
            if (snake.gameover)
            {
                window.clear();
                snake.SavePoints();
                snake.wnd(window);
                window.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(5000));
                window.close();
            }
        }
    }
    return 0;
}


