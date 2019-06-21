// Camilla Moraes - camillamoraes@wustl.edu 
// Lab 2
// Source file with main function of lab. The main function makes sure the user enters the correct number of command
// line arguments, gets the dimensions of the game board by opening and reading an input file, creates empty game
// board pieces, calls the function to read in game pieces, and eventually prints the pieces if possible. 

#include "stdafx.h"
#include "Header.h"
#include "Functions1.h"
#include "Game_Pieces.h"
#include "game_board.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{

	//make sure number of command line arguments is 1
	if (argc != NumArguments) {
		usage_message(argv[ProgramName]);
	}

	//construct and open an input file stream using the argument passed to the program -- argv[1]
	ifstream input_file;
	input_file.open(argv[InputFile]);

	unsigned int hor;
	unsigned int vert;

	if (input_file.is_open())
	{
		while (get_board_dimensions(input_file, hor, vert) == 4 && !input_file.eof())
		{
			continue;
		}
	}
	else
	{
		cout << "File could not be opened. Please try again." << endl;
		return UnableToOpenFile;
	}

	vector<Game_Piece> pieces;

	unsigned int count = 0;
	while (count < hor*vert)
	{
		//push back game piece representing empty square on board
		Game_Piece piece;
		piece.color = nocolor;
		piece.piece_display = " ";
		piece.piece_name = " ";
		pieces.push_back(piece);
		++count;
	}

	//call function that reads game pieces and pass input file, game piece vector, and board dimensions 
	if (get_game_pieces(input_file, pieces, hor, vert) == 0)
	{
		//print out game pieces 
		print_game_pieces(pieces, hor, vert);
		return Success; 
	}
	else
	{
		return ErrorGettingGamePieces;
	}

}

