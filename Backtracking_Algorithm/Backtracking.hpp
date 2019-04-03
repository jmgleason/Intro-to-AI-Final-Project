#pragma once
#include <iostream>
#include "Queen.h"

//Struct to store a 2D array of Queen grid
struct QueenGrid {
    Queen Grid[numOfQueens][numOfQueens];
}; 


//Recursive function for the CSP Backtracking algorithm
QueenGrid CSP_Backtracking(QueenGrid grid){
    return grid;
};


//Display NxN queen grid
void PrintGrid( QueenGrid grid ){
    for( int x=0; x<numOfQueens; ++x ){
        if( x==0 ){ std::cout<<"|"; for( int i=0; i<numOfQueens-1; ++i ){std::cout<<"---+";} std::cout<<"---|\n"; }
        std::cout<<"|";
        for( int y=numOfQueens-1; y>=0; --y ){
            if( grid.Grid[x][y].active == true ){
                std::cout<<" X ";
            }
            else {
                std::cout<<"   ";
            }
            std::cout<<"|";
        }
        std::cout<<"\n";
        std::cout<<"|";
        for( int i=0; i<numOfQueens-1; ++i ){std::cout<<"---+";}
        std::cout<<"---|";
        std::cout<<"\n";
    }
}