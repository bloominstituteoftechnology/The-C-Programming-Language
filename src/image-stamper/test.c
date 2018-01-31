#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct testStruct
{
    char *s;
};
void modifyStruct(struct testStruct ts)
{
    printf("modifyStruct %s\n", ts.s);
    strcat(ts.s, " World");
}

struct testStruct main()
{
    struct testStruct ts;
    ts.s = (char *)malloc(100);
    strcpy(ts.s,"Hello");
    printf("%s\n", ts.s);
    modifyStruct(ts);
    printf("%s\n", ts.s);
    free(ts.s);
    return ts;
}










/*

/hangman test
          
          
          
          
          
          
/*****\   

____

ABCDEFGHIJKLMNOPQRSTUVWXYZ


Enter your guess for the word or a guess for a character in the word
a
   +      
   |      
   |      
   |      
   |      
   |      
/*****\   

____

ABCDEFGHIJKLMNOPQRSTUVWXYZ


Enter your guess for the word or a guess for a character in the word
b
   +----  
   |      
   |      
   |      
   |      
   |      
/*****\   

____

ABCDEFGHIJKLMNOPQRSTUVWXYZ


Enter your guess for the word or a guess for a character in the word
t
   +----  
   |      
   |      
   |      
   |      
   |      
/*****\   

T__T

ABCDEFGHIJKLMNOPQRSTUVWXYZ


Enter your guess for the word or a guess for a character in the word
z
   +----  
   |   O  
   |      
   |      
   |      
   |      
/*****\   

T__T

ABCDEFGHIJKLMNOPQRSTUVWXYZ


Enter your guess for the word or a guess for a character in the word
e
   +----  
   |   O  
   |      
   |      
   |      
   |      
/*****\   

TE_T

ABCDEFGHIJKLMNOPQRSTUVWXYZ


Enter your guess for the word or a guess for a character in the word
s
   +----  
   |   O  
   |      
   |      
   |      
   |      
/*****\   

TEST

ABCDEFGHIJKLMNOPQRSTUVWXYZ


you won with word test


*/