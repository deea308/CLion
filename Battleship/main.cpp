#include <QApplication>
#include <QPushButton>
#include "MainWindow.h"
#include "Game.h"
#include "Board.h"
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("Battleship game");
    window.show();

    return app.exec();
}
