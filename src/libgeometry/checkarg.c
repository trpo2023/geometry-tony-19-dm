#include <stdio.h>
#include <string.h>

#include <libgeometry/area.h>
#include <libgeometry/checkarg.h>
#include <libgeometry/perimetr.h>
#include <libgeometry/vocabulary.h>
int Argument(char* str)
{
    int ret = 0;
    int count = 0;
    for (size_t i = 7; str[i] != ',' && i < strlen(str); i++) {
        if ((str[i] != '.' && str[i] != ' ')
            && !(str[i] >= 48 && str[i] <= 57)) {
            printf("Figure coordinates entered incorrectly\n\n");
            ret++;
            return 1;
        }
        if (str[i] >= 48 && str[i] <= 57 && str[i + 1] == ' ')
            count++;
        if (str[i] == '.' && str[i + 1] == ')')
            count += 2;
    }
    if (count + 1 != 2) {
        printf("Figure coordinates entered incorrectly\n\n");
        ret++;
        return ret;
    }
    size_t index = 0;
    for (size_t i = 0; i != strlen(str); i++) {
        if (str[i] == ',') {
            index = i + 1;
            i = strlen(str) - 1;
        }
    }
    for (; str[index] != ')' && index < strlen(str); index++) {
        if ((str[index] != '.' && str[index] != ' ')
            && !(str[index] >= 48 && str[index] <= 57)) {
            printf("Figure radius entered incorrectly\n\n");
            ret++;
            return 1;
        }
        if (str[index] >= 48 && str[index] <= 57 && str[index + 1] == ' ')
            count++;
        if (str[index] == '.' && str[index + 1] == ' ')
            count += 2;
    }
    if (count != 1) {
        printf("Figure radius entered incorrectly\n\n");
        ret++;
    }
    return ret;
}
int End(char* str)
{
    int ret = 1, firstBracket = 0;
    int endingSymbol;
    if (str[strlen(str) - 1] == '\n')
        endingSymbol = strlen(str) - 2;
    else
        endingSymbol = strlen(str) - 1;
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            firstBracket = i;
            break;
        }
    }
    if (firstBracket == endingSymbol)
        ret = 0;
    return ret;
}
int Errors(char* str, int countFigures)
{
    printf("Figure %d:\n", countFigures);
    printf("%s", str);
    if (Figure(str))
        printf("Incorrect input of figure name\n\n");
    else if (Argument(str))
        return 0;
    else if (End(str))
        printf("Wrong final symbol\n\n");
    else
        printf("\n%s\n\tarea = %f\n\tperimetr = %f\n",
               str,
               Area(str),
               Perimetr(str));

    return 0;
}