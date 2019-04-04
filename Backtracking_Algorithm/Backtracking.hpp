#pragma once
#include <iostream>
#include <vector>
#include "Queen.h"

//Struct to store a 2D array of Queen grid
struct QueenGrid {
    Queen Grid[numOfQueens][numOfQueens];
    bool fail;
}; 


//Recursive function for the CSP Backtracking algorithm
QueenGrid CSP_Backtracking(QueenGrid grid, std::vector<Queen> queenPos ){
    /* If passed grid is complete then return */
    //check each queen's confliction when number of queen is 8, otherwise skip and continue
    if( queenPos.size() == 8 ){
        //iterate and check if there's no confliction
        for( std::vector<Queen>::iterator it=queenPos.begin(); it != queenPos.end(); ++it ){
            if( calculateConflicts( *it, grid.Grid ) > 0 ){
                //not complete so return failure
                grid.fail = true;
                return grid;
            }
        }
        //grid is complete so return it
        grid.fail = false;
        return grid;
    }
    else if( queenPos.size() < 8 ){
        //select unassigned row
        int currrentRow = queenPos.size();
        return grid;
    }
    
    
    return grid;
};


//Display NxN queen grid
void PrintGrid( QueenGrid grid ){

    //x-axis interation
    for( int y=numOfQueens-1; y>=0; --y ){
        
        //Display the first top border
        if( y==numOfQueens-1 ){
            std::cout<<"|";
            for( int i=0; i<numOfQueens-1; ++i ){std::cout<<"---+";} 
            std::cout<<"---|\n"; 
        }

        //y-axis iteration -> Display 'X' if Queen is active, else blank
        std::cout<<"|";
        for( int x=0; x<numOfQueens; ++x ){
            if( grid.Grid[x][y].active == true ){
                std::cout<<" X "<<"|";
            }
            else {
                std::cout<<"   "<<"|";
            }
        }

        //Display the bottom border
        std::cout<<"\n"<<"|";
        for( int i=0; i<numOfQueens-1; ++i ){std::cout<<"---+";}
        std::cout<<"---|"<<"\n";
    }
}
