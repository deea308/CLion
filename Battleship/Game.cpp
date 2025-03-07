#include "Game.h"
#include<QMessageBox>


//constructor
Game::Game(QTableWidget *table, QLabel *movesLbl, QLabel *statusLbl) {
    tableWidget=table;
    movesLabel=movesLbl;
    statusLabel=statusLbl;
    movesLeft=30;
}

void Game::startNewGame(const std::string configFile) {
    board.loadConfiguration(configFile);
    movesLeft=30;
    updateTable();
    updateStatus();
}

void Game::attackCell(int row, int col) {
    if(row<0 || row>=Board::SIZE || col<0 || col>=Board::SIZE){
        QMessageBox::warning(nullptr, "Error", "Invalid cell");
        return;
    }

    int result= board.attackCell(row, col);
    if(result==-1){
        QMessageBox::warning(nullptr,"Error", "Call already attacked");
        return;
    }

    movesLeft--;
    updateStatus();
    updateTable();

    if(movesLeft<=0 && !isGameWon()){
        statusLabel->setText("player loses");
    }
}

bool Game::isGameWon() {
    for(int row=0; row<Board::SIZE; row++){
        for( int col=0;col<Board::SIZE; col++){
            if(board.grid[row][col]==1)
                return false;
        }
    }
    return true;
}

//reflect the current state of the widget
void Game::updateTable() {
    for(int row=0; row<Board::SIZE; row++){
        for(int col=0;col<Board::SIZE; col++){
            QTableWidgetItem* item= tableWidget->item(row, col);
            if(!item){
                item= new QTableWidgetItem("x");
                tableWidget->setItem(row,col,item);
            }

            if(board.grid[row][col]==2){
                item->setText("*");
                item->setBackground(Qt::red);
            }else if(board.grid[row][col]==-1){
                item->setText("o");
                item->setBackground(Qt::blue);
            }else{
                item->setText("x");
                item->setBackground(Qt::lightGray);
            }
        }
    }
}

//update to reflect the current state of the game
void Game::updateStatus() {
    movesLabel->setText(QString::number(movesLeft));
    if(isGameWon()){
        statusLabel->setText("player wins");
    }else{
        statusLabel->setText("in progress");
    }
}




