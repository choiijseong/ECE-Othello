#ifndef _ECE_OTHELLO_PLAYERS_PLAYER_HPP_
	#define _ECE_OTHELLO_PLAYERS_PLAYER_HPP_

	#include <iostream>
	#include <string>
	#include <vector>
	#include "../board/pun.hpp"
	#include "../board/move.hpp"
	#include "../board/gameboard.hpp"

	namespace Othello {
		namespace Players {
		    /// \class Player player.hpp
			class Player {
				protected:
					std::string m_name;
					Othello::Board::Pun::Colors m_color;
					bool m_canPlay = true;
					unsigned char m_punCount = 0;
					Othello::Board::GameBoard* m_board;

				public:
					Player( std::string name, Othello::Board::Pun::Colors color );

					const std::string &getName() const;
					Othello::Board::Pun::Colors getColor() const;
					bool canPlay() const;
					unsigned char getPunCount() const;

					void setCanPlay();
					void setCannotPlay();
					void setPunCount( unsigned char punCount );
					void setBoard( Othello::Board::GameBoard* board );

					virtual Othello::Board::Move getMove() = 0;
			};
		}
	}

#endif
