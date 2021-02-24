#include "GameWorld.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

GameWorld::GameWorld(int aPlayerRow, int aPlayerColumn)
{
	fPlayerRow = aPlayerRow;
	fPlayerColumn = aPlayerColumn;
}


GameWorld::~GameWorld()
{
}

void GameWorld::WorldInitialatation()
{
	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			fWorldDimentions[i][y] = "E";
		}
	}

	for (int i = 0; i < 8; i++)
	{
		fWorldDimentions[0][i] = "W";
	}

	for (int i = 0; i < 8; i++)
	{
		fWorldDimentions[7][i] = "W";
	}

	for (int i = 1; i < 7; i++)
	{
		fWorldDimentions[i][0] = "W";
	}

	for (int i = 1; i < 7; i++)
	{
		fWorldDimentions[i][7] = "W";
	}

	for (int i = 1; i < 6; i++)
	{
		fWorldDimentions[i][4] = "W";
	}

	fWorldDimentions[3][1] = "W";
	fWorldDimentions[3][2] = "W";
	fWorldDimentions[5][2] = "W";
	fWorldDimentions[5][3] = "W";
	fWorldDimentions[5][5] = "W";

	fWorldDimentions[7][2] = "S";
	fWorldDimentions[1][1] = "G";

	fWorldDimentions[1][3] = "D";
	fWorldDimentions[1][5] = "D";
	fWorldDimentions[3][6] = "D";
}

void GameWorld::ShowWorldMap()
{
	for (int i = 0; i < 8; i++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (fWorldDimentions[i][y] == "W")
			{
				cout << '#';
			}
			else if (fWorldDimentions[i][y] == "E")
			{
				cout << ' ';
			}
			else if (fWorldDimentions[i][y] == "D")
			{
				cout << 'D';
			}
			else if (fWorldDimentions[i][y] == "G")
			{
				cout << "G";
			}
			else if (fWorldDimentions[i][y] == "P")
			{
				cout << "P";
			}
			else
			{
				cout << "S";
			}
		}

		cout << endl;
	}
}

vector<Directions> GameWorld::FindMoves()
{
	vector<Directions> lAvailableMoves;

	if (fWorldDimentions[fPlayerRow][fPlayerColumn] != "S")
	{
		if (fWorldDimentions[fPlayerRow][fPlayerColumn + 1] != "W")
		{
			lAvailableMoves.push_back(east);
		}

		if (fWorldDimentions[fPlayerRow][fPlayerColumn - 1] != "W")
		{
			lAvailableMoves.push_back(west);
		}

		if (fWorldDimentions[fPlayerRow - 1][fPlayerColumn] != "W")
		{
			lAvailableMoves.push_back(north);
		}

		if (fWorldDimentions[fPlayerRow + 1][fPlayerColumn] != "W")
		{
			lAvailableMoves.push_back(south);
		}

	}
	else
	{
		lAvailableMoves.push_back(north);
	}

	return lAvailableMoves;
}

void GameWorld::DisplayMoves(vector<Directions> aAvailableMove)
{
	for (int i = 0; i < aAvailableMove.size(); i++)
	{
		if (i != aAvailableMove.size() - 1)
		{
			if (aAvailableMove[i] == north)
			{
				cout << "N, ";
			}

			if (aAvailableMove[i] == west)
			{
				cout << "W, ";
			}

			if (aAvailableMove[i] == east)
			{
				cout << "E, ";
			}

			if (aAvailableMove[i] == south)
			{
				cout << "S, ";
			}
		}
		else
		{
			if (aAvailableMove[i] == north)
			{
				cout << "N: ";
			}

			if (aAvailableMove[i] == west)
			{
				cout << "W: ";
			}

			if (aAvailableMove[i] == east)
			{
				cout << "E: ";
			}

			if (aAvailableMove[i] == south)
			{
				cout << "S: ";
			}
		}
	}
}

Directions GameWorld::ProcessUsersAction(string aAction)
{
	if (aAction == "N")
	{
		return north;
	}
	else if (aAction == "S")
	{
		return south;
	}
	else if (aAction == "W")
	{
		return west;
	}
	else
	{
		return east;
	}
}




bool GameWorld::MovePlayer(Directions aDirection)
{
	fWorldDimentions[fPlayerRow][fPlayerColumn] = "E";

	if (aDirection == north)
	{
		if (fWorldDimentions[fPlayerRow - 1][fPlayerColumn] == "G")
		{
			cout << "Wow - you've discovered a large vhest filled with GOLD coins" << endl;
			cout << "YOU WIN!";

			bool lEndGame = true;

			return lEndGame;
		}
		else if (fWorldDimentions[fPlayerRow - 1][fPlayerColumn] == "D")
		{
			cout << "OH NOOOOO!!!.. you've fallen down a pit :(" << endl;
			cout << "YOU ARE DED M8";

			bool lEndGame = true;

			return lEndGame;
		}
		else
		{
			fPlayerRow--;
			fWorldDimentions[fPlayerRow][fPlayerColumn] = "P";

			bool lEndGame = false;

			return lEndGame;
		}
	}
	else if (aDirection == south)
	{
		if (fWorldDimentions[fPlayerRow + 1][fPlayerColumn] == "G")
		{
			cout << "Wow - you've discovered a large chest filled with GOLD coins" << endl;
			cout << "YOU WIN!";

			bool lEndGame = true;

			return lEndGame;
		}
		else if (fWorldDimentions[fPlayerRow + 1][fPlayerColumn] == "D")
		{
			cout << "OH NOOOOO!!!.. you've fallen down a pit :(" << endl;
			cout << "YOU ARE DED M8";

			bool lEndGame = true;

			return lEndGame;
		}
		else
		{
			fPlayerRow++;
			fWorldDimentions[fPlayerRow][fPlayerColumn] = "P";

			bool lEndGame = false;

			return lEndGame;
		}

	}
	else if (aDirection == west)
	{
		if (fWorldDimentions[fPlayerRow][fPlayerColumn - 1] == "G")
		{
			cout << "Wow - you've discovered a large vhest filled with GOLD coins" << endl;
			cout << "YOU WIN!";

			bool lEndGame = true;

			return lEndGame;
		}
		else if (fWorldDimentions[fPlayerRow][fPlayerColumn - 1] == "D")
		{
			cout << "OH NOOOOO!!!.. you've fallen down a pit :(" << endl;
			cout << "YOU ARE DED M8";

			bool lEndGame = true;

			return lEndGame;
		}
		else
		{
			fPlayerColumn--;
			fWorldDimentions[fPlayerRow][fPlayerColumn] = "P";

			bool lEndGame = false;

			return lEndGame;
		}

	}
	else
	{
		if (fWorldDimentions[fPlayerRow][fPlayerColumn + 1] == "G")
		{
			cout << "Wow - you've discovered a large vhest filled with GOLD coins" << endl;
			cout << "YOU WIN!";

			bool lEndGame = true;

			return lEndGame;
		}
		else if (fWorldDimentions[fPlayerRow][fPlayerColumn + 1] == "D")
		{
			cout << "OH NOOOOO!!!.. you've fallen down a pit :(" << endl;
			cout << "YOU ARE DED M8";

			bool lEndGame = true;

			return lEndGame;
		}
		else
		{
			fPlayerColumn++;
			fWorldDimentions[fPlayerRow][fPlayerColumn] = "P";

			bool lEndGame = false;

			return lEndGame;
		}

	}
}
