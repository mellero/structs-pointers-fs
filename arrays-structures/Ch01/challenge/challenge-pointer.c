// Completes challenge by passing only pointers


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

void swap(person *p); 
void display_person(person *pres);
void display_presidents(person *p);

int main() {
    person presidents[] = {
        { "George Washington", { 30, 4, 1789 } },
        { "Thomas Jefferson", { 4, 3, 1801 } },
        { "Abraham Lincoln", { 4, 3, 1861 } },
        { "Theodore Roosevelt", { 9, 14, 1901 } }
    }; 

    // *p is equivalent to presidents anyway, but this makes an explicit pointer variable 
    // *p points to the address of the zeroth element of presidents:
    //      *p = presidents = &presidents[0]
    person *p = presidents;

    display_presidents(p);
    swap(p);
    display_presidents(p);

    return 0;
}

void swap(person *p) {
    person temp;

    temp = p[1];
    p[1] = p[2];
    p[2] = temp;
}

void display_person(person *pres) {
    printf("President %s took office on %d/%d/%d\n",
            pres->name,
            pres->tookoffice.day,
            pres->tookoffice.month,
            pres->tookoffice.year
        );
}

void display_presidents(person *p) {
    person *person_p;

    puts("Presidents:");

    // Receives the pointer to the array, and assigns the address of the current 
    // position of that pointer to person_p, in order to send a pointer of the current person
    // to display_person
    for (int i = 0; i < 4; i++) {
        person_p = &(p[i]);
        display_person(person_p);
    }

    // This can be done without using a person_p variable, and simply sending the address: &(p[i])
}