#include "tcp.h"
#include <iostream>
#include <QByteArray>
#include <QPixmap>
#include "mainwindow.h"

void tcp_init()
{
    WSADATA wsaData;
    SOCKET hServSock, hClntSock;
    SOCKADDR_IN servAddr, clntAddr;
    int szClntAddr;

    int count = 0;
    QPixmap pix;
    QByteArray aa ;

    char read_buf[4096];

    char  message[30] = "hello world";
    //版本初始化
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        ErrorHandling("WSAStartup() error!");

    //创建套接字，面向连接的套接字，速度慢，不丢失数据，按照顺序传输
    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if(hServSock == INVALID_SOCKET)
        ErrorHandling("socket() error!");

    //绑定端口
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(port));

    if(bind(hServSock, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        ErrorHandling("bind() error");

    //端口监听
    if(listen(hServSock, 5) == SOCKET_ERROR)
        ErrorHandling("listen() error)");

    //accept
    szClntAddr = sizeof(clntAddr);
    hClntSock = accept(hServSock, (SOCKADDR *)&clntAddr, &szClntAddr);
    if(hClntSock == INVALID_SOCKET)
        ErrorHandling("accept() error");

    //发送数据
    send(hClntSock, message, sizeof(message), 0);

#if 0
    //接收数据
    int rn = 0;
    //接受服务器的文件信号
    while((rn = recv(hClntSock, read_buf, sizeof(read_buf), 0)) > 0)
    {
        //累加count
        count += rn;
        //打印接收到的数据个数
        printf("recv number = %d\n", rn);
        //将数据追加到pix
        aa.append((char *)read_buf, rn);
        //数组清零，不然会有上次传入的没有清楚
        memset(read_buf, 0, sizeof(read_buf));
    }
    //实现了图片数据(包含头信息)向pix的传递
    pix.loadFromData(aa);
    //pix在label上的显示。
//    MainWindow::ui->label->setPixmap(pix);
#endif

    //关闭套接字
    closesocket(hClntSock);
    closesocket(hServSock);
    //注销WSA
    WSACleanup();
}

void ErrorHandling(char * message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
