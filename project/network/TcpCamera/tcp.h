#ifndef TCP_H
#define TCP_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#include <iostream>
#include <QByteArray>
#include <QPixmap>

#include "log.h"

using namespace std;

class Tcp
{
public:
    Tcp();
    ~Tcp();
public:
    //void errorHandling(char * message);
    int tcpConnect();
    int wsaInit(int port, char * ip);
    SOCKET getSocket();
    int wsaClose();
private:
    int port;
    char ip[30];
    WSADATA wsaData;
    SOCKET hsocket;
};

#endif // TCP_H
