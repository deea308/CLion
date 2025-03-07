//
// Created by Andreea on 6/3/2024.
//


#ifndef HANGMAN_HANGMAN_H
#define HANGMAN_HANGMAN_H

#include <QLabel>
#include <QLineEdit>
#include<QPushButton>
#include<QListWidget>
#include<QSet>
#include<QStringList>
#include <QMainWindow>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime>   // for std::time()

class HangmanGame: public QWidget{
    Q_OBJECT
private:
    QLabel  *wordLabel;
    QLineEdit *guessInput;
    QPushButton *guessButton;
    QPushButton *newGamebutton;
    QLabel *attemptsLabel;
    QLabel *statusLabel;
    QListWidget *wrongGuessesList;

    QString currentWord;
    QString displayWord;
    QSet<char> guessedLetters;
    int attempts;

    void setUpUi();
    void connectSignals();
    void guessLetter();
    void startNewGame();
public:
    explicit HangmanGame(QWidget *parent= nullptr);

};


#endif //HANGMAN_HANGMAN_H
