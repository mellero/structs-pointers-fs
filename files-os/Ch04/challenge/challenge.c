// Prompt user for pathname (strip \n)
// Open that dir and read its files (chdir() returns 0)
// Output the filenames to filelist.txt (must be in samed dir as program)

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define SIZE 512

int main() 
{
    DIR *directory; // For opendir(char *) function
	struct dirent *file; // For readdir(DIR *) function
    FILE *outputFile;
    char cwd[SIZE];
    char outFileName[512];
    char pathname[SIZE]; // Path to be input from user

    // Get input and strip newline
    puts("Please enter a pathname to read from: ");
    if ( fgets(pathname, SIZE, stdin) != NULL )
    {
        size_t len = strlen(pathname);
        if (len > 0 && pathname[len-1] == '\n')
        {
            pathname[len-1] = '\0';
        }
    }

    // Use the cwd to create an absolute path to filelist.txt
    getcwd(cwd, SIZE);
    strcpy(outFileName, cwd);
    strcat(outFileName, "/filelist.txt");
    
    // Change CWD to pathname
    if ( chdir(pathname) != 0 )
    {
        printf("Could not find directory \"%s\"\n", pathname);
        return 1;
    }

    // Open directory "."
    directory = opendir(".");
    if (directory == NULL)
    {
        puts("Unable to open current directory");
        return 1;
    }

    // Open output file
    outputFile = fopen(outFileName, "w");
    if (outputFile == NULL)
    {
        puts("Failed to open output file");
        return (1);
    }

    // Read from cwd and output to file
    printf("Reading from directory: %s\n",pathname);
    while ( (file = readdir(directory)) != NULL)
    {
        fputs(file->d_name, outputFile);
        fputc('\n', outputFile);
    }

    closedir(directory);
    fclose(outputFile);

	return(0);
}
