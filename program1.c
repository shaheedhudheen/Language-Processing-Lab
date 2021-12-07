//write a program to conut the number of lines characters and words from an input file

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int characters=0, words=0, lines=0;


  
    printf("Enter source file path: ");
    scanf("%s", path);

   
    file = fopen(path, "r");


    if (file == NULL)
    {
        printf("\nUnable to open file.\n");

        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(file)) != EOF)
    {
        characters++;

        if (ch == '\n' || ch == '\0')
            lines++;

        
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }

    if (characters > 0)
    {
        words++;
        lines++;
    }

    printf("\n Total characters = %d\n", characters);
    printf("Total words      = %d\n", words);
    printf("Total lines      = %d\n", lines);

    fclose(file);

    return 0;
}