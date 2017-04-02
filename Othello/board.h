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

    vector<pair<int,int>> find_possible_moves(); // m�thode qui renvoie une paire de coordonn�es.
    void play(pair<int,int> _move,vector<pair<int,int>> possible_moves, bool turn); //re�oit des coordonn�es et ajoute un pion du joueur correspondant � l'endroit voulu ?
    void make_changes(pair<int,int> _move); // fait les changements n�c�ssaires apr�s un coup
};



#endif // BOARD_H_INCLUDED
