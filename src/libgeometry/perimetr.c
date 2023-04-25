#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <libgeometry/perimetr.h>
#include <math.h>

#define pi 3.141592

float Perimetr(char* str)
{
    size_t i = 0;
    char* temp = (char*)malloc(sizeof(char));
    for (i = 0; str[i] != ','; i++)
        ;
    i++;
    int index = 0;
    for (; i < strlen(str); i++) {
        temp[index++] = str[i];
        temp = (char*)realloc(temp, (index + 1) * sizeof(char));
    }
    float perimetr = 2 * M_PI * atof(temp);
    free(temp);
    return perimetr;
}