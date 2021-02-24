#pragma once
#include<vector>
#include<string>

using namespace std;

enum Directions { north, west, east, south };

class GameWorld
{
private:
	int fPlayerRow;
	int fPlayerColumn;
	string fWorldDimentions[8][8];
	

public:
	GameWorld(int aPlayerRow, int aPlayerColumn);

	~GameWorld();

	void WorldInitialatation();
	void ShowWorldMap();
	bool MovePlayer(Directions aDirection);
	vector<Directions> FindMoves();
	void DisplayMoves(vector<Directions> aAvailableMove);
	Directions ProcessUsersAction(string aAction);
};