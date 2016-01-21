#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "thread.h"
#include "tcp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void disImg(QPixmap pix);

private slots:
    void on_connect_server_clicked();

    void on_close_connect_clicked();

    void on_disp_img_clicked();

protected slots:
    void recvDataSlot(QByteArray aa);

private:
    Ui::MainWindow *ui;
    Thread * recvThread;
};

#endif // MAINWINDOW_H
