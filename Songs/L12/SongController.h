//
// Created by Andreea on 6/4/2024.
//

#ifndef L11L12_SONGS_SONGCONTROLLER_H
#define L11L12_SONGS_SONGCONTROLLER_H
#include "Song.h"
#include<vector>
#include <QObject>

class SongController: public QObject {
    Q_OBJECT;
private:
    std::vector<Song> allSongs;
    std::vector<Song> playlist;
public:
    explicit SongController(QObject *parent = nullptr) : QObject(parent) {}
    void addSong(const Song song){
        allSongs.push_back(song);
        emit songsUpdated(); //notify the UI
    }
    void deleteSong(int index){
        if(index>0 && index<=allSongs.size()){
            allSongs.erase(allSongs.begin()+index);
            emit songsUpdated();//notify the user interface
        }
    }
    void addToPlaylist(int index){
        if(index>0 && index<=allSongs.size()){
            playlist.push_back(allSongs[index]);
            emit playlistUpdated();
        }
    }

    const std::vector<Song> getAllSongs(){
        return allSongs;
    }

    const std::vector<Song> getPlaylist(){
        return playlist;
    }

    signals:
    void songsUpdated();
    void playlistUpdated();
};


#endif //L11L12_SONGS_SONGCONTROLLER_H
