#include "tcp.h"

#include "mainwindow.h"


WSADATA wsaData;
SOCKET hsocket;


//wsa_init
int wsa_init()
{
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        ErrorHandling("WSAStartup() error!");
}

//wsa_close
int wsa_close()
{
    WSACleanup();
}

int tcp_connect()
{
    SOCKADDR_IN servAddr;

    hsocket = socket(PF_INET, SOCK_STREAM, 0);

    if(hsocket == INVALID_SOCKET)
        ErrorHandling("socket() error!");

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;

    servAddr.sin_addr.s_addr = inet_addr("192.168.1.161");
    servAddr.sin_port = htons(atoi(port));


    if(connect(hsocket, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        ErrorHandling("connect() error!");
}


void ErrorHandling(char * message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}


