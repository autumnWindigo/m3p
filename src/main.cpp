#include "config.h"
#include "library.h"
#include "mainwindow.h"
#include "mpd/client.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    /* MPD::Library lib;
    lib.load_library();
    lib.sort_by_title();
    lib.print(); */

    M3P::Config conf;
    cout << conf.get().filename() << endl;

    return a.exec();
}
