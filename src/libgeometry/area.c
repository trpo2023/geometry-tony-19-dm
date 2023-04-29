#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <libgeometry/checkarg.h>

double calculateArea(char *str)
{
    if (checkArguments(str) == 3)
    {
        return -1;
    }

    size_t i = 0;
    char *temp = (char *)malloc(sizeof(char));
    for (i = 0; str[i] != ','; i++)
        ;
    i++;
    int index = 0;
    for (; i < strlen(str); i++)
    {
        temp[index++] = str[i];
        temp = (char *)realloc(temp, (index + 1) * sizeof(char));
    }
    double area = M_PI * atof(temp) * atof(temp);
    free(temp);
    return area;
}