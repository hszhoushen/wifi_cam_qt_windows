#ifndef TCP_H
#define TCP_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

#define port "10086"
void ErrorHandling(char * message);
void tcp_init();

#endif // TCP_H
