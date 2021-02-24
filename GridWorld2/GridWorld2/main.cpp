#include "GameWorld.h"
#include "Directions.cpp"
#include<iostream>
#include <string>

using namespace std;


int main()
{
	string fAction = "0";
	bool fEndGame = false;
	GameWorld grid(7, 2);
	grid.WorldInitialatation();



	while (fAction != "Q")
	{
		if (fEndGame != true) 
		{
			cout << endl;
			grid.ShowWorldMap();

			cout << "Welcome to GridWorld! " << endl;
			cout << "Valid commands: N, S, W and E for directions. Q to quit the game." << endl;
			cout << "You can move: ";

			grid.DisplayMoves(grid.FindMoves());

			cin >> fAction;


			fEndGame = grid.MovePlayer(grid.ProcessUsersAction(fAction));
		}
		else
		{
			break;
		}
	}


	return 0;
}