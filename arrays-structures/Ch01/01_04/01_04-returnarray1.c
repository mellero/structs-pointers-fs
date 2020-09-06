#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *makearray(void)
{

	// int array[5] :: this will not work as memory is freed from the stack once this function is returned. As such, this variable will not be securely pointing at
					// what you think it is pointing at
	
	// Using static will work as static local variables keep their memory cell throughout all program execution. 
	static int array[5]; 

	int x;

	for(x = 0 ; x < 5; x++)
		array[x] = rand() % 10 + 1;

	// return(array); This line will not work if the signature is not "int *makearray", as you cannot return an entire array from a function
	/* You must return either: 
		* the values individually (eg: calling a function many times that returns single elements)
		* a pointer to the array
	*/

	return array;
}

int main()
{
	int x;
	int *p;

	srand( (unsigned)time(NULL) );
	puts("Here are your 5 random numbers:");
	p = makearray();

	for(x = 0; x < 5; x++)
		printf("%d\n", p[x]);

	return(0);
}


	
