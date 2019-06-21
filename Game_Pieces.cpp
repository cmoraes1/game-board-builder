// Camilla Moraes - camillamoraes@wustl.edu
// Lab 2
// Source file with functions the work with game pieces. File includes functions that convert an enum to a string
// and convert a string to an enum.

#include "stdafx.h"
#include "Header.h"
#include "Functions1.h"
#include "Game_Pieces.h"
#include "game_board.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

// takes in parameter of enumerated piece color type and returns all lowercase C++ string corresponding to value
string get_piece_color(Color col) 
{
	//convert enum to string using get_enum_name function 
	string(fcnPtr) = get_enum_name(col);
	string enum_string = fcnPtr; 

	//convert string chars to all lowercase 
	fcnPtr = convert_chars_lowercase(enum_string);
	string lowercase_enum = fcnPtr; 

	return lowercase_enum;

}

// converts enum name to string -- got idea to use map from stackoverflow: https://stackoverflow.com/questions/11714325/how-to-get-enum-item-name-from-its-value
string get_enum_name(Color c) 
{

	//create a map that maps enum name to string value
	map<int, string> color_map;
	color_map[0] = "red";
	color_map[1] = "black";
	color_map[2] = "white";
	color_map[3] = "blue";
	color_map[4] = "invalidcolor";
	color_map[5] = "nocolor";

	return color_map[c];
}

//take a C++ style string and return element of enumerated type corresponding to string
Color string_to_enum(string s) {

	//convert string to enum value

	convert_chars_lowercase(s);

	//return enum type that corresponds to string that was passed in
	if (s == "red") 
	{
		return red; 
	}
	if (s == "black")
	{
		return black;
	}
	if (s == "blue")
	{
		return blue;
	}
	if (s == "white") 
	{
		return white; 
	}
	if (s == "nocolor" || s == " " || s == "no color" || s == "none") 
	{
		return nocolor;
	}
	
	return invalidcolor;

}

