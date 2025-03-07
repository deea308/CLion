//
// Created by Andreea on 6/4/2024.
//

#include "Song.h"
#include <QString>
Song::Song(QString t, QString a, QString d, QString mP){
    title=t;
    artist=a;
    duration=d;
    mediaPath=mP;
}

QString Song::getTitle() const {
    return title;
}
