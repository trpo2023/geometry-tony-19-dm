#include <stdio.h>
#include <stdlib.h>
#include <libgeometry/vocabulary.h>
#include <libgeometry/chekarg.h>
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
    int Figures = 0;
    while (fgets(str1, SIZE, file))
    {
        Figures++;
        Errors(str1, Figures);
    }

    fclose(file);
    printf("\n");

    return 0;
}