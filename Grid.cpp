#include<iostream>
#include <string>
#include "Grid.h"
using namespace std;

Grid::Grid() {
	// creating the structure of the board by filling the array
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			grid[x][y] = "| |";
		}
	}
}

void Grid::title() {
	
	cout << " ____         __     _______    _______  ___      ___      _______    ______   _      _    _______    ____                  _                                  _" << endl;
	cout << "||   ||      // |   |_______|  |_______| | |      | |      | |____|  | |____| | |    | |  |_______|  | |  ||               |-|                                |-|" << endl;
	cout << "||___//     //  |      | |        | |    | |      | |      | |____   | |____  | |____| |     | |     | |__//          _____|_|______                     _____|_|______" << endl;
	cout << "||---||    //___|      | |        | |    | |      | |      | _____|  | ___| | |  ____| |     | |     | |__/          |[]___[]___[]__|_                  |[]___[]___[]__|_" << endl;
	cout << "||   ||   //----|      | |        | |    | |      | |      | |            | | | |    | |     | |     | |           _|_________________|               _|_________________| " << endl;
	cout << "||   //  //     |      | |        | |    | |____  | |____  | |____    ____| | | |    | |   __| |__   | |           |      []   []      /              |      []   []      / " << endl;
	cout << "||__//  //      |      |_|        |_|    |______| |______| |______|  |______| |_|    |_|  |_______|  |_|           |__________________/               |__________________/" << endl;
	cout << endl << endl << endl;

}
//function part of the Grid class to layout the grid
void Grid::gridLayout(bool showAll)
{
	//printing out the grid using 2D arrays
	for (int x = 0; x < 10; x++) {
		cout << "\t\t\t\t\t\t";
		// laying out title of the columns 1- 10
		if (x + 1 != 10) {
			cout << x + 1 << " ";
		}
		else
			cout << x + 1;
		for (int y = 0; y < 10; y++) {
			if (showAll || grid[x][y] == "|X|" || grid[x][y] == "|O|")
				cout << grid[x][y];
			else
				cout << "| |";
		}

		cout << endl;
	}
	cout << endl;
}
void Grid::newMove(string str)
{
	
	char playerA = toupper(str[0]);
	char playerB = toupper(str[1]);
	char playerC;
	if (str.length() == 3)
	{
		playerC = toupper(str[2]);
	}


	if (playerA < 65 || playerA > 74)
	{
		cout << "not valid, try again." << endl;
		cout << endl;
		return;
	}
	else if (str.length() == 3)
	{
		if (playerC != 48)
		{
			cout << "not valid, try again." << endl;
			cout << endl;
			return;
		}
	}
	else
	{
		if (playerB < 49 || playerB > 57)
		{
			cout << "not valid, try again." << endl;
			cout << endl;
			return;
		}
	}

	int playerRow = (int)playerA - 65;
	int playerCol;
	if (str.length() == 2)
	{
		playerCol = (int)playerB - 49;
	}
	else
	{
		playerCol = 9;
	}

	cout << endl;

	displayHit(playerCol, playerRow);
}
 void Grid::displayHit(int col, int row) {
	 title();
	if (grid[col][row] == "| |") 
	{
			grid[col][row] = "|O|";
			cout << "miss count: " << ++count << endl;
			cout << "You missed!" << endl;
			cout << "Points: " << score << endl;
			cout << "\t\t\t\t\t\t  |A  B  C  D  E  F  G  H  I  J| " << endl;
	}
	else
	{

			grid[col][row] = "|X|";
			cout << "you got a hit!       +1 point" << endl;
			cout << "miss count: " << count << endl;
			cout << "Points: " << ++score << endl;
			cout << "  \t\t\t\t\t\t  |A  B  C  D  E  F  G  H  I  J| " << endl;

		}

	}




