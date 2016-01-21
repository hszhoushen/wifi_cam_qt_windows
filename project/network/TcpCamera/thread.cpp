#include "thread.h"
#include <fstream>

Thread::Thread()
{
    tcp = new Tcp();
    tcp->wsaInit(10086,"192.168.1.161");
    tcp->tcpConnect();
}

Thread::Thread(int port, char * ip)
{
    tcp = new Tcp();
    tcp->wsaInit(port, ip);
    tcp->tcpConnect();
}

Thread::~Thread()
{
    tcp->wsaClose();
    disconnect_tcp();
    delete tcp;
}

void Thread::disconnect_tcp()
{
    closesocket(tcp->getSocket());
}

int Thread::tcpGetData()
{
    QByteArray pic;
    ofstream fout;          //create an ofstream object named fout

    //没加binary末尾多出"0d"
    fout.open("text.jpg", ios_base::binary);

    if(!fout.is_open())     //open attempt failed
    {
        cout << "file open failed" << endl;
        exit(1);
    }

    char message[30] = {0};
    char read_buf[4096] = {0};
    int count = 0;
    int strlen = 0;

    strlen = recv(tcp->getSocket(), message, sizeof(message)-1, 0);
    cout << "Message from server: " << message << endl;
    cout << count << endl;
    if(strlen == -1){
        ErrorHandling("recv() error!");
        exit(-1);
    }

    //接收数据
    int rn=0;
    //接受服务器的文件信号
    while((rn=recv(tcp->getSocket(),read_buf,sizeof(read_buf),0))>0)
    {
        //累加count
        count += rn;
        //将数据追加到pix
        pic.append(read_buf,rn);
        //数组清零，不然会有上次传入的没有清楚
        memset(read_buf,0,sizeof(read_buf));
    }

    fout.write(pic, count);
    fout.close();//close output connection to file

    emit dataUpdated(pic);

    return 0;
}


void Thread::run()
{ 
    tcpGetData();
}

