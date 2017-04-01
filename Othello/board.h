#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "othello.h"

using namespace std ;

class Board
{
private :

    vector<vector<Pun>> m_game_board ; //plateau de jeu

public :

    Board();
    ~Board();

    vector<vector<Pun>> getBoard();

    pair<int,int> find_move(); // m�thode qui renvoie une paire de coordonn�es.
    void play(); //re�oit des coordonn�es et ajoute un pion du joueur correspondant � l'endroit voulu ?
    void make_changes(); // fait les changements n�c�ssaires apr�s un coup
};



#endif // BOARD_H_INCLUDED
