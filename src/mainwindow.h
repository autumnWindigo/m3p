#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <qnamespace.h>
#include "mpd_connection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Example Key Press Event */
    void keyPressEvent(QKeyEvent *event) override
    {
        if(event->key() == Qt::Key_N) {
            MPD::Connection::instance()->play_next();
        }
    }

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

