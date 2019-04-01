#include <iostream>
#include "Queen.h"

using namespace std;

int main() {
	//Initializing the array of the grid
	Queen Grid[numOfQueens][numOfQueens];


	//Randomly placing numOfQueens on the board
	int randx, randy, count = 0;
	while (count <= numOfQueens) {
		randx = rand() % numOfQueens;
		randy = rand() % numOfQueens;

		if (Grid[randx][randy].active == false) {
			Grid[randx][randy].active = true;
			Grid[randx][randy].pos.x = randx;
			Grid[randx][randy].pos.y = randy;
			count++;
		}
	}



	//Calculate the initial number of conflicts for each queen
	for (int i = 0; i < numOfQueens; i++) {
		for (int j = 0; j < numOfQueens; j++) {
			if (Grid[i][j].active == true) {
				Grid[i][j].numOfConflicts = calculateConflicts(Grid[i][j], Grid);
			}
		}
	}


	//Run constraint satisfaction algorithm with minimum-conflict heuristic



	return 0;
}