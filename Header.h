// Camilla Moraes - camillamoraes@wustl.edu
// Lab 2
// Header file with enumeration with error messages and array indicies relevant to the program.

#pragma once
#ifndef HEADER_H
#define HEADER_H

//success and failure values 
enum ErrorMessage {
	Success,
	InputStringEmpty,
	UnableToOpenFile,
	InvalidNumberOfArguments,
	ErrorExtractingBoardDimensions,
	ErrorReadingInputFile,
	ErrorExtractingValues,
	NoWellFormedPieceDefinitions,
	VectorSizeDoesNotMatchBoardDimensions,
	ErrorGettingGamePieces,
	BoardDimensionsNotEqual
};

//array indices relevant to program 
enum Info {
	ProgramName,
	InputFile,
	NumArguments
};

#endif /* HEADER_H */
