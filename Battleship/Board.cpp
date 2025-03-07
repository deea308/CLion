//
// Created by Andreea on 6/2/2024.
//

#include "Board.h"
#include <fstream>
#include <sstream>
//constructor of the grid
Board::Board(): grid(SIZE, std::vector<int>(SIZE)) {
    initializeGrid();
}

//private function to initialize the vector with 0
void Board::initializeGrid() {
    for(auto row: grid)
        std::fill(row.begin(), row.end(),0);

}

//function to load a configuration from file
bool Board::loadConfiguration(const std::string filename) {
//    std::ifstream file(filename);
//    if(!file.is_open()) return false;
//
//    for (int row=0;row<SIZE;row++){
//        std::string line;
//        std::getline(file,line);
//        std::istringstream stream(line);//creates an input string stream stream from the line string.
//        //This allows us to treat the string as a stream, which makes it easy to extract individual elements (such as integers) from the line.
//        for(int col=0;col<SIZE; col++)
//            stream>>grid[row][col];//extracts the next integer from the stream and assigns it to the grid at the current row (row) and column (col).
//            //The extraction operator (>>) reads an integer from the stream and places it in grid[row][col]
//    }
//    return true;
    std::ifstream file(filename);
    if(!file.is_open()) return false;

    // Reset the grid to all zeros before loading the new configuration
    initializeGrid();

    for (int row = 0; row < SIZE; row++) {
        std::string line;
        std::getline(file, line);
        std::istringstream stream(line);
        for (int col = 0; col < SIZE; col++)
            stream >> grid[row][col];
    }
    return true;
}

//function to attack on a cell
int Board::attackCell(int row, int col) {
    if(grid[row][col]==1){
        grid[row][col]=2;//hit ship
        return 1;
    }else if(grid[row][col]==0){
        grid[row][col]=-1; //hit water
        return 0;
    }
    return -1;
}
