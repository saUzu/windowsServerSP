#pragma once
#include "main.h"


void veriGonder(void)
{

	if (listen(mainStruct->soket, 3) == SOCKET_ERROR) 
	{
		printf_s("dinlenemde hata oldu.\tHata: %d", WSAGetLastError());
		return;
	}
	printf_s("- baglanti dinleniyor..");
	SOCKET baglananSoket;
	struct sockaddr_in baglanan;
	int32_t c = sizeof baglanan;


	while ((baglananSoket = accept(mainStruct->soket, (struct sockaddr*)&baglanan, &c)) != INVALID_SOCKET)
	{
		printf_s("\n -> baglanti oldu.\n");
		uint8_t* ileti = "Hooop! Naber?\nNeyse ben gittim..!\n";
		if (send(baglananSoket, ileti, strlen(ileti), 0) == SOCKET_ERROR)
		{
			printf_s(" -> Gondermede hata oldu.\tHata: %d\n", WSAGetLastError());
			return;
		}
		printf_s(" -> Veri gonderildi.\n");
	}
	if (baglananSoket == INVALID_SOCKET)
	{
		printf_s(" -> kabul edilemedi.\tHata: %d\n", WSAGetLastError());
		return;
	}
}