// Camilla Moraes - camillamoraes@wustl.edu
// Lab 2
// Source file for a game board. File includes functions that get the dimensions of a game board from an input file, 
// read in game pieces from an input file, and print out the game pieces based on their indices that are constructed
// when reading in the pieces. 

#include "stdafx.h"
#include "Header.h"
#include "Functions1.h"
#include "Game_Pieces.h"
#include "game_board.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//function that reads in the dimensions of a game board (row, col) from an input file stream
int get_board_dimensions(ifstream & in_file, unsigned int & r, unsigned int & c) 
{
	string s; 
	string temp;
	
	if (getline(in_file, s))
	{
		//wrap string variable in an input string stream
		istringstream stream(s);

		//if extraction operator and value of getline() return true - return Success
		if (stream >> r && stream >> c)
		{
			if (r != c)
			{
				cout << "Error with board dimensions. Board must be 1 by 1, 2 by 2, 3 by 3, etc . . ." << endl;
				return BoardDimensionsNotEqual;
			}
			return Success;
		}
		//if getline returns true but either (or both) extraction operators return false
		else
		{
			cout << "Error extracting horizontal or vertical board dimensions" << endl;
			return ErrorExtractingBoardDimensions;
		}
	}
	//if line could not be read from input file stream
	else 
	{
		cout << "Error reading line from input file" << endl;
		return ErrorReadingInputFile;
	}
	
}

//function for reading in game pieces from an input file stream
int get_game_pieces(ifstream & piece_file, vector<Game_Piece> & game_pieces, unsigned int r, unsigned int c)
{
	//r and c are the dimensions of the game board 
	string s;

	string piece_color;
	string piece_name;
	string piece_display;
	unsigned int piece_row;
	unsigned int piece_col;
	
	//while loop to read file line by line
	while(getline(piece_file, s))
	{
		istringstream stream(s);

		//extract 5 values using stream >> operator 
		if (stream >> piece_color &&
			stream >> piece_name &&
			stream >> piece_display &&
			stream >> piece_row &&
			stream >> piece_col) {

			//convert piece color to lowercase chars
			convert_chars_lowercase(piece_color);

			//convert string to enum representing color
			Color(fcnPtr) = string_to_enum(piece_color);
			Color enum_color = fcnPtr;

			//compare piece coordinates with board dimensinos 
			if (piece_row >= r || piece_col >= c)
			{
				//skip line and continue to process subsequent lines 
				continue;
			}
			//check if color is invalid or does not exist
			if (enum_color == invalidcolor || enum_color == nocolor)
			{
				continue;
			}
			
			//calculate index and replace game piece values at index with values extracted from stream 
			int index = c * piece_col + piece_row;
			game_pieces[index].color = enum_color;
			game_pieces[index].piece_name = piece_name;
			game_pieces[index].piece_display = piece_display;

		}
		else
		{
			continue;
		}

	}

	//check if at least one game piece is well formed
	bool formed_piece = false;

	//iterates through vector of game pieces and check if at least one is well formed 
	for (unsigned int i = 0; i < game_pieces.size(); ++i)
	{
		//BUT what if it has a valid color but its coordinates are messed up ****** 
		if (game_pieces[i].color != 5)
		{
			formed_piece = true;
			break;
		}
	}

	if (formed_piece == true)
	{
		return Success;
	}
	else
	{
		cout << "Failed to find any well formed piece definitions." << endl;
		return NoWellFormedPieceDefinitions; 
	}
	
}

//function for printing out game pieces
int print_game_pieces(const vector<Game_Piece> & game_pieces, unsigned int r, unsigned int c)
{
	
	//print layout of game board given by parameters passed into function
	for (int i = c - 1; i >= 0; i--)
	{
		for (unsigned int j = 0; j <= r - 1; j++)
		{
			//print string for displaying the piece at the corresponding index in the vector
			int index = c * i + j;
			cout << game_pieces[index].piece_display;
		}
		cout << endl;
	}

	//check for any errors or edge cases 
	if (game_pieces.size() != r*c)
	{
		cout << "Vector size does not match the game board dimensions" << endl;
		return VectorSizeDoesNotMatchBoardDimensions;
	}
	if (game_pieces.size() == 0)
	{
		cout << "No pieces have been added to your vector" << endl;
	}

	return Success;
}