// Camilla Moraes - camillamoraes@wustl.edu
// Lab 2
// Header file with function declarations for game board functions. 

#pragma once
#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <fstream>
#include <vector>

int get_board_dimensions(std::ifstream & in_file, unsigned int & r, unsigned int & c);
int get_game_pieces(std::ifstream & piece_file, std::vector<Game_Piece> & game_pieces, unsigned int r, unsigned int c);
int print_game_pieces(const std::vector<Game_Piece> & game_pieces, unsigned int r, unsigned int c);


#endif /* GAME_BOARD_H */ 


