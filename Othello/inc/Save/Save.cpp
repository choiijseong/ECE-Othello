#include "Save.h"

Save::~Save()
{

}

//passer � un type booleen pour v�rifier que la sauvegarde a r�ussi ?
void Save::savePlayer(Othello::Players::Human player_toSave, int slot)
{
    m_playerName = player_toSave.getName();

    std::ofstream players("playerFile.txt");

    players << m_playerName << std::endl ;

    players.close();

}

void Save::saveBoard(Othello::Board::GameBoard gameBoard_toSave, int slot)
{
    std::ofstream board("boardFile.txt");

    board << gameBoard_toSave.getBoard() << std::endl ;

    board.close();

}
