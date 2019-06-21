// Camilla Moraes - camillamoraes@wustl.edu
// Lab 2
// File with functions for lab that aren't specifically related to the game board or game pieces. This source file 
// includes a usage message function to ensure the user is running the program correctly and a function that converts
// all chars in an input string to be lowercase. 

#include "stdafx.h"
#include "Header.h"
#include "Functions1.h"
#include "Game_Pieces.h"
#include <iostream>
using namespace std;

//defines a helpful usage message that tells the user how to correctly run the program
int usage_message(char * programName) 
{
	cout << "usage: " << programName << " <input_file_name>" << endl;
	cout << "Invalid number of arguments" << endl;
	return InvalidNumberOfArguments;
}

//function that converts all chars in an input string to lowercase 
string convert_chars_lowercase(string & input_string) 
{
	//check for empty string
	if (input_string.length() == 0) 
	{
		cout << "input string empty" << endl;
	}

	//converts string to be all lower case (if upper case chars exist)
	for (unsigned int i = 0; i < input_string.length(); ++i) 
	{
		int char_as_int = input_string.at(i);

		//check if character is upper case based on ASCII value
		if (char_as_int >= 65 && char_as_int <= 90) 
		{
			//convert uppercase char to lowercase by adding 32 to its int value 
			int lowercase_val = char_as_int + 32;
			char lowercase_char = lowercase_val;
			input_string.at(i) = lowercase_char; 
		}
	}

	return input_string;

}