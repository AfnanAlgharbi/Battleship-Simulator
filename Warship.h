#pragma once
#include <iostream>
#include<string>
#include "Grid.h"
#ifndef WARSHIP_H
#define WARSHIP_H
using namespace std;

class Warship {
private:

	//attribute of what ship is it
	string ship;

	int getShipLength() { //functions that assigns the length of each ship
		if (ship == "Frigate")
			return 2;
		else if (ship == "Sub")
			return 3;
		else if (ship == "Destroyer")
			return 3;
		else if (ship == "Battleship")
			return 4;
		else if (ship == "Aircraft Carrier")
			return 5;
	}

public:
	Warship(string name) :ship(name) {}
	void shipGenerator(Grid&); // function that randomizes the location of the ships

};
#endif




