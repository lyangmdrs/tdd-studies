#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitpacks.h"

void splitMessage(const char* message, unsigned int length, unsigned int numPacket, char** output)
{
	unsigned int packetSize = length/numPacket;

	for (unsigned int packet = 0; packet < numPacket; packet++)
	{
		memmove(output[packet], (char *)message + packet * packetSize, packetSize * sizeof(char));
	}
}
