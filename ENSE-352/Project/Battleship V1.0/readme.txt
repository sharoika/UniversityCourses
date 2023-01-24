----------------------------------------------------------------------------------------------------
------------------------------------------BattleShips V1.0------------------------------------------
-----------------------------------------By MAKSIM SHAROIKA-----------------------------------------
----------------------------------------------------------------------------------------------------

This document provides all the information required to play BattleShips V1.0; the bottom of this
document contains a lookup table for the codes that the game may show you.

----------------------------------------------------------------------------------------------------

The attached file are:
	1. Battleship/ 			-> This is the actual game application that is to be run on 
					   the board.
	2. HardwareDocument.pdf 	-> This is a document the explains the required hardware and 
					   how to set it up.
	3. ExampleGameGrid.pdf	  	-> This a test document that shows the best practices to show 
					   to keep track of the game and a lookup of the codes.
	4.readme.txt			-> Current document with important information such as 
					   how to setup, play, and win the game.
	5.BattleShipOperation.mp4 	-> Simple video file to showcase the operation of the game.

----------------------------------------------------------------------------------------------------

ADDITIONAL FEATURES:
1. Error Validation for grid inputs, make sure the input is within the grid.
2. Grid error validation against all ships being places, making sure the given grid fits them all. 
3. Using a 7-segment display to the outputs of the game instead of LEDS.
4. Using a green on-board LED to help visualize to the user that the game is running. 

----------------------------------------------------------------------------------------------------

(a) 	This is a game for a NUCLEO-F103RB running with a ARM Cortex-M3 processor.
	It is a form of battleships, designed for targeting ships - it can be given
	to a player to try and find all the ships or played against another plater with
	a similar setup. The program says input in the form or a ROW and COLUMN in HEX 
	and then return either a miss, hit, sunk, or sunk all condition. The purpose of the
	game is to sink all the ships as fast as you can. In addition the ships cannot be 
	adjacent to one another, they need to be at least one square apart.

----------------------------------------------------------------------------------------------------

(b)	To play this game first you should become familiar with the terms:
	(E -> Enter, 0 -> Grid, F -> Fail, H -> Hit, C -> Miss)
	These are only the simple terms but they are combined to give information and request it.
	Next will come the explanation of steps to the game (instructions flash in twos):

	The blue button along with the switches are used to request and confirm user input.

----------------------------------------------------------------------------------------------------

1. EO (Enter Grid) 	-> 	This will prompt the user to enter the grid size, from 1 to 15, 
				this will against the ship setup and see if a grid of that size 
				is viable.
1.1 OF (Grid Failure)	->	The grid size was not viable, please select another size go to 1.
1.2 O# (Grid Number)	->	This will flash the provided grid number, meaning accepted go to 
				2.
2. EA (Enter a, row)	-> 	This prompts the user to enter a row location, if invalid (too 
				big) it will go to 2.1, otherwise it will go to 2.2.
2.1 AF (Row failure)	->	This informs the user there was a failure and will go to 2.
2.2 A# (Row Number)	->	This confirms the value for A is reasonable and will go to 3.

3. EB (Enter b, column) -> 	This prompts the user to enter a column location, if invalid 
				(too big) it will go to 3.1, otherwise it will go to 3.2.
3.1 BF (Column failure)	->	This informs the user there was a failure and will go to 3.
3.2 B# (Column Number)	->	This confirms the value for B is reasonable and will go to 4.

4. [EMPTY]		->	This will now calculate in the backend and return one for the 
				following 4 options:
4.1 HH (Hit Hit)	->	If you a hit a ship it will flash HH, and the move you to step 2.
4.2 HD (Hit Sunk)	->	If you a sink a ship it will flash HH, and the move you to step 2.
4.3 CC (Miss Miss)	->	If you miss a ship, it will flash CC, and then you move to step 2.
4.4 HD-end (HIT SUNK)	->	Finally, if you get HD and then D D D D D this means that the game 
				is over the screen will turn black - you were able to sink all the 
				ships.

----------------------------------------------------------------------------------------------------

(c) 	The biggest issue I had was troubleshooting a burnt out 7-segment-display, I was extremely 
	confused on why it wasn't working and eventually I borrowed a friends and it started working. 
	He was gracious enough to let me keep it afterwards.The two extra features I implemented for 
	this were the 7-segment-display being used for user information and then the grid size to be 
	changeable at the start of every game. Lastly, I also implemented a green LED to show the
	user when the game as begun and when it had ended (after grid - last ship sunk) Another issue
	that I ran into was trying to optimize different logic in the game, a good place where I
	I managed to do that was instead of doing a lookup table for each possible input combination
	of the switch instead of managed to get its input with only 4 conditions. 

----------------------------------------------------------------------------------------------------

(d)	The grid is configurable and it is possible at each game, is it used a stop-check mechanism 
	to make sure that none of the hard-coded ships lie outside of the grid. All peripherals 
	used mirror the LAB. In addition to this there is error checking present for the grid and
	enter any values into the computer. i.e. anything the user enter is error checked. In addition
	to all of this there is also configuration options in the form of ship placement within the
	code a developer is able to change the ships positioning.

----------------------------------------------------------------------------------------------------

+--------+-----------------------------------------------------------------------------------------+
|   E0   | Request a grid size input from the user.						   |
+--------+-----------------------------------------------------------------------------------------+
|   0#   | Will repeat the grid size to the user in the form of grid - grid size.		   |
+--------+-----------------------------------------------------------------------------------------+
|   EA   | Request the first input, in this case for the ROW of the grid.	    		   |
+--------+-----------------------------------------------------------------------------------------+
|   A#   | Will confirm that the correct ROW has been inputed in the form A - Row Number	   |
+--------+-----------------------------------------------------------------------------------------+
|   EB   | Request the second input, in this case for the COLUMN of the grid.			   |
+--------+-----------------------------------------------------------------------------------------+
|   B#   | Will confirm that the correct COLUMN has been inputed in the form B - Column Number	   |
+--------+-----------------------------------------------------------------------------------------+
|   HH   | Hit-hit this is the inform the user a hit on a ship has been made.			   |
+--------+-----------------------------------------------------------------------------------------+
|   Hd   | Hit-down this is to inform the user a ship has been hit and it had sunk.		   |
+--------+-----------------------------------------------------------------------------------------+
|   CC   | Miss-miss this is to inform the user that there was a miss and nothing was hit.	   |
+--------+-----------------------------------------------------------------------------------------+
|  dddd  | This is to inform the user that the game is over and all the ships have been hit.	   |
+--------+-----------------------------------------------------------------------------------------+
| 0 to F | For input from user we use standard Hex-decimal notation.				   |
+--------+-----------------------------------------------------------------------------------------+

----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------