
#include <stdio.h>
#include <stdlib.h>

/***********************************************
 * This is Array Pointer Assignment Rapping 
 ***********************************************/
int* childOfMainWithAllocation() {
  // these are both 10 item integer arrays, why so obfuscated, C?
  int* integerPointer = malloc(10*sizeof(int));
  for(int i = 0 ; i < 10 ; ++i) {
    integerPointer[i] = i;
  }
  return integerPointer;
}
int* childOfMainWithoutAllocation() {
  int integerArray[10];
  for(int i = 0 ; i < 10 ; ++i) {
    integerArray[i] = i;
  }
  return &integerArray;
}
void doThePointerAssignmentTest() {
  // what's gonna happen?
  int* integerPointer = childOfMainWithAllocation();
  puts("I'm good");
  int sum = 0;
  for(int i = 0 ; i < 10 ; ++i) {
    printf("%d",integerPointer[i]);
    sum = sum + integerPointer[i];
  }
  printf("\n");
  printf("Sum: %d\n", sum);
  free(integerPointer);
  printf("\n");
  int* integerArray = childOfMainWithoutAllocation();
  puts("I'm bad");
  sum = 0;
  for(int i = 0 ; i < 10 ; ++i) {
    printf("%d",integerArray[i]);
    sum = sum + integerArray[i];
  }
  printf("\n");
  printf("Sum: %d\n", sum);
  printf("\n");
}

/***********************************************
 * This is struct Pointer Assignment Rapping 
 ***********************************************/
struct radDoublyLinkedList {
  struct radDoublyLinkedList* next;
  struct radDoublyLinkedList* last;
  int value;
} radDoublyLinkedList;
struct radDoublyLinkedList* doTheStructAssignmentTest() {
  struct radDoublyLinkedList* theList = malloc(sizeof(struct radDoublyLinkedList));
  theList->next = NULL;
  theList->last = NULL;
  theList->value = 5;
  return theList;
}
void radDoublyLinkedListAdd(struct radDoublyLinkedList* list, int value)
{
  struct radDoublyLinkedList* newItem = malloc(sizeof(radDoublyLinkedList));
  newItem->value = value;
  newItem->last = NULL;
  newItem->next = list->next;
  list = newItem;
}

/***********************************************
 * This is Array Pointer Assignment Rapping 
 ***********************************************/
int main(int argc, char** argv) {
  doThePointerAssignmentTest();
  struct radDoublyLinkedList* list = doTheStructAssignmentTest();
  while(list->next != NULL) {
    struct radDoublyLinkedList* freeItem = list;
    list = list->next;
    free(freeItem); 
  }
}

