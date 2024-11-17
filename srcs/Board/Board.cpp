#include "Board.hpp"

Board::Board()
{
}

Board::~Board()
{
}

void	Board::place_pieces(sf::RenderWindow &window, std::string piece, int pos_x, int pos_y)
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u size = window.getSize();

	float offset_x = (size.x - 1100) / 2.0f;
	float offset_y = (size.y - 640) / 2.0f;

	if (!texture.loadFromFile("/Users/melvin/Desktop/Code/CPP/Chess/srcs/assets/" + piece + ".png"))
	{
		std::cerr << "Error: Could not load texture" << std::endl;
		exit(1);
	}
	sprite.setTexture(texture);
	sprite.setPosition(offset_x + pos_x * SQUARE_SIZE, offset_y + pos_y * SQUARE_SIZE);
	window.draw(sprite);
}

void	Board::draw_pieces(sf::RenderWindow &window)
{
	auto place_piece = [&](const std::string &color, const s_piece &piece, int row_offset)
	{
		std::string piece_name = color + "_" + piece.name;
		place_pieces(window, piece_name, piece.pos_x, piece.pos_y + row_offset);
	};

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		place_piece("black", major_pieces[i], 0);
		place_piece("black", pawn_pieces[i], 1);
		place_piece("white", major_pieces[i], 7);
		place_piece("white", pawn_pieces[i], 6);
	}
}

void	Board::draw_board(sf::RenderWindow &window)
{
	sf::RectangleShape square(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
	sf::Vector2u size = window.getSize();

	float offset_x = (size.x - 1100) / 2.0f;
	float offset_y = (size.y - 640) / 2.0f;

	for (int y = 0; y < BOARD_SIZE; y++)
	{
		for (int x = 0; x < BOARD_SIZE; x++)
		{
			if ((x + y) % 2 == 0)
				square.setFillColor(sf::Color(209, 139, 71));
			else
				square.setFillColor(sf::Color(255, 206, 158));
			square.setPosition(offset_x + x * SQUARE_SIZE, offset_y + y * SQUARE_SIZE);
			window.draw(square);
		}
	}
	draw_pieces(window);
}
