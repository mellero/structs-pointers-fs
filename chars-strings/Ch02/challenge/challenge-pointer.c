// 3 Parts
// Fetch string input from user
    // Prompt for name
    // loop to process single-char input storing in a buffer called name[]
    // buffer can hold up to 32 chars (making own text input fnc)
// Process input and string literal to generate a phrase
    // Copy input name[] into the buffer[]
    // Append text from the last[] array into buffer
    // The last[] array contains the string literal "passed the challenge"
// Output the phrase
    // Output char array buffer[]
    // Dont use puts() or printf()
    // Use putchar() fn

#include <stdio.h>
#include <string.h>

void print(char * p);

int main() 
{
    const int length = 32;
    char name[length];
    char * name_pointer = name;

    char buffer[64];
    char last[] = "passed the challenge";
    char ch;

    print("What is your name? ");

    while( (ch = getchar()) != '\n' ) 
    {
        *name_pointer++ = ch;

        // Check for overflow
        if (name_pointer == &name[length-2]) 
        {
            break;
        }
    }
    // End input with \0
    *name_pointer = '\0';

    // Part 2: Process
    strcpy(buffer, name);
    strcat(buffer, " ");
    strcat(buffer, last);

    // Part 3: Output
    print(buffer);
    putchar('\n');

    return 0;
}

void print(char * p) {
    while ( putchar(*p++))
    {
    }
}