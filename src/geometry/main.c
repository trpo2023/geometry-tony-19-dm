#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/intersection.h>
#include <libgeometry/memory.h>
#include <libgeometry/output.h>

#define SIZE 100

int main()
{
    FILE *file;
    file = fopen("tesedata.txt", "r");
    if (file == NULL)
    {
        printf("Error of oppening file!");
        return 1;
    }
    char *line = (char *)malloc(SIZE * sizeof(char));
    char **lines = (char **)malloc(sizeof(char *));
    int row = 1, num = 1;
    while (fgets(line, SIZE, file))
    {
        int check = isCircle(line);
        if (!check)
        {
            lines = (char **)realloc(lines, row * sizeof(char *));
            lines[row - 1] = (char *)malloc(strlen(line) * sizeof(char));
            strcpy(lines[row - 1], line);
            row++;
        }
        else
        {
            printError(line, check, num++);
        }
    }
    fclose(file);

    printf("\n\nCorrect figures in WKT format:");
    intersections(lines, row - 1);

    freeMemForStr(lines, row - 1);
    free(line);
    printf("\n");
    return 0;
}