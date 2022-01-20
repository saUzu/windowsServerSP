#pragma once
#include "main.h"

#define VERSION MAKEWORD(2,2)

int8_t hata_y;

int8_t wsaAtama(WSADATA *wsa) 
{
	printf_s(" -> Winsock atamasi yapiliyor...\n");
	if (WSAStartup(VERSION, wsa) != 0)
	{
		printf_s("WSAStartup() basarili olmadi.\n");
		return -1;
	}
	printf_s("\t-> WSAStartup() basarili oldu.\n");
	return 0;
}

int8_t soketAtama(SOCKET *soket)
{
	if ((*soket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf_s(" -> soket acilamadi.\tHata: %d\n", WSAGetLastError());
		return -1;
	}
	printf_s(" -> soket olusturuldu.\n");
	return 0;
}

void sunucuAtama(struct sockaddr_in* sunucu)
{
	sunucu->sin_addr.S_un.S_addr = INADDR_ANY;
	sunucu->sin_family = AF_INET;
	sunucu->sin_port = htons(5555);
}

MAIN ilkAtama(void)
{
	MAIN main;
	if (!(main = calloc(1, sizeof * main)))
	{
		perror("MAIN icin gerekli alan ayrilamadi.\tHata: ");
		return NULL;
	}
	if (wsaAtama(&(main->wsa)) == -1)
		return NULL;
	if (soketAtama(&(main->soket)) == -1)
		return NULL;
	sunucuAtama(&(main->sunucu));
	return main;
}