#pragma once 
#include "main.h"

void soketeBaglan(void)
{
	if (bind(mainStruct->soket, (struct sockaddr*)&(mainStruct->sunucu), sizeof mainStruct->sunucu) == SOCKET_ERROR) 
	{
		printf_s(" -> sokete baglanma hatasi.\tHata: %d", WSAGetLastError());
		return;
	}
	printf_s(" -> sokete baglanildi.\n");
}