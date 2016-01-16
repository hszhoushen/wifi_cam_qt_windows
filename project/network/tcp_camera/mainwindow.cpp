#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcp.h"


int tcp_get_data()
{
    QPixmap pix;
    QByteArray aa ;

    char message[30] = {0};
    char read_buf[4096] = {0};
    int count = 0;
    int strlen = 0;

    strlen = recv(hsocket, message, sizeof(message)-1, 0);
    if(strlen == -1)
        ErrorHandling("recv() error!");

    //接收数据
    int rn=0;
    //接受服务器的文件信号
    while((rn=recv(hsocket,read_buf,sizeof(read_buf),0))>0)
    {
        //累加count
        count+=rn;
        //打印接收到的数据个数
        printf("recvnumber=%d\n",rn);
        //将数据追加到pix
        aa.append((char*)read_buf,rn);
        //数组清零，不然会有上次传入的没有清楚
        memset(read_buf,0,sizeof(read_buf));
    }
    //实现了图片数据(包含头信息)向pix的传递
    pix.loadFromData(aa);

    //pix在label上的显示。
//    Ui::MainWindow.label->setPixmap(pix);
//    dis_img(pix);

    std::cout << "Message from server: " << message << std::endl;

    closesocket(hsocket);

    return 0;


}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wsa_init();
    tcp_connect();
}

MainWindow::~MainWindow()
{
    wsa_close();
    delete ui;
}

void MainWindow:: dis_img(QPixmap pix)
{
   ui->label->setPixmap(pix);
}

void MainWindow::on_connect_server_clicked()
{
    threadone.start();
}
