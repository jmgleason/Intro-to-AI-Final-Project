#include <iostream>
#include <stdlib.h>
#include "Queen.h"

using namespace std;


int main() {
	//Initializing the array of the grid
	struct Queen Grid[numOfQueens][numOfQueens];

	for (int i = 0; i < numOfQueens; i++) {
		for (int j = 0; i < numOfQueens; j++) {
			Grid[i][j].active = false;
		}
	}

	//Array to hold the queens with conflicts
	struct Queen ConflictQueens[numOfQueens];  //Maybe use a queue here and just loop while not empty

	//Initializing conflicts to -1 to see if this space has been used or not
	for (int i = 0; i < numOfQueens; i++) {
		ConflictQueens[i].numOfConflicts = -1;
	}

	//Randomly placing numOfQueens on the board so there is one queen in each column.
	//This is known as a greedy placement of initial step which will allow us to only move
	//the queens up and down in the specific column
	int randy, count = 0;
	for (int i = 0; i < numOfQueens; i++) {
		randy = rand() % numOfQueens;

		Grid[i][randy].active = true;
		Grid[i][randy].pos.x = i;
		Grid[i][randy].pos.y = randy;
	}



	//Calculate the initial number of conflicts for each queen
	for (int i = 0; i < numOfQueens; i++) {
		for (int j = 0; j < numOfQueens; j++) {
			if (Grid[i][j].active == true) {
				Grid[i][j].numOfConflicts = calculateConflicts(Grid[i][j], Grid);
			}
		}
	}

	//If any of the queens have a conflict, add it to the conflict array
	for (int i = 0; i < numOfQueens; i++) {
		for (int j = 0; j < numOfQueens; j++) {
			if (Grid[i][j].active == true && Grid[i][j].numOfConflicts > 0) {
				for (int k = 0; k < numOfQueens; k++) {
					if (ConflictQueens[k].numOfConflicts == -1) {
						ConflictQueens[k] = Grid[i][j];
						break;
					}
				}
			}
		}
	}

	cout << "Initial constraints:  \n\n";
	for	(Queen x : ConflictQueens) {
		if (x.numOfConflicts != -1) {
			cout << "Position: (" << x.pos.x << "," << x.pos.y << ")\n";
			cout << "Number of conflicts:  " << x.numOfConflicts << endl << endl;
		}
	}

	//Run constraint satisfaction algorithm with minimum-conflict heuristic

	int x = 0;
	cin >> x;

	return 0;
}