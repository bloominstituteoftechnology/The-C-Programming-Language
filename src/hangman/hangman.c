#define debugging
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
// #define MIN(a, b) ((a) < (b) ? a : b)
const char HANG_STATES[7][10 * 9 + 1] =
	{
		"             +         +----     +----     +----     +----     +----     +----     +----  ",
		"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
		"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
		"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
		"             |         |         |         |         |         |         |  /      |  / \\ ",
		"             |         |         |         |         |         |         |         |      ",
		"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

#ifdef debugging
FILE *f;
#endif
int showLetters(char *good, char *bad)
{
	char t[2] = {0, 0};
	for (char c = 'A'; c <= 'Z'; c++)
	{
		t[0] = c;
		const char *goodPtr = strstr(good, t);
		const char *badPtr = strstr(bad, t);

		if (goodPtr != NULL)
			printf("\033[1;32m%c\033[0m", c); // green
		else if (badPtr != NULL)
			printf("\033[9;31m%c\033[0m", c); // red with strikethough
		else
			printf("\033[0;37m%c\033[0m", c); // grey
	}
	puts("\n\n");
	return 0;
}

int hangMan(char *word)
{
	const int NC = 26;
	const int MAX_WORD_LENGTH = 255;
	int state = 0;
	int L = strlen(word);
	char *current = (char *)malloc(L + 1);
	char *uword = (char *)malloc(L + 1);
	for (int i = 0; i < L; i++)
		uword[i] = toupper(word[i]);
	uword[L] = 0;
	memset(current, '_', L);
	current[L] = 0;

	char *bad = (char *)malloc(NC + 1);
	*bad = 0;
	char *good = (char *)malloc(NC + 1);
	*good = 0;

	char *buffer = (char *)malloc(MAX_WORD_LENGTH + 1);

	size_t len = 255;
	int done = 0;
	char t[2] = {0, 0};
	for (; state < 9; state++)
	{
#ifdef debugging
		fprintf(f, "state: %d", state);
#endif
		for (int i = 0; i < 7; i++)
		{
			// memcpy(dstate[i], HANG_STATES[i] +  state * 10, 10);
			printf("%.*s\n", 10, (char *)HANG_STATES[i] + state * 10);
		}
		printf("\n%s\n\n", current);
		showLetters(good, bad);
		if (done > 0 || state == 8)
		{
			free(uword);
			free(current);
			free(bad);
			free(buffer);
			return (state == 8) ? 1 : 0;
		}
		puts("Enter your guess for the word or a guess for a character in the word");
		getline(&buffer, &len, stdin);
		int lB = strlen(buffer);
		if (lB >= 2)
		{
			buffer[lB - 1] = 0;
			lB--;
		}
#ifdef debugging
		fprintf(f, "buffer length %d  buffer %s \n", lB, buffer);
		fflush(f);
#endif
		if (lB > 0)
		{
			if (lB == 1)
			{
				char c = toupper(*buffer);
				t[0] = c;
				if (strstr(good, t) != NULL)
				{
					printf("you already used %c", c);
					continue;
				}
				if (strstr(bad, t) != NULL)
				{
					printf("you already tested %c, it isn't in word", c);
					continue;
				}
				char *fo = strstr(uword, t);
#ifdef debugging
				fprintf(f, "lb is 1, fo: %s\n", fo);
				fflush(f);
#endif
				if (fo == NULL)
					strcat(bad, t);
				else
				{
					strcat(good, t);
					state--;
					for (; *fo > 0; fo++)
					{
						if (*fo == c)
							current[fo - uword] = c;
					}
					if (strncasecmp(current, word, L) == 0)
					{
						strcpy(current, uword);
						done++;
					}
				}
			}
			else
			{
#ifdef debugging
				fprintf(f, "lb > 1, buffer: %s  uword: %s\n", buffer, uword);
#endif
				if (strncasecmp(buffer, word, L) == 0)
				{
					strcpy(current, uword);
					done++;
					state--;
				}
			}
		}
		else
			state--;
	}
	return 1;
}
int main(int argc, char *argv[])
{
#ifdef debugging
	const char *logFile = "hangman.log.txt";
	unlink(logFile);
	f = fopen(logFile, "w");
	if (f == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}
#endif
	/* Your code here */
	if (argc < 2)
	{
		printf("usage: hangman \"word\"\n ");
		exit(1);
	}
	char *word = argv[1];
	if (hangMan(word) == 0)
		printf("you won with word '%s'\n", word);
	else
		printf("you lost\n");
#ifdef debugging
	fclose(f);
#endif
	return 0;
}