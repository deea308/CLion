
#include <QApplication>
#include "hangman.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    HangmanGame hangman;
    hangman.setWindowTitle("Hangman game");
    hangman.show();
    return app.exec();
}
