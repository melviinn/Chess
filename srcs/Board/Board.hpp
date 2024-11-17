#include <SFML/Graphics.hpp>
#include <iostream>

#define BOARD_SIZE 8
#define SQUARE_SIZE 80

class Board
{
	public:
		Board();
		~Board();
		void	draw_pieces(sf::RenderWindow &window);
		void	draw_board(sf::RenderWindow &window);
		void	place_pieces(sf::RenderWindow &window, std::string piece, int pos_x, int pos_y);

	private:
		struct s_piece
		{
			std::string name;
			int pos_x;
			int pos_y;
		};
		s_piece	major_pieces[8] = {
			{"rook", 0, 0},
			{"knight", 1, 0},
			{"bishop", 2, 0},
			{"queen", 3, 0},
			{"king", 4, 0},
			{"bishop", 5, 0},
			{"knight", 6, 0},
			{"rook", 7, 0}
		};

		s_piece pawn_pieces[8] = {
			{"pawn", 0, 0},
			{"pawn", 1, 0},
			{"pawn", 2, 0},
			{"pawn", 3, 0},
			{"pawn", 4, 0},
			{"pawn", 5, 0},
			{"pawn", 6, 0},
			{"pawn", 7, 0}
		};
};

