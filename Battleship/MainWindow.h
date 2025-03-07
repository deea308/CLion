//
// Created by Andreea on 6/2/2024.
//
#include "Game.h"
#include "Board.h"
#ifndef BATTLESHIP_MAINWINDOW_H
#define BATTLESHIP_MAINWINDOW_H
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

class MainWindow: public QMainWindow {
private:
    QTableWidget* tableWidget;
    QPushButton* attackButton;
    QPushButton* newGameButton;
    QLineEdit* configInput;
    QLabel* movesLabel;
    QLabel* statusLabel;
    Game* game;
public:
    MainWindow(QWidget* parent= nullptr);
public slots:
    void attackCell();
    void startNewGame();
};


#endif //BATTLESHIP_MAINWINDOW_H
