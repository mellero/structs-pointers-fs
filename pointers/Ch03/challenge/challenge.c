// Create array of 10 char *
// Prompt user for input 
// Assign each input to an address stored in the array
// Display the 10 strings input

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allocates a char * of size size.
char * allocate(size_t size);

int main() 
{
    char * arr[10]; // Output array
    char buffer[32]; // Input buffer

    for (int i = 0; i < 10; i++)
    {
        printf("Please input string %d\n", i+1);
        scanf("%s", buffer);

        // Get the size of the input string
        size_t length = strlen(buffer);

        // Allocate enough memory and retrieve pointer
        char *p = allocate(length);

        // Copy input string to output location
        strcpy(p, buffer);

        // Place the output pointer in the output array
        arr[i] = p;
    }

    puts("OUTPUT: -------------------------");
    for (int i = 0; i < 10; i++) 
    {
        printf("%d: %s\n", (i+1), *(arr+i));
    }

    return 0;
}

char * allocate(size_t size)
{
    char *p;
    // Size + 1 for null character
    p = (char *)malloc(sizeof(char) * (size + 1));
    if( p == NULL )
	{
		puts("Unable to allocate memory");
		exit(1);
	}
    return p;
} 