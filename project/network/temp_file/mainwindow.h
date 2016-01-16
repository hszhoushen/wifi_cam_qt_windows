#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "thread.h"
#include <QPushButton>
#include <QMainWindow>
//add
#include <QtCore>
#define MAXSIZE 2




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    void display_img();

    ~MainWindow();
    
private slots:
    void slotStart();
    void slotStop();

    void on_pushButton_clicked();

    void on_disp_img_clicked();

    void on_close_serve_pbt_clicked();

private:
    Ui::MainWindow *ui;

    Thread threadone;

    QPushButton *close_serve_pbt;
    QPushButton *pushButton;
    QPushButton *disp_img;
};



#endif // MAINWINDOW_H
