#include <SFML/Graphics.hpp>

namespace
{
	constexpr float g_PlayerSpeed{15.f};
	constexpr float g_RotationAngle{10.f};

	sf::RectangleShape rectangle(sf::Vector2f{50.f, 50.f});

	void handleInput()
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			rectangle.move(-g_PlayerSpeed, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			rectangle.move(0.f, g_PlayerSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			rectangle.move(g_PlayerSpeed, 0.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			rectangle.move(0.f, -g_PlayerSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			rectangle.rotate(g_RotationAngle);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			rectangle.rotate(-g_RotationAngle);
		}
	}
} // namespace

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 480), "SFML Demo!", sf::Style::Close);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	sf::Vector2f center{window.getView().getCenter()};

	rectangle.setPosition(center.x, center.y);
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setOutlineColor(sf::Color::Yellow);
	rectangle.setOutlineThickness(10.f);

	const sf::Vector2f rect_size{rectangle.getSize()};
	rectangle.setOrigin(rect_size.x / 2.f, rect_size.y / 2.f);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}

			handleInput();

			window.clear();
			window.draw(rectangle);
			window.display();
		}
	}
}