//
// Created by Andreea on 6/4/2024.
//

#ifndef L11L12_SONGS_SONG_H
#define L11L12_SONGS_SONG_H
#include <QString>

class Song {
public:
    QString title;
    QString artist;
    QString duration;
    QString mediaPath;

    Song(QString t, QString a, QString d,QString mP);
    QString getTitle() const;
};


#endif //L11L12_SONGS_SONG_H
