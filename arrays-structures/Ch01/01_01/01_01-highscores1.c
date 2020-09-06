#include <stdio.h>

typedef unsigned int uint;

// Is using a define preprocessor as a constant the best way to keep and use the length of an array?
// What if the size is dynamically allocated? 
#define SIZE 5

int main()
{
	float highscore[SIZE] = {
		993.86, 682.01, 639.60, 310.45, 123.25
	};

	puts("Here are the high scores:");
	for (uint i = 0; i < SIZE; i++) 
	{
		printf("#1 %.2f\n", highscore[i]);
	}

	return(0);
}

