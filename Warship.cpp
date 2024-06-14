#include <iostream>
#include <string>
#include <ctime>
#include "Warship.h"
using namespace std;


void Warship::shipGenerator(Grid& grid) {


	int length = getShipLength();

	bool running = true; //setting a bool to true it creates a never ending loop until appointed a place
	while (running)
	{
		int col = rand() % (10 - length);//randomizing column
		int row = rand() % (10 - length); //randomizing row


		int diffPosition = rand() % 2; //randomizing position
		if (diffPosition)
		{
			swap(row, col); //if position is changed, then switch row and col

			bool freeSpot = true; //setting a bool to true if a spot is free, then | | is placed
			for (int x = 0; x < length; x++)
			{
				if (grid.grid[x + col][row] != "| |") {
					freeSpot = false;
					break;
				}
			}
			if (!freeSpot) { //otherwise, continue reasigning 
				continue;
			}
			char spot = ship.at(0);
			string place;
			place = spot;
			for (int x = 0; x < length; x++)
			{
				grid.grid[x + col][row] = "|" + place + "|";
			}
			break;
			//when ship is placed, loop ends
		}
		else {
			//same concept
			bool freeSpot = true;
			for (int x = 0; x < length; x++)
			{
				if (grid.grid[col][row + x] != "| |")
				{
					freeSpot = false;
					break;
				}

			}
			if (!freeSpot)
				continue;


			char spot = ship.at(0);
			string place;
			place = spot;
			for (int x = 0; x < length; x++)
			{
				grid.grid[col][row + x] = "" + place + "|";
			}
			break;
		}
	}
}