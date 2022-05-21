#include "../Headers/Game.h"

// Initialisers

void Game::initWindow()
{
    unsigned int windowWidth  = 800;
    unsigned int windowHeight = 600;
    std::string windowTitle   = "SFML";
    unsigned int windowFPS    = 60;
    bool windowVSyncOn        = false;

    // Loading Window.ini Config File
    std::ifstream configFile("src/Config/Window.ini");
    if (!configFile.is_open())
    {
        std::cout << "ERROR::GAME::CANT_LOAD_WINDOW_CONFIG\n";
    }
    else
    {
        configFile >> windowTitle;
        configFile >> windowWidth >> windowHeight;
        configFile >> windowFPS >> windowVSyncOn;
        
        configFile.close();
    }
    
    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
    this->window->setFramerateLimit(windowFPS);
    this->window->setVerticalSyncEnabled(windowVSyncOn);
}

void Game::initTextures()
{
    this->textureManager.addTexture("player", "src/Assets/Textures/player.png");
    this->textureManager.addTexture("stone", "src/Assets/Textures/stone.png");
}

void Game::initBlocks()
{
    this->blocks.push_back(Block(
        this->textureManager.getTexture("stone"),
        sf::Vector2f(64.f, 128.f),
        sf::Vector2f(64.f, 64.f)
    ));
}

void Game::initPlayer()
{
    this->player.setTexture(this->textureManager.getTexture("player"));
    this->player.setSpeed(80.f);
}

// Constructor and Destructor

Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initBlocks();
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
}

void Game::updateKeys()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        this->player.move(sf::Vector2f(-1.f, 0.f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        this->player.move(sf::Vector2f(1.f, 0.f));
    }
}

void Game::update()
{
    this->updateSFMLEvents();
    this->updateClocks();
    this->updateKeys();
    this->player.update(this->blocks);
}

// Render Functions

void Game::renderBlocks()
{
    for (Block& block : this->blocks) block.render(*this->window);
}

void Game::renderPlayer()
{
    this->player.render(*this->window);
}

void Game::render()
{
    this->window->clear(sf::Color(40, 40, 40));
    this->renderBlocks();
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
