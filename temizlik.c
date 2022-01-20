#pragma once
#include "main.h"


void temizlik(void)
{
	if (closesocket(mainStruct->soket) == SOCKET_ERROR)
		printf_s(" -> closesocket() basarisiz oldu.\tHata: %d\n", WSAGetLastError());
	else
		printf_s(" -> closesocket() basarili oldu.\n");

	if (WSACleanup() == SOCKET_ERROR)
		printf_s(" -> WSACleanup() basarisiz oldu.\n");
	else
		printf_s(" -> WSACleanup() basarili oldu.\n");

	free(mainStruct);
}