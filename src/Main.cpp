#include "Headers.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Event.hpp>

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE         = "SFML";
const unsigned int WINDOW_FPS    = 60;
const bool WINDOW_VSYNC_ON       = false;

int main()
{
    // Initialising SFML Window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(WINDOW_FPS);
    window.setVerticalSyncEnabled(WINDOW_VSYNC_ON);

    // Creating a simple shape
    sf::RectangleShape shape(sf::Vector2f(100.f, 40.f));
    shape.setFillColor(sf::Color::Red);

    // Main Loop
    while (window.isOpen())
    {
        // Event Polling
        sf::Event sfEvent;
        while (window.pollEvent(sfEvent))
        {
            switch (sfEvent.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
