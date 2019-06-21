// Camilla Moraes - camillamoraes@wustl.edu
// Lab 2
// Header file with information about game pieces (enum with game piece colors and game piece struct) and functions
// relating to game pieces. 

#pragma once
#ifndef GAME_PIECES_H
#define GAME_PIECES_H

#include <string>

enum Color {
	red,
	black,
	white,
	blue,
	invalidcolor,
	nocolor
};

//declare struct that represents game piece 
struct Game_Piece
{
	Color color;
	std::string piece_name;
	std::string piece_display;
};

//function declarations
Color string_to_enum(std::string s);
std::string get_piece_color(Color col);
std::string get_enum_name(Color c);


#endif /* GAME_PIECES_H */ 
