#include "mainwindow.h"
#include <QApplication>
#include "library.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    MPD::Library lib;
    lib.load_library();
    cout << "-- Sorted by name --" << endl;
    lib.sort_by_title();
    lib.print();
    cout << "-- Sorted by release date --" << endl;
    lib.sort_by_date();
    lib.print();

//    M3P::Config conf;
  //  cout << conf.get().filename() << endl;

    return a.exec();
}
