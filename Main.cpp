#include <iostream>
#include <string>
#include "Grid.h"
#include "Warship.h"
#include <ctime>
#include <cstdlib>


using namespace std;

void title() {
	cout << " ____         __     _______    _______  ___      ___      _______    ______   _      _    _______    ____                  _                                  _" << endl;
	cout << "||   ||      // |   |_______|  |_______| | |      | |      | |____|  | |____| | |    | |  |_______|  | |  ||               |-|                                |-|" << endl;    
	cout << "||___//     //  |      | |        | |    | |      | |      | |____   | |____  | |____| |     | |     | |__//          _____|_|______                     _____|_|______" << endl;
	cout << "||---||    //___|      | |        | |    | |      | |      | _____|  | ___| | |  ____| |     | |     | |__/          |[]___[]___[]__|_                  |[]___[]___[]__|_" << endl;
	cout << "||   ||   //----|      | |        | |    | |      | |      | |            | | | |    | |     | |     | |           _|_________________|               _|_________________| " << endl;
	cout << "||   //  //     |      | |        | |    | |____  | |____  | |____    ____| | | |    | |   __| |__   | |           |      []   []      /              |      []   []      / " << endl;
	cout << "||__//  //      |      |_|        |_|    |______| |______| |______|  |______| |_|    |_|  |_______|  |_|           |__________________/               |__________________/" << endl;
	cout << endl << endl << endl;

}
inline void WaitEnter() {
	std::cout << " ";
	while (std::cin.get() != '\n');
}

void gameOn() {
	string name;
	cout << "ENTER PLAYER'S NAME: " << endl; 
	cin >> name;
	cout << "\t\t\tIt is a thunderous day for sailing uboard the cruise missile  destroyer USS John Paul Jones." << endl;
	cout << "\t\t\tThe sea is angry and the  waves are as huge as mountains.On top of that, the sattelites are" << endl;
	cout << "\t\t\tout and the troubled commander that you are , have been demanding your crew to maintain the" << endl;
	cout << "\t\t\tship and take their precautions. All of the sudden, you hear ''Commander!we are under attack!''" << endl;
	cout << "\t\t\tLays ahead of you the abominated flee of your enemy which you long to defeat with triumphing" << endl;
	cout << "\t\t\tvictory! Luckily, your sonar works and your crew is able to have a good look at your enemy's" << endl;
	cout << "\t\t\tflee and realize that they occupy an area of a 10x10 grid. They also make up the number and" << endl;
	cout << "\t\t\tsize of the ships, as well as detect whether a hit will be spotted or not. " << endl << endl;
	cout << "Commander "<< name << "...Your crew is looking out for the following:" << endl << endl << endl;
	cout << "				 Ship   |   size" << endl;
	cout << "			--------------------------" << endl;
	cout << "			Frigate             2" << endl;
	cout << "			Sub                 3" << endl;
	cout << "			Destroyer           3" << endl;
	cout << "			Battleship          4" << endl;
	cout << "			Aircraft Carrier    5" << endl << endl;
	cout <<">>Press Enter to continue"<<endl;
	WaitEnter();
	cout <<"Are you ready to defeat the flee, Commander "<<name<<"?!" << endl;
	WaitEnter();
	cout << "LET'S  GO!!!!!!!!!!!" << endl;
	WaitEnter();
	system("cls");

srand(time(NULL));


	//display row titles
	title();
	cout << "  \t\t\t\t\t\t  |A  B  C  D  E  F  G  H  I  J| " << endl;

	Grid oGrid;
	//five instances of type string and laying them out
	Warship frigate("Frigate");
	frigate.shipGenerator(oGrid);

	Warship sub("Sub");
	sub.shipGenerator(oGrid);

	Warship destroyer("Destroyer");
	destroyer.shipGenerator(oGrid);

	Warship battleship("Battleship");
	battleship.shipGenerator(oGrid);

	Warship airCraft("Aircraft Carrier");
	airCraft.shipGenerator(oGrid);

	//laying out the ships with their letters
	
	
	bool playMode = true;
	
	while (playMode) {
		oGrid.gridLayout(false);

		string nextCor;

		cout << "Enter a coordinate to fire or -1 for Home Screen: ";

		cin >> nextCor;

		if (nextCor.length() > 3 || nextCor.length() < 2)
		{
			cout << "invalid, try again.";
			cout << endl;
			continue;
		}
		else if (oGrid.count == 14)
		{
			cout << "\t\t\t|GAME OVER!|" << endl;
			playMode = false;
			system("pause");
			system("cls");
			title();
		}
		else if (nextCor == "-1")
		{
			playMode = false;
			system("cls");
			title();
		}
		else
		{
			system("cls");
			oGrid.newMove(nextCor);

		}
	}
	cout << endl;
	

}


void Menu()
{

	cout << "\t \t \t\t\t\t" << "MAIN MENU" << endl;
	cout << "\t \t \t\t\t\t" << "---------" << endl << endl;

	cout << "\t \t \t\t\t\t" <<"A. Start Game\n";
	cout << "\t \t \t\t\t\t" <<"B. Instructions\n";
	cout << "\t \t \t\t\t\t" <<"C. Quit Game";

}



	int main() {
		
		char option;
		Grid oGrid;
		//Create menu
		const char Op1 = 'A', Op2 = 'B', Op3 = 'C';
		title();
		do {
			;
			Menu();
			cout << "\n>> Please choose an option:  " << endl << endl;
			cin >> option;
			system("cls");
			//respond to choice
			switch (option)
			{
			
			case Op1:
			case 'a':
				title();
				gameOn();
				break;
			case Op2:
			case 'b':
				title();
				cout << "  INSTRUCTIONS:" << endl;
				cout << "  ------------" << endl;
				cout << "- To shoot a coordinate, Choose which row and column to fire. First a letter, then a number." << endl;
				cout << "- If at any point during the game you would like to go back to Main Menu, enter -1. " << endl;
				cout << "- A Hit is marked as an 'X' and a miss is marked as a 'O'" << endl;
				cout << "- Your overall score will be displayed at the bottom, each hit is worth a point." << endl;
				cout << "- If you miss 15 times, GAME OVER!" << endl<<endl<<endl;
				cout << ">> Enter -1 for HomeScreen" << endl;
				break;
			
			case Op3:
			case 'c':
				title();
				cout << "GoodBye!";
				option = Op3;
				break;


			}


			system("pause>0");
		} while (option != Op3);

	}


