#include <stdlib.h>
#include <string.h>
#include <libgeometry/area.h>

#define pi 3.141592

float Area(char *str)
{

    int i = 0;
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
    return pi * atof(temp) * atof(temp);
}