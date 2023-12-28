#include <SFML/Graphics.hpp>
#include <iostream>

class SnakeGame {
public:
    SnakeGame() : window(sf::VideoMode(800, 600), "Snake Game"), deltaTime(0.1f) {
        window.setFramerateLimit(10); // Limit frames to make movement consistent

        // Initialize snake
        snake.setSize(sf::Vector2f(20, 20));
        snake.setFillColor(sf::Color::Green);
        snake.setPosition(400, 300);
        snakeVelocity = sf::Vector2f(20, 0); // Initial movement to the right

        // Initialize food
        spawnFood();
    }

    void run() {
        while (window.isOpen()) {
            handleInput();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    sf::Clock clock;
    float deltaTime;

    sf::RectangleShape snake;
    sf::Vector2f snakeVelocity;
    std::vector<sf::RectangleShape> food;

    void handleInput() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snakeVelocity.y == 0) {
                snakeVelocity = sf::Vector2f(0, -20);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snakeVelocity.y == 0) {
                snakeVelocity = sf::Vector2f(0, 20);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snakeVelocity.x == 0) {
                snakeVelocity = sf::Vector2f(-20, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snakeVelocity.x == 0) {
                snakeVelocity = sf::Vector2f(20, 0);
            }
        }
    }

    void update() {
        sf::Time elapsed = clock.restart();
        deltaTime = elapsed.asSeconds();

        snake.move(snakeVelocity * deltaTime);

        // Check collision with food
        for (size_t i = 0; i < food.size(); ++i) {
            if (snake.getGlobalBounds().intersects(food[i].getGlobalBounds())) {
                food.erase(food.begin() + i);
                spawnFood();

                // Increase snake size
                sf::RectangleShape tail;
                tail.setSize(sf::Vector2f(20, 20));
                tail.setFillColor(sf::Color::Green);
                tail.setPosition(snake.getPosition());
                snake.setSize(sf::Vector2f(snake.getSize().x + 20, snake.getSize().y));
                food.push_back(tail);
            }
        }

        // Check collision with self
        if (checkCollision()) {
            std::cout << "Game Over!\n";
            window.close();
        }
    }

    void render() {
        window.clear();

        // Draw snake
        window.draw(snake);

        // Draw food
        for (const auto& f : food) {
            window.draw(f);
        }

        window.display();
    }

    void spawnFood() {
        sf::RectangleShape newFood;
        newFood.setSize(sf::Vector2f(20, 20));
        newFood.setFillColor(sf::Color::Red);

        // Randomly position food
        float x = static_cast<float>(rand() % (window.getSize().x / 20) * 20);
        float y = static_cast<float>(rand() % (window.getSize().y / 20) * 20);

        newFood.setPosition(x, y);

        food.push_back(newFood);
    }

    bool checkCollision() {
        // Check collision with window borders
        if (snake.getPosition().x < 0 || snake.getPosition().x >= window.getSize().x ||
            snake.getPosition().y < 0 || snake.getPosition().y >= window.getSize().y) {
            return true;
        }

        // Check collision with itself
        for (const auto& f : food) {
            if (snake.getGlobalBounds().intersects(f.getGlobalBounds())) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    SnakeGame game;
    game.run();

    return 0;
}
