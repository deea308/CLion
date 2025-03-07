//
// Created by Andreea on 6/5/2024.
//

#include "M_Window.h"
#include<QHBoxLayout>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>

M_Window::M_Window(SongController *controller, QWidget *parent): QMainWindow(parent),controller(controller) {
    QWidget *centralWidget= new QWidget(this);
    QHBoxLayout* hLay= new QHBoxLayout(centralWidget);

    hLay->addWidget(createLeftPanel());
    hLay->addWidget(new QPushButton(">"));
    hLay->addWidget(createRightPanel());

    setCentralWidget(centralWidget);
    setWindowTitle("Playlist qt");


    connect(controller, &SongController::songsUpdated, this, &M_Window::updatePlaylist);
    connect(controller, &SongController::playlistUpdated, this, &M_Window::updatePlaylist);
}

QWidget *M_Window::createLeftPanel() {
    QWidget* panel= new QWidget;
    QVBoxLayout* layout= new QVBoxLayout;//partea din st este aranjata pe vertical

    QLabel* label= new QLabel("songs");//nume la widget care va fi tabel
    layout->addWidget(label);

    songTable= new QTableWidget;//nou tabel
    QStringList header={"title","artist","durtion","path"};
    songTable->setColumnCount(header.count());
    songTable->setHorizontalHeaderLabels(header);//punem nume la coloane
    layout->addWidget(songTable);

    layout->addWidget(createTextInputWithLabel("title", &titleEdit));
    layout->addWidget(createTextInputWithLabel("artist",&artistEdit));
    layout->addWidget(createTextInputWithLabel("duration", &durationEdit));
    layout->addWidget(createTextInputWithLabel("path",&mediaPathEdit));

    layout->addWidget(createButtons());
    panel->setLayout(layout);
    return panel;
}

QWidget *M_Window::createRightPanel() {
    QWidget* panel= new QWidget;
    QVBoxLayout* layout= new QVBoxLayout;

    QLabel* label= new QLabel("PLAYLIST");//TITLE OF THE LIST
    layout->addWidget(label);

    playlist= new QListWidget();//CREATE THE PLAYLIST LIST WIDGET
    layout->addWidget(playlist);

    QPushButton* playButton= new QPushButton("play");
    layout->addWidget(playButton);

    QPushButton* nextBUtton= new QPushButton("next");
    layout->addWidget(nextBUtton);

    panel->setLayout(layout);
    return panel;
}

QWidget *M_Window::createTextInputWithLabel(const char *name, QLineEdit **lineEdit) {
    QWidget* panel= new QWidget;
    QHBoxLayout* layout= new QHBoxLayout;

    QLabel* label = new QLabel(name);
    layout->addWidget(label);

    QLineEdit* input= new QLineEdit;
    layout->addWidget(input);

    //*lineEdit=input;

    panel->setLayout(layout);
    return panel;
}

QWidget *M_Window::createButtons() {
    QWidget* panel= new QWidget;
    QHBoxLayout* layout= new QHBoxLayout;

    QPushButton *addButton= new QPushButton("add");
    QPushButton *deleteButton= new QPushButton("delete");
    QPushButton *updateButton= new QPushButton("update");
    QPushButton *filterButton= new QPushButton("filter");

    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    layout->addWidget(updateButton);
    layout->addWidget(filterButton);

    connect(addButton, &QPushButton::clicked, this, &M_Window::addSongs);
    connect(deleteButton, &QPushButton::clicked, this, &M_Window::deleteSongs);

    panel->setLayout(layout);
    return panel;

}

void M_Window::addSongs() {
    QString title= titleEdit->text();
    QString artist= artistEdit->text();
    QString duration= durationEdit->text();
    QString mediaPath= mediaPathEdit->text();

    if (!title.isEmpty() && !artist.isEmpty() && !duration.isEmpty() && !mediaPath.isEmpty()) {
        Song song(title, artist, duration, mediaPath);
        controller->addSong(song);
    }
}

void M_Window::deleteSongs() {
    int row=songTable->currentRow();
    if(row>0)
        controller->deleteSong(row);
}

void M_Window::updatePlaylist() {
    playlist->clear();
    const std::vector<Song> &songs= controller->getPlaylist();
    for(const auto &song: songs)
        playlist->addItem(song.getTitle());
}





