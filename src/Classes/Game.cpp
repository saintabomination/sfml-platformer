#include "../Headers/Game.h"
#include <SFML/Window/Event.hpp>

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE         = "SFML";
const unsigned int WINDOW_FPS    = 60;
const bool WINDOW_VSYNC_ON       = false;

// Initialisers

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    this->window->setFramerateLimit(WINDOW_FPS);
    this->window->setVerticalSyncEnabled(WINDOW_VSYNC_ON);
}

void Game::initTextures()
{
    this->textureManager.addTexture("player", "src/Assets/Textures/player.png");
}

void Game::initPlayer()
{
    this->player.setTexture(this->textureManager.getTexture("player"));
}

// Constructor and Destructor

Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initPlayer();
}

Game::~Game()
{
    delete this->window;
}

// Accessors

const float Game::getDt() const
{
    return this->dtElapsed;
}

// Update Functions

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        switch (this->sfEvent.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;

            default:
                break;
        }
    }
}

void Game::updateClocks()
{
    this->dtElapsed = this->dtClock.restart().asSeconds();
    std::cout << this->dtElapsed << '\n';
}

void Game::update()
{
    this->updateSFMLEvents();
    this->updateClocks();
}

// Render Functions

void Game::renderPlayer()
{
    this->player.render(*this->window);
}

void Game::render()
{
    this->window->clear();
    this->renderPlayer();
    this->window->display();
}

// Functions

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
