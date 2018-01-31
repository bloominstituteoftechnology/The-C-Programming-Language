// pair programming with Mark Oliver, David Long, Joshua Hall 
// // #define debugging
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// #include <unistd.h>

// char HANG_STATES[7][10 * 9] =
//     {
//         "             +         +----     +----     +----     +----     +----     +----     +----  ",
//         "             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
//         "             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
//         "             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
//         "             |         |         |         |         |         |         |  /      |  / \\ ",
//         "             |         |         |         |         |         |         |         |      ",
//         "/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

// #ifdef debugging
// FILE *f;
// #endif
// int showLetters(char *good, char *bad)
// {
//   char t[2] = {0, 0};
//   for (char c = 'A'; c <= 'Z'; c++)
//   {
//     t[0] = c;
//     const char *goodPtr = strstr(good, t);
//     const char *badPtr = strstr(bad, t);

//     if (goodPtr != NULL)
//       printf("\033[1;32m%c\033[0m", c);
//     else if (badPtr != NULL)
//       printf("\033[9;31m%c\033[0m", c);
//     else
//       printf("\033[0;37m%c\033[0m", c);
//   }
//   puts("\n\n");
//   return 0;
// }

// int hangMan(char *word)
// {
//   const int NC = 26;
//   const int MAX_WORD_LENGTH = 255;
//   int state = 0;
//   int L = strlen(word);
//   char *current = (char *)malloc(L + 1);
//   char *uword = (char *)malloc(L + 1);
//   for (int i = 0; i < L; i++)
//     uword[i] = toupper(word[i]);
//   uword[L] = 0;
//   memset(current, '_', L);
//   current[L] = 0;

//   char *bad = (char *)malloc(NC + 1);
//   *bad = 0;
//   char *good = (char *)malloc(NC + 1);
//   *good = 0;

//   char *buffer = (char *)malloc(MAX_WORD_LENGTH + 1);

//   size_t len = 255;
//   int done = 0;
//   char t[2] = {0, 0};
//   for (; state < 9; state++)
//   {
// #ifdef debugging
//     fprintf(f, "state: %d", state);
// #endif

//     for (int i = 0; i < 7; i++)
//     {
//       printf("%.*s\n", 10, (char *)HANG_STATES[i] + state * 10);
//     }
//     printf("\n%s\n\n", current);
//     showLetters(good, bad);
//     if (done > 0 || state == 8)
//     {
//       free(uword);
//       free(current);
//       free(bad);
//       free(buffer);
//       return (state == 8) ? 1 : 0;
//     }
//     puts("Enter your guess for the word or a guess for a character in the word");
//     getline(&buffer, &len, stdin);
//     int lB = strlen(buffer);
//     if (lB >= 2)
//     {
//       buffer[lB - 1] = 0;
//       lB--;
//     }
// #ifdef debugging
//     fprintf(f, "buffer length %d buffer %s \n", lB, buffer);
//     fflush(f);
// #endif
//     if (lB > 0)
//     {
//       if (lB == 1)
//       {
//         char c = toupper(*buffer);
//         t[0] = c;
//         if (strstr(good, t) != NULL)
//         {
//           printf("you already used %c\n", c);
//           continue;
//         }
//         if (strstr(bad, t) != NULL)
//         {
//           printf("you already tested %c, it isn't in word\n", c);
//           continue;
//         }
//         char *fo = strstr(uword, t);
// #ifdef debugging
//         fprintf(f, "lb is 1, fo: %s\n", fo);
//         fflush(f);
// #endif
//         if (fo == NULL)
//           strcat(bad, t);
//         else
//         {
//           strcat(good, t);
//           state--;
//           for (; *fo > 0; fo++)
//           {
//             if (*fo == c)
//               current[fo - uword] = c;
//           }
//           if (strncasecmp(current, word, L) == 0)
//           {
//             strcpy(current, uword);
//             done++;
//           }
//         }
//       }
//       else
//       {
// #ifdef debugging
//         fprintf(f, "lb > 1, buffer: %s uword: %s\n", buffer, uword);
// #endif
//         if (strncasecmp(buffer, word, L) == 0)
//         {
//           strcpy(current, uword);
//           done++;
//           state--;
//         }
//       }
//     }
//     else
//       state--;
//   }
//   return 1;
// }

// int main(int argc, char *argv[])
// {
// /* Your code here */
// #ifdef debugging
//   const char *logFile = 'hangman.log.text';
//   unlink(logFile);
//   f = fopen(logFile, "w");
//   if (f == NULL)
//   {
//     printf("Error opening file!\n");
//     exit(1);
//   }
// #endif
//   if (argc < 2)
//   {
//     printf("usage: hangman \"word\"\n ");
//     exit(1);
//   }
//   char *word = argv[1];
//   if (hangMan(word) == 0)
//     printf("you won with word '%s'\n", word);
//   else
//     printf("You are a big loser!!! :(\n");
// #ifdef debugging
//   fclose(f);
// #endif
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] =
	{
		"             +         +----     +----     +----     +----     +----     +----     +----  ",
		"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
		"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
		"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
		"             |         |         |         |         |         |         |  /      |  / \\ ",
		"             |         |         |         |         |         |         |         |      ",
		"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

/* Reads user input from stdin with the given prompt text */
static char *read_input(char *prompt)
{
	size_t s = 1;
	size_t r = 0;
	char *in = malloc(s * sizeof(char));
	int c;
	printf("%s", prompt);
	while ((c = fgetc(stdin)) != EOF)
	{
		if ((char)c == '\n')
			break;
		if (r == s)
		{
			s *= 2;
			in = realloc(in, s * sizeof(char));
		}
		in[r++] = (char)c;
	}
	in = realloc(in, (strlen(in) + 1) * sizeof(char));
	in[r] = '\0';
	return in;
}

/* Returns 0 (false) if str doesn't contain c, otherwise 1 (true) */
static int str_contains(const char *str, char c)
{
	return (strchr(str, c) == NULL ? 0 : 1);
}

static void print_ui(const char *word, const char *guessed, unsigned int hangman_state, unsigned int clear)
{
	size_t i = 0;

	/* If the clear flag is set, we clear the screen using ANSI escape codes.
	   Doesn't work in Windows */
	if (clear)
	{
		printf("\033[2J\033[1;1H");
		fflush(stdout);
	}

	/* Print current hangman state */
	for (i = 0; i < 7; i++)
	{
		printf("%.10s\n", &HANG_STATES[i][hangman_state * 10]);
	}
	printf("\n");

	/* Print guessed letters */
	for (i = 0; i < strlen(word); i++)
	{
		if (i > 0)
			printf(" ");
		if (str_contains(guessed, word[i]))
		{
			printf("%c", word[i]);
		}
		else
		{
			printf("_");
		}
	}
	printf("\n\nWrong guesses:\n  ");

	/* Find and print missed letters */
	for (i = 0; i < strlen(guessed); i++)
	{
		if (!str_contains(word, guessed[i]))
		{
			if (i > 0)
				printf(" ");
			printf("%c", guessed[i]);
		}
	}
	printf("\n\n");
}

int main(int argc, char *argv[])
{

	char *word = NULL;
	char *guessed = NULL;
	char *guess = NULL;
	unsigned int guesses = 0;
	unsigned int hangman_state = 0;
	unsigned int clear = 0;
	size_t i = 0;
	size_t a = 0;

	if (argc == 1)
	{
		printf("Usage: %s [-c] word\n", argv[0]);
		return 1;
	}

	if (argv[1][0] == '-')
	{
		if (argv[1][1] == 'c')
		{
			/* "Clear screen"-flag */
			clear = 1; /* True */
		}
		word = argv[2];
	}
	else
	{
		word = argv[1];
	}
	guessed = calloc(strlen(word) + 1, sizeof(char));

	/* Print some nice graphics */
	printf("####################\n");
	printf("#    Hangman (c)   #\n");
	printf("#  MannieJay 2018  #\n");
	printf("####################\n\n");

	while (1)
	{

		/* Print the UI */
		print_ui(word, guessed, hangman_state, ((guesses == 0) ? 0 : clear));

		/* Read user input */
		guess = read_input("Guess a letter or a word (or 'exit'): ");

		/* If user wants to exit (input is "exit"), we quit */
		if (strcmp(guess, "exit") == 0)
			break;

		if (strlen(guess) > 1)
		{
			/* Word guess */
			if (strcmp(guess, word) == 0)
			{
				/* Correct!
				   Player wins */
				printf("You guessed the whole word! You win!\n");
				free(guess);
				break;
			}
			else
			{
				/* Not correct */
				/* TODO: Add strings to guessed (change guessed to be a pointer array) */
				printf("Nope!\n");
				hangman_state++;
			}
		}
		else
		{
			/* Letter guess */
			guessed[guesses++] = guess[0];
			if (str_contains(word, guessed[guesses - 1]))
			{
				/* Correct guess */
				/* Check if we have the whole word */
				for (i = 0, a = 0; i < strlen(word); i++)
				{
					if (str_contains(guessed, word[i]))
						a++;
				}
				if (a == strlen(word))
				{
					/* We got the whole word! */
					/* Player wins! */
					print_ui(word, guessed, hangman_state, clear);
					printf("Correct! You win!\n");
					free(guess);
					break;
				}
			}
			else
			{
				/* Failed guess */
				printf("Nope!\n");
				hangman_state++;
			}
		}

		if (hangman_state == 8)
		{
			/* Hangman complete, player loses! */
			print_ui(word, guessed, hangman_state, clear);
			printf("You lost! The correct word was \"%s\"!\n", word);
			free(guess);
			break;
		}

		free(guess);
		printf("\n");
	}

	free(guessed);

	printf("See ya!\n");

	return 0;
}