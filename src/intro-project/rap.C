#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// `WHERE` is essentially a constant
#define WHERE "Where is my Lambda swag?"

// A struct is basically a set of values that we want associated together in
// order to represent some larger type
//
// Here, this struct called `helloArray` holds a character array called
// `sentence` that has been allocated 59 bytes of memory
typedef struct {
  char sentence[59];
} helloArray;

// An enum is much like a struct, except it is typically used to enforce that
// one and only one state is active any any given moment. 
//
// This enum represents all of a data packet's possible types, which will always
// be either a TCP packet, an IP packet, or a UDP packet. 
typedef enum {
  TCP,
  IP,
  UDP
} PACKET_TYPE;

// Another struct declaration. This one has a few more fields associated with
// it, all of them characters except for the third one
//
// The `char*` indicates the type of this field to be a pointer to a memory
// location that is holding characters. The pointer itself
//
// is called `packetPayload`. We'll talk about pointers a bit more in another
// file. 
struct dataPacket {
  char packetType;
  char packetDataLength;
  char* packetPayload;
};

int main(int argc, char** argv) {
  helloArray test;

  // look up the strcpy function 
  strcpy( test.sentence, WHERE );
  printf( "%s\n", test.sentence );

  strcpy( test.sentence, WHERE );
  printf( "%s\n", test.sentence );

  dataPacket outbound;
  outbound.packetType = TCP;
  outbound.packetDataLength = strlen(WHERE);

  // The follwoing lines are bad. WHY?
  outbound.packetPayload[0] = 'a';
  strcpy( outbound.packetPayload, WHERE );

  // look up the malloc function 
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

  // It is undefined behavior to read or write memory after it has been freed.
  // Don't do it.
}

// Try to compile this program. You'll get many errors. Try to fix them and have
// your program compile without error messages.
//
// Hint: The fix is simple and has to do with the `dataPacket` struct
// definition. Also, look up the `typedef` keyword.
