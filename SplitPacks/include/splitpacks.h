#ifndef SPLITPACKS_H
#define SPLITPACKS_H

#define DATA_SIZE 24
#define PACK_SIZE 3

void splitMessage(const char* message, unsigned int length, 
                  unsigned int numPacket, char** output);

void joinPackets(char** packets, unsigned int numPakcs, 
                 unsigned int packLength, char* output);

#endif