//
// Created by Andreea on 6/3/2024.
//

#include "hangman.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QRandomGenerator>
# include <cstdlib>
#include <ctime>

HangmanGame::HangmanGame(QWidget *parent) : QWidget(parent), attempts(7){
    srand(time(nullptr));
    setUpUi();
    startNewGame();
}

void HangmanGame::setUpUi() {

    QVBoxLayout *mainLayout= new QVBoxLayout(this);
    QHBoxLayout *inputLayout= new QHBoxLayout();
    QVBoxLayout *statusLayout= new QVBoxLayout();

    wordLabel= new QLabel(this);
    guessButton= new QPushButton("Guess", this);
    guessInput= new QLineEdit(this);
    newGamebutton= new QPushButton("new game", this);
    attemptsLabel= new QLabel(this);
    statusLabel= new QLabel("keep guessing...", this);
    wrongGuessesList= new QListWidget(this);

    inputLayout->addWidget(new QLabel("enter letter", this));
    inputLayout->addWidget(guessInput);
    inputLayout->addWidget(guessButton);

    statusLayout->addWidget(attemptsLabel);
    statusLayout->addWidget(statusLabel);
    statusLayout->addWidget(new QLabel("wrong guesses: ", this));
    statusLayout->addWidget(wrongGuessesList);

    mainLayout->addWidget(wordLabel);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(statusLayout);
    mainLayout->addWidget(newGamebutton);

    connectSignals();
}

void HangmanGame::connectSignals() {
    connect(guessButton, &QPushButton::clicked,[this]() {this->guessLetter(); });
    connect(newGamebutton, &QPushButton::clicked, [this]() {this->startNewGame(); });

}

void HangmanGame::guessLetter() {
    QString input = guessInput->text().toUpper();
    if(input.isEmpty() || input.size()>1 ||!input[0].isLetter()){
        QMessageBox::warning(this, "Invalid input","please enter a single letter");
        return;
    }

    char guess= input[0].toLatin1();
    guessInput->clear();

    if(guessedLetters.contains(guess)){
        QMessageBox::warning(this,"ALready guessed", "You have alrady guessed this");
        return;
    }

    guessedLetters.insert(guess);

    if(currentWord.contains(guess)){
        for(int i=0;i<currentWord.size();i++){
            if(currentWord[i]==guess)
                displayWord[i*2]=guess;//i*2 bec displayword contains space between letters
        }
        wordLabel->setText(displayWord);

        if(!displayWord.contains("_")){
            statusLabel->setText("you won");
            guessButton->setEnabled(false);
        }
    }else{
        wrongGuessesList->addItem(input);
        attempts--;
        attemptsLabel->setText("Remaining attemps: "+ QString::number(attempts));

        if(attempts==0){
            statusLabel->setText("You lost, the word was: "+ currentWord);
            guessButton->setEnabled(false);
        }
    }
}

void HangmanGame::startNewGame() {
    const QStringList wordList={"APPLE", "BANANA", "ORANGE", "GRAPE", "PEACH", "CHERRY", "MELON", "KIWI", "TAYLOR","STRAWBERRY"};


    currentWord = wordList[std::rand() % wordList.size()];

    guessedLetters.clear();
    wrongGuessesList->clear();
    attempts=7;

    displayWord = QString(currentWord.size()*2-1, ' ');
    for (int i = 0; i < currentWord.size(); ++i) {
        displayWord[i * 2] = '_';
    }

    wordLabel->setText(displayWord);
    attemptsLabel->setText("remaining attemps: "+ QString::number(attempts));
    statusLabel->setText("keep guessing...");
    guessButton->setEnabled(true);

}


