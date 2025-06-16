#include "Game.h"
#include <stdexcept>
#include <cstdlib>

Game::Game()
    : window(sf::VideoMode({ 800u, 600u }), "Banana Catcher"),
    font("assets/ARIAL.ttf"),
    timerText(font, "Time: 0", 24),
    livesText(font, "Lives: 3", 24),
    gameOverText(font, "GAME OVER!", 36)
{
    window.setFramerateLimit(60);

    if (!jungleTexture.loadFromFile("assets/jungle.png") ||
        !playerTexture.loadFromFile("assets/monkey.png") ||
        !bombTexture.loadFromFile("assets/bomb.png") ||
        !bananaTexture.loadFromFile("assets/banana.png")) {
        throw std::runtime_error("Nie udało się załadować tekstur!");
    }

    player = new Player(playerTexture);

    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(sf::Vector2f(10.f, 10.f));

    livesText.setFillColor(sf::Color::Red);
    livesText.setPosition(sf::Vector2f(680.f, 10.f));

    gameOverText.setFillColor(sf::Color::Yellow);
    gameOverText.setPosition(sf::Vector2f(280.f, 250.f));

    gameClock.restart();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (auto event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
    }

    if (!isGameOver)
        player->handleInput();
}

void Game::update() {
    if (isGameOver) {
        if (restartClock.getElapsedTime().asSeconds() > 2.f)
            resetGame();
        return;
    }

    player->update();

    if (bananaSpawnClock.getElapsedTime().asSeconds() > 1.5f) {
        spawnBanana();
        bananaSpawnClock.restart();
    }

    if (bombSpawnClock.getElapsedTime().asSeconds() > 2.5f) {
        spawnBomb();
        bombSpawnClock.restart();
    }

    for (auto& banana : bananas) {
        banana.update();
    }

    for (auto& bomb : bombs) {
        bomb.update();
    }

    checkCollisions();

    int seconds = static_cast<int>(gameClock.getElapsedTime().asSeconds());
    timerText.setString("Time: " + std::to_string(seconds));
    livesText.setString("Lives: " + std::to_string(lives));
}

void Game::render() {
    sf::VertexArray skyGradient(sf::PrimitiveType::TriangleFan, 4);

    sf::Color topColor(100, 180, 255);
    sf::Color bottomColor(173, 216, 230);

    skyGradient[0].position = sf::Vector2f(0, 0);
    skyGradient[0].color = topColor;

    skyGradient[1].position = sf::Vector2f(800, 0);
    skyGradient[1].color = topColor;

    skyGradient[2].position = sf::Vector2f(800, 600);
    skyGradient[2].color = bottomColor;

    skyGradient[3].position = sf::Vector2f(0, 600);
    skyGradient[3].color = bottomColor;

    window.clear();
    window.draw(skyGradient);

    sf::Sprite background(jungleTexture);
    window.draw(background);

    player->draw(window);

    for (auto& banana : bananas)
        banana.draw(window);

    for (auto& bomb : bombs)
        bomb.draw(window);

    window.draw(timerText);
    window.draw(livesText);

    if (isGameOver)
        window.draw(gameOverText);

    window.display();
}

void Game::spawnBanana() {
    float x = static_cast<float>(rand() % 760);
    bananas.emplace_back(sf::Vector2f(x, -20.f), bananaTexture);
}

void Game::spawnBomb() {
    float x = static_cast<float>(rand() % 760);
    bombs.emplace_back(sf::Vector2f(x, -20.f), bombTexture);
}

void Game::checkCollisions() {
    for (auto it = bananas.begin(); it != bananas.end();) {
        if (player->getBounds().findIntersection(it->getBounds())) {
            it = bananas.erase(it);
            score++;
        }
        else if (it->getBounds().position.y > 600.f) {
            it = bananas.erase(it);
            lives--;
            if (lives <= 0) {
                isGameOver = true;
                restartClock.restart();
            }
        }
        else {
            ++it;
        }
    }

    for (auto it = bombs.begin(); it != bombs.end();) {
        if (player->getBounds().findIntersection(it->getBounds())) {
            it = bombs.erase(it);
            lives--;
            if (lives <= 0) {
                isGameOver = true;
                restartClock.restart();
            }
        }
        else if (it->getBounds().position.y > 600.f) {
            it = bombs.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Game::resetGame() {
    score = 0;
    lives = 3;
    bananas.clear();
    bombs.clear();
    gameClock.restart();
    isGameOver = false;
}
