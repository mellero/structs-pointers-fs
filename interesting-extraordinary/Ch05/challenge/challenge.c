// Initialization, 1-51, each must be unique
// Pull numbers, pull 6 numbers
// Sort winning number (lowest to highest)
// display

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 50
#define BALLS 6

int compare(const void *a, const void *b);
void print_numbers(int arr[], int size);
int is_drawn(int arr[], int size, int val);

int main()
{
    int drawn[BALLS];
    int num;
    
    srand( (unsigned)time(NULL) );

    // Pull the winning numbers
    for (int i = 0; i < BALLS; i++)
    {
        num = (rand() % RANGE) + 1;
        while ( is_drawn(drawn, BALLS, num) == 1 )
        {
            num = (rand() % RANGE) + 1;
        }
        drawn[i] = num;
    }

    // Sort the values
	qsort(drawn, BALLS, sizeof(int), compare);

    // Print the winning, sorted numbers
    print_numbers(drawn, BALLS);

    return 0;
}

// comparison function used by qsort
int compare(const void *a, const void *b)
{
	return( *(int *)a - *(int *)b);
}

void print_numbers(int arr[], int size)
{
    puts("The winning numbers are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }  
    puts(""); 
}

// Returns 1 if the number has been drawn, and 0 if it has not
int is_drawn(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return 1;
        }
    }
    return 0;
}