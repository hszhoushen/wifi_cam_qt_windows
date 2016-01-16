#ifndef TCP_H
#define TCP_H

#include "mainwindow.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#include <iostream>
#include <QByteArray>
#include <QPixmap>


#define port "10086"
extern SOCKET hsocket;
void ErrorHandling(char * message);
int tcp_connect();

int wsa_init();
int wsa_close();

#endif // TCP_H
