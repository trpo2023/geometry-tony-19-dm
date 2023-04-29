#include <ctest.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include <libgeometry/area.h>
#include <libgeometry/vocabulary.h>
#include <libgeometry/checkarg.h>
#include <libgeometry/perimetr.h>

CTEST(check_figure_name, correct_figure)
{
    char *str = "circle(4.0 5.0, 6.0)";
    const int expected = 0;
    const int result = checkFigure(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_figure_name, incorrect_figure)
{
    char *str = "circlee(3.0 2.0, 7)";
    const int excpected = 1;
    const int result = checkFigure(str);
    ASSERT_EQUAL(excpected, result);
}

CTEST(check_argument, int_arguments)
{
    char *str = "circle(4 5, 6)";
    const int expected = 0;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_argument, float_arguments)
{
    char *str = "circle(4.0 5.0, 6.0)";
    const int expected = 0;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_argument, incorrect_coordinates_arg)
{
    char *str = "circle(x5 4, 9.0)";
    const int expected = 2;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_argument, incorrect_radius_arg)
{
    char *str = "circle(4.0 5.0, x)";
    const int expected = 3;
    const int result = checkArguments(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end, correct_end)
{
    char *str = "circle(4.0 5.0, 6.0)\n ";
    const int expected = 0;
    const int result = checkEnd(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_end, incorrect_end)
{
    char *str = "circle(4 3, 6.1(";
    const int expected = 4;
    const int result = checkEnd(str);
    ASSERT_EQUAL(expected, result);
}

CTEST(check_area, correct_area)
{
    char *str = "circle(4 5, 6)";
    const double expected = 36 * M_PI;
    const double result = calculateArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_area, incorrect_area)
{
    char *str = "circle(4 5, x)";
    const double expected = -1;
    const double result = calculateArea(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}

CTEST(check_perimetr, correct_perimetr)
{
    char *str = "circle(4 5, 6)";
    const double expected = 2 * M_PI * 6;
    const double result = calculatePerimetr(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0.00000000001);
}

CTEST(check_perimetr, incorrect_perimetr)
{
    char *str = "circle(4 5, x)";
    const double expected = -1;
    const double result = calculatePerimetr(str);
    ASSERT_DBL_NEAR_TOL(expected, result, 0);
}