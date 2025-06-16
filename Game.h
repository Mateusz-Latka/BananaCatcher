#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Banana.h"

class Game {
public:
    Game();
    void run();
    void resetGame();

private:
    void processEvents();
    void update();
    void render();
    void spawnBanana();
    void checkCollisions();
    void spawnBomb();

    sf::RenderWindow window;

    
    sf::Texture jungleTexture;
    sf::Texture playerTexture;
    sf::Texture bananaTexture;

    
    Player* player;
    std::vector<Banana> bananas;
    sf::Clock bananaSpawnClock;

    
    sf::Font font;
    sf::Text timerText;
    sf::Text livesText;
    sf::Text gameOverText;

    
    int lives = 3;
    int score = 0;
    bool isGameOver = false;
    sf::Clock gameClock;
    sf::Clock restartClock;

    sf::Texture bombTexture;
    std::vector<Banana> bombs;
    sf::Clock bombSpawnClock;

};
