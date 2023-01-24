#include "../include/battleship.h"
#include <stdio.h>
#include <string.h>
#ifdef HARDWARE
#include "../include/io_hw.h"
#else
#include "../include/io.h"
#endif

int setupShips(void);

static struct Vessel vessels[5];

int main()
{
	// turning on the clocks
	turnOnClocks();
	
	// configuring the ports
	configurePorts(); 
	
	// creating the ships
	int vessels_number = setupShips();
	
	// grid input size logic
	int gridsize = 0;
	bool grid_accepted = false;
	bool grid_selected = false;
	
	/** login for accepting the grid size from the user **/
	while(grid_accepted == false)
	{
		// flashing user to enter data
		delay();
		lightLookup(14);
		delay();
		lightLookup(0);
		delay();
		lightLookup(-1);
		delay();
		// while a valid grid is not set
		while (grid_selected == false)
		{
			lightLookup(listenSwitches());
			if (listenBlueSwitch() == true)
			{
				lightLookup(-1);
				gridsize = listenSwitches();
				grid_selected = true;
				break;
			}
		}
		// if a valid grid was set lets see if the ships we have fit into it
		delay();
		grid_accepted = true;
		for(int i = 0; i < vessels_number; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				// if the ships do not fit in our grid say there is a failure and request another input
				if (vessels[i].vesselLocations[j].c > gridsize || vessels[i].vesselLocations[j].r > gridsize)
				{
					// display logic for showing grid error and setting indicator variables to false (input again)
					delay();
					lightLookup(0);
					delay();
					lightLookup(15);
					delay();
					lightLookup(-1);
					delay();
					grid_accepted = false; 
					grid_selected = false; 
					gridsize = 0;
					break;
				}
			}
		}
	}
	
	/** display logic for transition from grid selection to game **/
	lightLookup(-1);
	delay();
	lightLookup(0);
	delay();
	lightLookup(gridsize);
	delay();
	lightLookup(-1);
	
	
	/** battleship game logic, hitting, sinking, and others **/
	// turning on green indicator
	greenLED(true);
	delay();
	
	// game logic below
	bool game = true;
	int a_value = 0;
	int b_value = 0;
	bool a_selected = false;
	bool a_accepted = false;
	bool b_selected = false;
	bool b_accepted = false; 
	
	while(game == true)
		{
			// game control for getting coordinates from the player
			while(a_accepted == false)
				{
					// tell the user to input row
					lightLookup(14);
					delay();
					lightLookup(10);
					delay();
					lightLookup(-1);
					delay();
					a_accepted = true;
					// listening for row
					while (a_selected == false)
					{
						lightLookup(listenSwitches());
						if (listenBlueSwitch() == true)
							{
								a_value = listenSwitches();
								a_selected = true;
								break;
							}
					}
					// if the row is outside of the grid size throw and error and ask again
					if (a_value > gridsize || a_value == 0)
					{
						lightLookup(-1);
						delay();
						lightLookup(10);
						delay();
						lightLookup(15);
						delay();
						lightLookup(-1);
						delay();
						a_accepted = false; 
						a_selected = false; 
					}
					// otherwise it is within grid size therefore move forward with the change
					else
					{
						lightLookup(-1);
						delay();
						lightLookup(10);
						delay();
						lightLookup(a_value);
						delay();
						lightLookup(-1);
						delay();
					}
				}

			//game control for getting the column input
			while(b_accepted == false)
				{
					// request player for colum input
					lightLookup(14);
					delay();
					lightLookup(11);
					delay();
					lightLookup(-1);
					delay();
					b_accepted = true;
					// listener function for the column input
					while (b_selected == false)
					{
						lightLookup(listenSwitches());
						if (listenBlueSwitch() == true)
							{
								b_value = listenSwitches();
								b_selected = true;
								break;
							}
					}
					// if the column is outside of the grid ask again
					if (b_value > gridsize || b_value == 0)
					{
						lightLookup(-1);
						delay();
						lightLookup(11);
						delay();
						lightLookup(15);
						delay();
						lightLookup(-1);
						delay();
						b_accepted = false; 
						b_selected = false; 
					}
					// otherwise it works keep it
					else
					{
						lightLookup(-1);
						delay();
						lightLookup(11);
						delay();
						lightLookup(b_value);
						delay();
						lightLookup(-1);
						delay();
					}
				}
		// make the screen dark
		lightLookup(-1);
		
		// game control checking if all ships have been hit
		game = false;
		
		// if a ship was hit
		bool hit = false; 
		
		// look thru all the ships and see if any coordinates match up
		int hitship = 0;
		for (int i = 0; i < vessels_number; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				// if there is a match there was a hit, set hit to true and that location on vessel to hit
					if (vessels[i].vesselLocations[j].r == a_value && vessels[i].vesselLocations[j].c == b_value)
					{
						hit = true; 
						hitship = i;
						vessels[i].vesselLocations[j].hit = true; 
					}
			}
		}
		
		// if there was no hit
		if (hit == false)
		{
			// tell the user there was no hit and request the loop to be run again by setting 0's and falses
			delay();
			lightLookup(12);
			delay();
			lightLookup(-1);
			delay();
			lightLookup(12);
			delay();
			lightLookup(-1);
			delay();
			a_value = 0;
			b_value = 0;
			a_selected = false;
			a_accepted = false;
			b_selected = false;
			b_accepted = false; 
		}
		// otherwise there was a hit
		else
		{
			// check if it was a sunk or a hit by incrementing thru that ship
			bool sunkship = true;
				vessels[hitship].sunk = true;
				for (int j = 0; j < 5; j++)
				{
					if (vessels[hitship].vesselLocations[j].hit == false)
					{
						vessels[hitship].sunk = false;
						sunkship = false;
					}
				}
			// if the ship was sunk
			if (sunkship == true)
			{
			// let the user know that the ship was sunk
			delay();
			lightLookup(16);
			delay();
			lightLookup(-1);
			delay();
			lightLookup(13);
			delay();
			lightLookup(-1);
			delay();
			}
			else
			{
			// otherwise its just a normal hit let the user know that
			delay();
			lightLookup(16);
			delay();
			lightLookup(-1);
			delay();
			lightLookup(16);
			delay();
			lightLookup(-1);
			delay();
			}
			// set all the input variables to false so the loop can run again without incident 
				sunkship = false; 
				a_value = 0;
				b_value = 0;
				a_selected = false;
				a_accepted = false;
				b_selected = false;
				b_accepted = false; 
		}
				
		// check if ALL ship have been sunk, if they have don't set game to true therefore exit out of the loop
		for (int i = 0; i < vessels_number; i++)
		{
			if(vessels[i].sunk == false)
			{
				game = true;
			}
		}
		
	}
	
	// turning off green game indicator
	greenLED(false);
	
	// once all ships have been sunk this code will run
	// end game logic flash the screen with d's
	delay();
	lightLookup(13);
	delay();
	lightLookup(-1);
	delay();
	lightLookup(13);
	delay();
	lightLookup(-1);
	delay();
	lightLookup(13);
	delay();
	lightLookup(-1);
	delay();
	lightLookup(13);
	delay();
	lightLookup(-1);
	delay();
	lightLookup(13);
	delay();
	lightLookup(-1);
	delay();
	lightLookup(-1);
}

// i have created 5 ships but only implement two as shooting down each ship that takes too long
int setupShips(void)
{
	int vessels_number = 0;
	
	// test ship - DO NOT RUN WITH THE REST OF THE 5 SHIPS
	strcpy(vessels[0].name, "Submarine");
	vessels[0].sunk = false;
	vessels[0].length = 2;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 2;
	vessels[0].vesselLocations[0].hit = false;
	vessels[0].vesselLocations[1].c = 2;
	vessels[0].vesselLocations[1].r = 3;
	vessels[0].vesselLocations[1].hit = false;
	vessels[0].vesselLocations[2].c = -1;
	vessels[0].vesselLocations[2].r = -1;
	vessels[0].vesselLocations[2].hit = true;
	vessels[0].vesselLocations[3].c = -1;
	vessels[0].vesselLocations[3].r = -1;
	vessels[0].vesselLocations[3].hit = true;
	vessels[0].vesselLocations[4].c = -1;
	vessels[0].vesselLocations[4].r = -1;
	vessels[0].vesselLocations[4].hit = true;
	vessels_number++;
	

	/**
	// ship 0
	strcpy(vessels[0].name, "Carrier");
	vessels[0].sunk = false;
	vessels[0].length = 5;
	vessels[0].vesselLocations[0].c = 2;
	vessels[0].vesselLocations[0].r = 2;
	vessels[0].vesselLocations[0].hit = false;
	vessels[0].vesselLocations[1].c = 2;
	vessels[0].vesselLocations[1].r = 3;
	vessels[0].vesselLocations[1].hit = false;
	vessels[0].vesselLocations[2].c = 2;
	vessels[0].vesselLocations[2].r = 4;
	vessels[0].vesselLocations[2].hit = false;
	vessels[0].vesselLocations[3].c = 2;
	vessels[0].vesselLocations[3].r = 5;
	vessels[0].vesselLocations[3].hit = false;
	vessels[0].vesselLocations[4].c = 2;
	vessels[0].vesselLocations[4].r = 6;
	vessels[0].vesselLocations[4].hit = false;
	vessels_number++;
	
	// ship 1
	strcpy(vessels[1].name, "Destroyer");
	vessels[1].sunk = false;
	vessels[1].length = 3;
	vessels[1].vesselLocations[0].c = 4;
	vessels[1].vesselLocations[0].r = 2;
	vessels[1].vesselLocations[0].hit = false;
	vessels[1].vesselLocations[1].c = 4;
	vessels[1].vesselLocations[1].r = 3;
	vessels[1].vesselLocations[1].hit = false;
	vessels[1].vesselLocations[2].c = 4;
	vessels[1].vesselLocations[2].r = 4;
	vessels[1].vesselLocations[2].hit = false;
	vessels[1].vesselLocations[3].c = -1;
	vessels[1].vesselLocations[3].r = -1;
	vessels[1].vesselLocations[3].hit = true;
	vessels[1].vesselLocations[4].c = -1;
	vessels[1].vesselLocations[4].r = -1;
	vessels[1].vesselLocations[4].hit = true;
	vessels_number++;
	
	// ship 2
	strcpy(vessels[2].name, "Destroyer");
	vessels[2].sunk = false;
	vessels[2].length = 3;
	vessels[2].vesselLocations[0].c = 6;
	vessels[2].vesselLocations[0].r = 2;
	vessels[2].vesselLocations[0].hit = false;
	vessels[2].vesselLocations[1].c = 6;
	vessels[2].vesselLocations[1].r = 3;
	vessels[2].vesselLocations[1].hit = false;
	vessels[2].vesselLocations[2].c = 6;
	vessels[2].vesselLocations[2].r = 4;
	vessels[2].vesselLocations[2].hit = false;
	vessels[2].vesselLocations[3].c = -1;
	vessels[2].vesselLocations[3].r = -1;
	vessels[2].vesselLocations[3].hit = true;
	vessels[2].vesselLocations[4].c = -1;
	vessels[2].vesselLocations[4].r = -1;
	vessels[2].vesselLocations[4].hit = true;
	vessels_number++;
	// ship 3
	strcpy(vessels[3].name, "Cruiser");
	vessels[3].sunk = false;
	vessels[3].length = 4;
	vessels[3].vesselLocations[0].c = 8;
	vessels[3].vesselLocations[0].r = 2;
	vessels[3].vesselLocations[0].hit = false;
	vessels[3].vesselLocations[1].c = 8;
	vessels[3].vesselLocations[1].r = 3;
	vessels[3].vesselLocations[1].hit = false;
	vessels[3].vesselLocations[2].c = 8;
	vessels[3].vesselLocations[2].r = 4;
	vessels[3].vesselLocations[2].hit = false;
	vessels[3].vesselLocations[3].c = 8;
	vessels[3].vesselLocations[3].r = 5;
	vessels[3].vesselLocations[3].hit = false;
	vessels[3].vesselLocations[4].c = -1;
	vessels[3].vesselLocations[4].r = -1;
	vessels[3].vesselLocations[4].hit = true;
	vessels_number++;
	// ship 4
	strcpy(vessels[4].name, "Submarine");
	vessels[4].sunk = false;
	vessels[4].length = 2;
	vessels[4].vesselLocations[0].c = 2;
	vessels[4].vesselLocations[0].r = 8;
	vessels[4].vesselLocations[0].hit = false;
	vessels[4].vesselLocations[1].c = 2;
	vessels[4].vesselLocations[1].r = 9;
	vessels[4].vesselLocations[1].hit = false;
	vessels[4].vesselLocations[2].c = -1;
	vessels[4].vesselLocations[2].r = -1;
	vessels[4].vesselLocations[2].hit = true;
	vessels[4].vesselLocations[3].c = -1;
	vessels[4].vesselLocations[3].r = -1;
	vessels[4].vesselLocations[3].hit = true;
	vessels[4].vesselLocations[4].c = -1;
	vessels[4].vesselLocations[4].r = -1;
	vessels[4].vesselLocations[4].hit = true;
	vessels_number++;
	**/
	
	// return value
	return vessels_number;
}
