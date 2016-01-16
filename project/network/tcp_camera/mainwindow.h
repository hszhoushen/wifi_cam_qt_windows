#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread.h"

extern int tcp_get_data();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void dis_img(QPixmap pix);
    
private slots:

    void on_connect_server_clicked();

private:
    Ui::MainWindow *ui;
    Thread threadone;
};

#endif // MAINWINDOW_H
