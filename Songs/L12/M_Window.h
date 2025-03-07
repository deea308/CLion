//
// Created by Andreea on 6/5/2024.
//

#ifndef L11L12_SONGS_M_WINDOW_H
#define L11L12_SONGS_M_WINDOW_H
#include "Song.h"
#include "SongController.h"
#include<QWidget>
#include<QMainWindow>
#include<QLineEdit>
#include<QTableWidget>
#include<QListWidget>

class M_Window : public QMainWindow{
    Q_OBJECT
public:
    explicit M_Window(SongController  *controller, QWidget *parent= nullptr);
private:
    SongController* controller;
    QTableWidget* songTable;
    QListWidget* playlist;
    QLineEdit *titleEdit;
    QLineEdit *artistEdit;
    QLineEdit *durationEdit;
    QLineEdit *mediaPathEdit;

    QWidget *createLeftPanel();
    QWidget *createRightPanel();
    QWidget *createTextInputWithLabel(const char* name, QLineEdit **lineEdit);
    QWidget *createButtons();

private slots:
    void addSongs();
    void deleteSongs();
    void updatePlaylist();

};


#endif //L11L12_SONGS_M_WINDOW_H
