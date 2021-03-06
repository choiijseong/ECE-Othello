#ifndef _ECE_OTHELLO_GAME_HPP_
	#define _ECE_OTHELLO_GAME_HPP_

	#include <iostream>
	#include <string>
	#include <vector>
	#include "board/gameboard.hpp"
	#include "players/player.hpp"
	#include "players/human.hpp"
	#include "board/tree/validmovenode.hpp"
	#include "ui/games/gameui.hpp"
	#include "ui/games/gameallegroui.hpp"
	#include "ui/games/gamecliui.hpp"
	#include "save/savemanager.hpp"

	/**
	 * @namespace Othello
	 * @details Espace de nommage du jeu.
	 */
	namespace Othello {
		/**
		 * @class Game
		 * @brief Classe de Jeu
		 * @details Classe initiatrice de jeu. Elle gère directement tous ses aspects, les appels à l'interface, le passage des joueurs, etc... Il suffit d'appeler le constructeur en fournissant les paramètres nécessaires. Le constructeur quitte dès que la partie est terminée.
		 */
		class Game {
			private:
				Othello::Board::GameBoard* m_board; //game board
				std::vector<Othello::Players::Player*> m_players; //players
				std::vector<Othello::Players::Player*>::iterator m_currentPlayer; //an iterator of players (we need to know who's turn it is)
				Othello::UI::Game* m_ui;
				bool won = false;

				/**
				 * @brief Effectueur de coup de joueur
				 * @details Effectue le coup d'un joueur. Passe au joueur suivant à la fin.
				 */
				void playerTurn();

				/**
				 * @brief Effectueur de victoire
				 * @details Calcul quel joueur a gagné, déclenche l'écran de victoire.
				 */
				void victory();

				/**
				 * @brief Vérificateur de victoire
				 * @details Vérifie si un joueur a gagné. Arrête le jeu en conséquence.
				 */
				void verifyVictory();

				/**
				 * @brief Préparateur d'objet joueur
				 * @details Prépare les objets joueur avant le début du jeu, fournit les élements nécessaires à leur fonctionnement.
				 */
				void preparePlayers();

				/**
				 * @brief Choisisseur de joueur
				 * @details Choisie le joueur qui débute selon les règles.
				 */
				void findStartingPlayer();

				/**
				 * @brief Choisisseur de joueur
				 * @details Règle le joueur qui débute selon la demande.
				 */
				void findStartingPlayer( unsigned char currentPlayer );

			public:
				/**
				 * @brief Constructeur par chargement de partie
				 * @details Reprend partie du jeu depuis une sauvegarde.
				 */
				Game( Othello::UI::Audio::FMOD& fmod, bool allegro );

				/**
				 * @brief Constructeur normal
				 * @details Initie une nouvelle partie du jeu avec les joueurs apportés.
				 * @param players Ensemble de pointeur vers joueurs, préalablement créé.
				 */
				Game( std::vector<Othello::Players::Player*>& players, Othello::UI::Audio::FMOD& fmod, bool allegro );
		};

		extern Othello::UI::Game* currentUI; /*!< Pointeur vers l'instance d'UI actuelle */
	}

#endif
