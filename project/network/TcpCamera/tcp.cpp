#include "tcp.h"

Tcp::Tcp()
{

}

Tcp::~Tcp()
{

}

int Tcp::tcpConnect()
{
    SOCKADDR_IN servAddr;

    hsocket = socket(PF_INET, SOCK_STREAM, 0);

    if(hsocket == INVALID_SOCKET){
        ErrorHandling("socket() error!");
        exit(-1);
    }

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;

    servAddr.sin_addr.s_addr = inet_addr(ip);
    servAddr.sin_port = htons(port);


    if(connect(hsocket, (SOCKADDR *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR){
        ErrorHandling("connect() error!");
        exit(-1);
    }
}

int Tcp::wsaInit(int port,char * ip)
{    
    this->port = port;
    strcpy(this->ip, ip);
    if(WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
        ErrorHandling("WSAStartup() error!");
        exit(-1);
    }
}

SOCKET Tcp::getSocket()
{
    return hsocket;
}

int Tcp::wsaClose()
{
    WSACleanup();
}
