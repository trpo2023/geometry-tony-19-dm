#include <string.h>
#include <libgeometry/vocabulary.h>

#define SIZE 100

int Figure(char *str)
{
    int ret = 1;
    char rec[SIZE];
    int u = strlen(str);
    for (int i = 0; i < u; i++)
    {
        if (str[i] != '(')
            rec[i] = str[i];
        else
            break;
    }
    char figure[] = "circle";
    if (strcmp(rec, figure) == 0)
    {
        ret = 0;
    }
    return ret;
}