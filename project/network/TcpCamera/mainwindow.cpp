#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (!recvThread)    delete recvThread;
    delete ui;
}

void MainWindow::disImg(QPixmap pix)
{
   ui->label->setPixmap(pix);
}

void MainWindow::recvDataSlot(QByteArray aa)
{
    QPixmap pix;
    cout << "hello world" << endl;
    cout << aa.length() << endl;
    pix.loadFromData(aa);
    //disImg(pix);
    ui->label->setPixmap(pix);
}

void MainWindow::on_connect_server_clicked()
{
    //默认端口为10086
    recvThread = new Thread();
    //自定义端口
    //1 先获取文本框中的端口号
    //2 将QString 转为int
    //3 recvThread = new Thread(port);
    //绑定信号槽
    connect(recvThread,SIGNAL(dataUpdated(QByteArray)),this,SLOT(recvDataSlot(QByteArray)));
    //开启线程接收数据
    recvThread->start();
}

void MainWindow::on_close_connect_clicked()
{

}

void MainWindow::on_disp_img_clicked()
{

}
