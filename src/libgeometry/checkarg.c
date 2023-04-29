#include <stdio.h>
#include <string.h>

int checkArguments(char *str)
{
    int count = 0;
    for (size_t i = 7; str[i] != ',' && i < strlen(str); i++)
    {
        if ((str[i] != '.' && str[i] != ' ') && !(str[i] >= 48 && str[i] <= 57))
        {
            return 2;
        }
        if (str[i] >= 48 && str[i] <= 57 && str[i + 1] == ' ')
            count++;
        if (str[i] == '.' && str[i + 1] == ')')
            count += 2;
    }

    if (count + 1 != 2)
    {
        return 2;
    }

    size_t index = 0;
    for (size_t i = 0; i != strlen(str); i++)
    {
        if (str[i] == ',')
        {
            index = i + 1;
            i = strlen(str) - 1;
        }
    }

    for (; str[index] != ')' && index < strlen(str); index++)
    {
        if ((str[index] != '.' && str[index] != ' ') && !(str[index] >= 48 && str[index] <= 57))
        {
            return 3;
        }
        if (str[index] >= 48 && str[index] <= 57 && str[index + 1] == ' ')
            count++;
        if (str[index] == '.' && str[index + 1] == ' ')
            count += 2;
    }

    if (count != 1)
    {
        return 3;
    }
    return 0;
}

int checkEnd(char *str)
{
    if (str[strlen(str) - 3] != ')')
    {
        return 4;
    }

    else if (strlen(str) + 3 < (strlen(str)))
    {
        return 5;
    }
    return 0;
}