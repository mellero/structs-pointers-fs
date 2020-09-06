// Completes challenge by passing entire array

/* Construct an array of structures
 * The array has 4 elements, each of which is a structure
 * Display the four structures
 * Swap two elements in the array
 * Display the four elements again
 */

/* Data:
 * George Washington, April 30, 1789
 * Thomas Jefferson, March 4, 1801
 * Abraham Lincoln, March 4, 1861
 * Theodore Roosevelt, September 14, 1901
 */

#include <stdio.h>

typedef struct date {
    int day;
    int month;
    int year;
} date;

typedef struct person {
    char name[32];
    date tookoffice;
} person;

void swap(person presidents[]); 
void display_person(person pres);
void display_presidents(person presidents[]);

int main() {
    person presidents[] = {
        { "George Washington", { 30, 4, 1789 } },
        { "Thomas Jefferson", { 4, 3, 1801 } },
        { "Abraham Lincoln", { 4, 3, 1861 } },
        { "Theodore Roosevelt", { 9, 14, 1901 } }
    }; 

    display_presidents(presidents);
    swap(presidents);
    display_presidents(presidents);

    return 0;
}

void swap(person presidents[]) {
    person temp;

    temp = presidents[1];
    presidents[1] = presidents[2];
    presidents[2] = temp;
}

void display_person(person pres) {
    printf("President %s took office on %d/%d/%d\n",
            pres.name,
            pres.tookoffice.day,
            pres.tookoffice.month,
            pres.tookoffice.year
        );
}

void display_presidents(person presidents[]) {
    puts("Presidents:");
    for (int i = 0; i < 4; i++) {
        display_person(presidents[i]);
    }
}