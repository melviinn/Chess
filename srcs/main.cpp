#include <iostream>
#include <SFML/Graphics.hpp>

void	place_pieces(sf::RenderWindow &window, std::string piece, int pos_x, int pos_y)
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u size = window.getSize();

	float offset_x = (size.x - 1100) / 2.0f; // 1100 = 80 * 8 + 240
	float offset_y = (size.y - 640) / 2.0f;

	if (!texture.loadFromFile("/Users/melvin/Desktop/Code/CPP/Chess/srcs/assets/" + piece + ".png"))
	{
		std::cerr << "Error: Could not load texture" << std::endl;
		exit(1);
	}
	sprite.setTexture(texture);
	sprite.setPosition(offset_x + pos_x * 80, offset_y + pos_y * 80);
	window.draw(sprite);
}

void	draw_pieces(sf::RenderWindow &window)
{
	struct s_piece
	{
		std::string name;
		int pos_x;
		int pos_y;
	};

	s_piece	major_pieces[] = {
		{"rook", 0, 0},
		{"knight", 1, 0},
		{"bishop", 2, 0},
		{"queen", 3, 0},
		{"king", 4, 0},
		{"bishop", 5, 0},
		{"knight", 6, 0},
		{"rook", 7, 0}
	};

	s_piece pawn_pieces[] = {
		{"pawn", 0, 0},
		{"pawn", 1, 0},
		{"pawn", 2, 0},
		{"pawn", 3, 0},
		{"pawn", 4, 0},
		{"pawn", 5, 0},
		{"pawn", 6, 0},
		{"pawn", 7, 0}
	};

	auto place_piece = [&](const std::string &color, const s_piece &piece, int row_offset)
	{
		std::string piece_name = color + "_" + piece.name;
		place_pieces(window, piece_name, piece.pos_x, piece.pos_y + row_offset);
	};

	for (int i = 0; i < 8; i++)
	{
		place_piece("black", major_pieces[i], 0);
		place_piece("black", pawn_pieces[i], 1);
		place_piece("white", major_pieces[i], 7);
		place_piece("white", pawn_pieces[i], 6);
	}
}

void	draw_board(sf::RenderWindow &window)
{
	sf::RectangleShape rectangle(sf::Vector2f(80, 80));
	sf::Vector2u size = window.getSize();

	float offset_x = (size.x - 1100) / 2.0f; // 1100 = 80 * 8 + 240
	float offset_y = (size.y - 640) / 2.0f; // 640 = 80 * 8

	rectangle.setFillColor(sf::Color::White);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			rectangle.setPosition(offset_x + i * 80, offset_y + j * 80);
			if ((i + j) % 2 == 0)
				rectangle.setFillColor(sf::Color(119, 150, 86));
			else
				rectangle.setFillColor(sf::Color::White);
			window.draw(rectangle);
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 750), "Chess");

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
		draw_board(window);
		draw_pieces(window);
		window.display();
	}
	return 0;
}
