#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <WS2tcpip.h>


#pragma comment(lib, "ws2_32.lib")


typedef struct Main {
	WSADATA wsa;
	SOCKET soket;
	struct sockaddr_in sunucu;
} * MAIN;

MAIN mainStruct;
int64_t genelHata;

MAIN ilkAtama(void);
void soketeBaglan(void);
void temizlik(void);
void veriGonder(void);