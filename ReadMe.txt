Camilla Moraes
CSE 332
Lab 2

** I was granted an extension to February 22nd by Professor Shidal **

Write Up:
This lab parses an input file in order to get dimensions to build a game board, read in game pieces which have
a color, a name, and a display, constructs an index for each piece using the given equation width * row + col, 
and prints out the pieces in their correct location based on their index.

The way I organized the lab and wrote my functions didn't change from when I started the lab to when I finished.
The instructions gave me a good idea of how to organize my code based on whether it related to the game board or 
the game pieces. 

Errors Encountered:
1. '<': signed/unsigned mismatch warning 
I got this error because I had a for loop that looked like for(int i = 0; i < input_string.length(); ++i). In order
to fix this error, I made int i an unsigned int, which got rid of the signed/unsigned mismatch warning. 

2. Undeclared identifier for enum Color in Functions1.h file. 
I fixed this by adding #include "Game_Pieces.h" to top of Functions1.h so that file would know what Color was.

3. The color enum type in the game piece struct I created in the game_piece.h header file was not being recognized.
I realized this was becuase the enum was written after the struct in the file. To fix this, I changed the ordering
of the code. First I declared the enum and then declared the struct so that the struct knew what the Color enum was. 

4. I struggled to print out the game pieces correctly and was printing it out sideways because of the way my for loops
were constructed. To fix this, I swapped my inner and outter for loops so that I was printing a whole row before moving
onto the next line. 

Feedback:
Overall, I really enjoyed doing this lab. It was definitely more complicated than the first one and I ran into 
more errors, but it was helpful that we were able to use some of our knowledge from Lab 1 in order to build this 
program. The most difficult parts for me were reading in the game pieces and printing out the game board correctly.

Design Choices:
1. I chose not to print any pieces with no color or invalid colors. I made the choice to consider pieces with
invalid colors or no colors as not being well formed pieces. For example, in test file #1, all of the pieces 
are not well formed becuase yellow and green are both invalid colors in my program. 

2. I decided that the horizontal and vertical board dimensions had to be equal in order to make the board in this
game a square. For example, the board must be 3 x 3 or 8 x 8 or 4 x 4, etc. Boards that are 4 x 5 or 6 x 7
(for example) are not allowed. This is because I think that almost every board game follows these rules (chess,
tic tac toe, gomoku). Even games like monopoly are played on square boards. Therefore, this design choice was made
in order to emulate real life game boards and provide some consistency in inputs for game board dimensions.

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

The output when running the lab with this file returns the error that states "Failed to find any well formed piece definitions".
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

This prints out a 3 by 3 board with 4 O's placed on it as well as errors indicating that the program could not extract board
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

This prints out the game board as it should because I used the function to convert all of the color strings 
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

This prints out the board correctly because the getline function skips the line with the coordiantes 1 and 7
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

This produces the same output as the tic-tac-toe.txt file. I wrote this test file to make sure the program
was skipped over blank lines and badly formatted lines. 



