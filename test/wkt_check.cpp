#include <iostream>
#include <string.h>
#include <wkt_check.h>

extern "C" {
#include <ctest.h>
}

CTEST(input_suite, correct_input_check)
{
    const char* input_char = "circle(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, wrong_figure_input_check)
{
    const char* input_char = "cirkle(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, wrong_coords_input_check)
{
    const char* input_char = "circle(1314,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, wrong_right_bracket_input_check)
{
    const char* input_char = "circle(13 14,8";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, wrong_left_bracket_input_check)
{
    const char* input_char = "circle13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, extra_spaces_in_input)
{
    const char* input_char = "circle (13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, letter_in_x)
{
    const char* input_char = "circle(1a3 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, letter_in_y)
{
    const char* input_char = "circle(13 1c4,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, letter_in_rad)
{
    const char* input_char = "circle(13 14,8r)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, extra_space_before_figure)
{
    const char* input_char = " circle(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, extra_space_after_figure)
{
    const char* input_char = "circle(13 14,8) ";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, figure_witout_parametres)
{
    const char* input_char = "circle";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parametres_witout_figure)
{
    const char* input_char = "(13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parameteres_without_x)
{
    const char* input_char = "circle( 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parameteres_without_y)
{
    const char* input_char = "circle(13 ,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, parameteres_without_rad)
{
    const char* input_char = "circle(13 14)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, float_x)
{
    const char* input_char = "circle(1.3 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, float_y)
{
    const char* input_char = "circle(13 1.4,8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, float_rad)
{
    const char* input_char = "circle(13 14,0.8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, float_all)
{
    const char* input_char = "circle(1.3 1.4,0.8)";

    const bool result = wkt_check(input_char);

    ASSERT_TRUE(result);
}

CTEST(input_suite, negative_x)
{
    const char* input_char = "circle(-13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_y)
{
    const char* input_char = "circle(13 -14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_rad)
{
    const char* input_char = "circle(13 14,-8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_x_extra_space)
{
    const char* input_char = "circle(- 13 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_y_extra_space)
{
    const char* input_char = "circle(13 - 14,8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}

CTEST(input_suite, negative_rad_extra_space)
{
    const char* input_char = "circle(13 14,- 8)";

    const bool result = wkt_check(input_char);

    ASSERT_FALSE(result);
}