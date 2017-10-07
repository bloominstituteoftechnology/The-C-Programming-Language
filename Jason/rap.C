
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WHERE "Where is my Lambda swag?"

struct helloArray {
  char sentence[59];
};

typedef enum {
  TCP,
  IP,
  UDP
} PACKET_TYPE;

struct dataPacket {
  char packetType;
  char packetDataLength;
  char* packetPayload;
};

int main(int argc, char** argv) {
  helloArray test;
  strcpy( test.sentence, WHERE );
  printf( "%s\n", test.sentence );
  strcpy( test.sentence, WHERE );
  printf( "%s\n", test.sentence );

  dataPacket outbound;
  outbound.packetType = TCP;
  outbound.packetDataLength = strlen(WHERE);
  // nothing happens here, C lets us write to unallocated memory, but it
  // isn't stored because the OS isn't actually writing it.
  outbound.packetPayload[0] = 'a';
  strcpy( outbound.packetPayload, WHERE );

  // allocate enough memory for "Where is my Lambda swag?"
  outbound.packetPayload = (char*)malloc(strlen(WHERE));
  // now when we try to write the data, the changes stick
  strcpy( outbound.packetPayload, WHERE );
  outbound.packetPayload[0] = 'a';
  // this is what the developer might use this for
  //protocol_send(outbound);

  printf( "Hey dude: %p %d\n", outbound.packetPayload, 5 );
  puts( (outbound.packetPayload) );
  printf( "%lu\n", strlen(outbound.packetPayload) );

  free(outbound.packetPayload);
 
  // The memory is still here! This is a safety violation. 
  puts( (outbound.packetPayload) );

  // can we change it?
  outbound.packetPayload[0] = 'f';
  puts( (outbound.packetPayload) );

  // we can! This is a terrible error waiting to happen
}

