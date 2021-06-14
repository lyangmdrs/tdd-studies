#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitpacks.h"

void splitMessage(const char* message, unsigned int length, unsigned int numPakcs, char** output)
{
	unsigned int packetSize = length/numPakcs;

	for (unsigned int packet = 0; packet < numPakcs; packet++)
	{
		memmove(output[packet], (char *)message + packet * packetSize, packetSize * sizeof(char));
	}
}

void joinPackets(char** packets, unsigned int numPakcs, unsigned int packLength, char* output)
{
	memcpy(output, packets[0], packLength);
	
	for (unsigned int packet = 1; packet < numPakcs; packet++)
	{
		strcat(output, packets[packet]);
	}
}
