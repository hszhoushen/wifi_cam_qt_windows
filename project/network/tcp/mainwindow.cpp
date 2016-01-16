#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->label->setText("wifi camera");

#if 0
    //this make exit code:255
    //why？
    connect(pushButton, SIGNAL(clicked()), this, SLOT(slotStart()));
    connect(close_serve_pbt, SIGNAL(clicked()), this, SLOT(slotStop()));
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotStart()
{

}

void MainWindow::slotStop()
{
    threadone.terminate();
    threadone.wait();
}

//显示图片
void MainWindow::display_img()
{
    QString filename;
    filename=QFileDialog::getOpenFileName(this,
                                          tr("选择图像"),
                                          "",
                                          tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(filename.isEmpty())
    {
         return;
    }
    else
    {
        QImage* img=new QImage;

        if(! ( img->load(filename) ) ) //加载图像
        {
            QMessageBox::information(this,
                                     tr("打开图像失败"),
                                     tr("打开图像失败!"));
            delete img;
            return;
        }
        ui->label->setPixmap(QPixmap::fromImage(*img));
    }

}


//开启服务器
void MainWindow::on_pushButton_clicked()
{
    threadone.start();
}

//显示图片
void MainWindow::on_disp_img_clicked()
{
    display_img();
}

//关闭服务器
void MainWindow::on_close_serve_pbt_clicked()
{
    slotStop();
}
