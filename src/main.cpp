#include "mainwindow.h"
#include <QApplication>
#include "mpd_connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MPD::Connection Mpd;
    Mpd.connect();
    Mpd.play_next();

    return a.exec();
}
