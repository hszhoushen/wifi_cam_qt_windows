#include <QCoreApplication>

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define port "10086"
void ErrorHandling(char * message);

int main(int argc, char ** argv)
{
    QCoreApplication a(argc, argv);


    WSADATA wsaData;
    SOCKET hServSock, hClntSock;
    SOCKADDR_IN servAddr, clntAddr;
    int szClntAddr;
    char message[]="hello world!";

    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        ErrorHandling("WSAStartup() error!");

    hServSock = socket(PF_INET, SOCK_STREAM, 0);
    if(hServSock == INVALID_SOCKET)
        ErrorHandling("socket() error!");

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(atoi(port));

    if(bind(hServSock, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
        ErrorHandling("bind() error");

    if(listen(hServSock, 5) == SOCKET_ERROR)
        ErrorHandling("listen() error)");

    szClntAddr = sizeof(clntAddr);
    hClntSock = accept(hServSock, (SOCKADDR *)&clntAddr, &szClntAddr);
    if(hClntSock == INVALID_SOCKET)
        ErrorHandling("accept() error");

    send(hClntSock, message, sizeof(message), 0);
    closesocket(hClntSock);
    closesocket(hServSock);
    WSACleanup();

    return a.exec();
}

void ErrorHandling(char * message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

