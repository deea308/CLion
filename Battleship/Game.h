//
// Created by Andreea on 6/2/2024.
//
#include "Board.h"

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H
#include<string>
#include <QTableWidget>
#include <QLabel>

class Game: public Board{
private:
    Board board;
    int movesLeft;
    QLabel* movesLabel;
    QLabel* statusLabel;
    QTableWidget* tableWidget;
public:
    Game(QTableWidget* table, QLabel* movesLbl, QLabel* statusLbl);

    void startNewGame(const std::string configFile);
    void attackCell(int row, int col);
    bool isGameWon();
    void updateTable();
    void updateStatus();
};


#endif //BATTLESHIP_GAME_H
