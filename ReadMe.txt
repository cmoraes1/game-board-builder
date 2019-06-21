Camilla Moraes
CSE 332
Lab 2

Write Up:

This lab parses an input file in order to get dimensions to build a game board, read in game pieces which have
a color, a name, and a display, constructs an index for each piece using the given equation width * row + col, 
and prints out the pieces in their correct location based on their index.

Test Files:

Test File #1:
3 3
yellow Xs X 0 0
yellow Xs X 0 2
yellow Xs X 1 1
yellow Xs X 1 2
yellow Xs X 2 2
green Os O 0 1 
green Os O 1 0 
green Os O 2 0 
green Os O 2 2 

Output with this file returns the error that states "Failed to find any well formed piece definitions".
This is because all of the colors are invalid so nothing can be printed on the board. 

Test File #2:
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1
red Xs X 1 2
red Xs X 2 2
3 3
blue Os O 0 1 
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 

Prints out a 3 by 3 board with 4 O's placed on it as well as errors indicating that the program could not extract board
dimensions up until it reaches the line with 3 3 on it. 

Test File #3:
3 3
yellow Xs X 0 0
yellow Xs X 0 2
yellow Xs X 1 1
yellow Xs X 1 2
yellow Xs X 2 2
green Os O 0 1 
green Os O 1 0 
green Os O 2 0 
green Os O 2 2 

Test File #4:
aksjdflkasjdfklja
dlaksjdflasjdf
3
3
3
lkajsdlf

Returns error extracting board dimensions and error reading line from input file. 

Test File #5:
3 5
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1

red Xs X 1 2
red Xs X 2 2
blue O 0 1 
xxxxxxxxxxx
blue Os O 2 0 
blue Os O 2 2 

Test File #6:
3 3
RED Xs X 0 0
REd Xs X 0 2
red Xs X 1 1
red Xs X 1 2
red Xs X 2 2
red Xs X 2 2
red Xs X 2 2
red Os O 0 1

Prints out the game board as it should because I used the function to convert all of the color strings 
to be lowercase. 

Test File #7:
3 3
red Xs X 0 0
red Xs X 0 2
red Xs X 1 7
red Xs X 1 2
red Xs X 2 2
blue Os O 0 1 
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 

Prints out the board correctly because the getline function skips the line with the coordiantes 1 and 7
since it is out of range. 

Test File #8:
3 3
red xx 3 dd ee f
blue Xs 17 x
e e e e e 

Running this file returns an error that no well formed pieces were found. 

Test File #9:
3 3
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1

red Xs X 1 2
red Xs X 2 2
blue Os O 0 1 

asdfasdfasdfasdfasdfasdf
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 

Produces the same output as the tic-tac-toe.txt file. I wrote this test file to make sure the program
was skipped over blank lines and badly formatted lines. 



