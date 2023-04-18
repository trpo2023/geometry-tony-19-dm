#include <stdio.h>
#include <stdlib.h>
#include <libgeometry/vocabulary.h>
#include <libgeometry/checkarg.h>
#include <libgeometry/perimetr.h>
#include <libgeometry/area.h>

#define SIZE 100

int main()
{
    FILE *file;
    file = fopen("testdata.txt", "r");
    if (file == NULL)
    {
        printf("Error of oppening file!");
        return 1;
    }
    char str1[SIZE];
    int countFigures = 0;
    while (fgets(str1, SIZE, file))
    {
        countFigures++;
        Errors(str1, countFigures);
    }

    fclose(file);
    printf("\n");
    return 0;
}