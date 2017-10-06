/*
 * testing the use and abuse of C structs
 */
#include <string.h>
#include <stdio.h>

// plural
struct Structures {
  char firstName[50];
  char lastName[50];
  int id;
// singular
} structure;

int main() {

  struct Structures Struct1;
  struct Structures Struct2;

  strcpy(Struct1.firstName, "Patrick");
  strcpy(Struct1.lastName, "Kennedy");
  Struct1.id = 1234;

  strcpy(Struct2.firstName, "Abraham");
  strcpy(Struct2.lastName, "Lincoln");
  Struct2.id = 5678;


  printf("%s %s %d\n", Struct1.firstName, Struct1.lastName, Struct1.id);
  printf("%s %s %d\n", Struct2.firstName, Struct2.lastName, Struct2.id);

  return 0;
}
