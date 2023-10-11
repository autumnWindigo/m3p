#include "library.h"
#include "mainwindow.h"
#include "mpd/client.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();
    MPD::Library lib;
    lib.load_library();
    lib.sort_by_title();
    lib.print();


    return a.exec();
}
