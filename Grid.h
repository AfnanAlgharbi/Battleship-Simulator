#pragma once
#include<iostream>
#include <string>
#ifndef GRID_H
#define GRID_H
using namespace std;

class Grid {
private:
	static const int COLS = 10;
	static const int ROWS = 10;
	int score = 0;


public:
	void gridLayout(bool showAll);
	void newMove(string str);
	void displayHit(int row, int col);	int count =0;
	Grid();
	void title();
	string grid[ROWS][COLS];

};


#endif




