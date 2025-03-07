#include <QApplication>
#include "M_Window.h"
#include "SongController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SongController controller;
    M_Window mainWindow(&controller);
    mainWindow.show();

    return app.exec();
}