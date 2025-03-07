
#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

class Board {
private:
    void initializeGrid();
public:
    static const int SIZE=10;
    std::vector<std::vector<int>> grid;

    Board();
    bool loadConfiguration(const std::string filename);

    int attackCell(int row, int col);
};


#endif //BATTLESHIP_BOARD_H
