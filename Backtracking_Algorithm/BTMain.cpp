#include <iostream>
#include <chrono>
#include "Queen.h"
#include "Backtracking.hpp"


int main() {
    //Start measurning time
    auto start = std::chrono::high_resolution_clock::now();

    //Declare the array of the grid
	QueenGrid QG;
    
    //Initialize the array
    for( int i=0; i<numOfQueens; ++i ){
        for( int j=0; j<numOfQueens; ++j ){
            QG.Grid[i][j].active = false;
            QG.Grid[i][j].numOfConflicts = 0;
            QG.Grid[i][j].pos.x = i;
            QG.Grid[i][j].pos.y = j;
        }
    }

    
    QG = CSP_Backtracking(QG);
    
    //std::cout<<"HIHI"<<std::endl;
    PrintGrid(QG);
    //Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now();

    //Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    //Display execution time
    std::cout<<duration.count()<<" microseconds"<<std::endl;
    

    return 0;
}