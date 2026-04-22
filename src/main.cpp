#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "SFML2 Rotated Rectangle");

    // Create the rectangle shape
    sf::RectangleShape rectangle(sf::Vector2f(150.f, 50.f));
    rectangle.setFillColor(sf::Color::Green);

    // Set the origin to the center of the rectangle
    // This ensures it rotates around its center rather than the top-left corner
    rectangle.setOrigin(75.f, 50.f);

    // Position and Rotate
    rectangle.setPosition(200.f, 250.f);
    rectangle.setRotation(20.f); // Degrees clockwise

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw the rectangle
        window.draw(rectangle);

        window.display();
    }

    return 0;
}
