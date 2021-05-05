#include "wkt_check.h"
#include <iostream>
#include <string>
using namespace std;

bool wkt_check(string str)
{
    string values_str;
    Circle tokens;

    if (str.empty())
        return 0;

    for (auto chr : str)
        if (chr == ' ')
            tokens.space++;
    if (tokens.space != 1)
        return 0;
    for (auto chr : str)
        if (chr == ',')
            tokens.comma++;
    if (tokens.comma != 1)
        return 0;
    for (auto chr : str)
        if (chr == '(')
            tokens.l_bracket++;
    if (tokens.l_bracket != 1)
        return 0;
    for (auto chr : str)
        if (chr == ')')
            tokens.r_bracket++;
    if (tokens.r_bracket != 1)
        return 0;
    if (str.find(' ') > str.find(','))
        return 0;

    values_str = str.substr(str.find('('), str.find(')'));

    for (auto chr : values_str)
        if (chr != ',' && chr != ' ' && !(chr >= '0' && chr <= '9')
            && chr != '(' && chr != ')' && chr != '.')
            return 0;
    if (values_str.length() <= 7)
        return 0;

    if ("circle" != str.substr(0, str.find_first_of("(")))
        return 0;

    return 1;
}