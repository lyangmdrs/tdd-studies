#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitpacks.h"

int split(void)
{
	char* data;
	char* buff;
	char* recv;

	data = malloc(DATA_SIZE * sizeof(char));
	
	if(NULL == data)
	{
		printf("Could not allocate memory!");
		exit(-1);
	}

	recv = malloc(DATA_SIZE * sizeof(char));

	if (NULL == recv)
	{
		printf("Could not allocate memory!");
		free(data);
		exit(-1);
	}

	buildMessage(data, DATA_SIZE);

	printf("Complete data: %s \nSize: %d\n\n", data, DATA_SIZE);

	buff = malloc(PACK_SIZE * sizeof(char));

	if (NULL == buff)
	{
		printf("Could not allocate memory!");
		free(data);
		free(recv);
		exit(-1);
	}

	for(int numPack = 0; numPack < DATA_SIZE; numPack = numPack + PACK_SIZE)
	{
		char* pack = data + numPack;

		memcpy(buff, pack, PACK_SIZE);

		printf("Buffer %d: %s\n", numPack, buff);

		memcpy(recv + numPack, buff, PACK_SIZE);
	}

	printf("Received: %s\n", recv);

	free(data);
	free(recv);
	free(buff);

	return 0;
}

void buildMessage(char* buffer, unsigned int bufferSize)
{
	memset(buffer, '\0', bufferSize);
	
	for(unsigned int i = 0; i < bufferSize; i++)
	{
		*(buffer + i) = 'A' + i;
	}
}
