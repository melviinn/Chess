#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Board/Board.hpp"

#define WIN_WIDTH 1200
#define WIN_HEIGHT 750

int main()
{
	Board board;

	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Chess");
	sf::Color background_color = sf::Color(48, 46, 43);

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}
		window.clear(background_color);
		board.draw_board(window);
		window.display();
	}
	return 0;
}
