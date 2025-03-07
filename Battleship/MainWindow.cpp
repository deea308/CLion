//
// Created by Andreea on 6/2/2024.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    tableWidget= new QTableWidget(10,10,this);
    tableWidget->setFixedSize(400,400);
    tableWidget->resizeColumnsToContents();
    tableWidget->resizeRowsToContents();

    attackButton= new QPushButton("Attack selected cell", this);
    newGameButton= new QPushButton("Start new game", this);
    configInput= new QLineEdit(this);
    movesLabel= new QLabel("moves left: 30", this);
    statusLabel= new QLabel("in progress", this);

    QVBoxLayout* layout= new QVBoxLayout();
    layout->addWidget(tableWidget);
    layout->addWidget(attackButton);
    layout->addWidget(newGameButton);
    layout->addWidget(configInput);
    layout->addWidget(movesLabel);
    layout->addWidget(statusLabel);

    QWidget* centralWidget= new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    game= new Game(tableWidget,movesLabel, statusLabel);
    game->startNewGame("configuration.txt");

    connect(attackButton, &QPushButton::clicked, this, &MainWindow::attackCell);
    connect(newGameButton, &QPushButton::clicked, this, &MainWindow::startNewGame);
}

void MainWindow::attackCell() {
    QList<QTableWidgetItem*> selectedItems = tableWidget-> selectedItems();
    if(selectedItems.isEmpty()){
        QMessageBox::warning(this,"Error", "no cell selected");
        return;
    }
    int row= selectedItems.first()->row();
    int col= selectedItems.first()->column();
    game->attackCell(row, col);

}

void MainWindow::startNewGame() {
    QString configFile= configInput->text();
    if(configFile.isEmpty()){
        QMessageBox::warning(this,"error","no configuration file specified");
        return;
    }
    game->startNewGame(configFile.toStdString());
}
