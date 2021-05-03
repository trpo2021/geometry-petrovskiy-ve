#include "wkt_check.h"
#include <iostream>
#include <string>
using namespace std;

bool control_count(int normal_value, int get_count)
{
    if (normal_value == get_count) {
        return 1;
    } else {
        return 0;
    }
}

int point_check(const char* figure, int indx1, int indx2)
{
    int i;
    int checker = 0;
    for (i = indx1 + 1; i < indx2; ++i) {
        if (isdigit(figure[i]) != 0) {
            checker = 1;
        } else if (
                (figure[i] == ' ')
                || (((figure[i] == '+') || (figure[i] == '-'))
                    && (isdigit(figure[i + 1]) != 0))) {
            continue;
        } else {
            std::cout << "\nError at column" << i << ": expected '<int>'"
                      << std::endl;
            break;
            return 0;
            exit(EXIT_FAILURE);
        }
    }
    return checker;
}

int radius_check(const char* figure, int indx1, int indx2)
{
    int i;
    int checker = 0;
    for (i = indx1 + 1; i < indx2; ++i) {
        if (isdigit(figure[i]) != 0) {
            checker = 1;
        } else if (
                (figure[i] == ' ')
                || (((figure[i - 1] != '-') || (figure[i] == '+')
                     || (figure[i] == '.'))
                    && (isdigit(figure[i + 1]) != 0)
                    && (isdigit(figure[i - 1]) != 0))) {
            continue;
        } else {
            std::cout << "\nError at column" << i
                      << ": expected positive '<double>'" << std::endl;
            break;
            return 0;
            exit(EXIT_FAILURE);
        }
    }
    return checker;
}

bool wkt_check(const char* figure, int length)
{
    int i, n;
    char example_circle[] = "circle(x y,r)";

    for (i = 0; (figure[i] != '(') && (i < length); ++i)
        n = i;
    if (n == 5) {
        for (i = 0; i <= n; ++i) {
            if ((figure[i]) != example_circle[i]) {
                std::cout << "\nError at column" << i << ": expected 'circle'"
                          << std::endl;
                return 0;
                exit(EXIT_FAILURE);
            } else
                continue;
        }
        return 1;
    } else {
        std::cout << "\nError at column" << n + 1 << ": expected 'circle'"
                  << std::endl;
        return 0;
        exit(EXIT_FAILURE);
    }
}

bool circle_wkt_check(const char* figure, int circle_length)
{
    Circle tokens;
    int i, tmp1, tmp2, tmp3, tmp4;
    tmp1 = tmp2 = tmp3 = tmp4 = 0;

    for (i = 0; i < circle_length; ++i) {
        if (figure[i] == '(') {
            tokens.open_bracket = i;
            tmp1++;
        }
        if ((figure[i] == ' ') && (isdigit(figure[i - 1]) != 0)) {
            tokens.space = i;
            tmp2++;
        }
        if (figure[i] == ',') {
            tokens.comma = i;
            tmp3++;
        }
        if (figure[i] == ')') {
            tokens.close_bracket = i;
            tmp4++;
        }
    }
    int cntrlcount = control_count(1, tmp1) + control_count(1, tmp2)
            + control_count(1, tmp3) + control_count(1, tmp4);
    if (cntrlcount != 4) {
        std::cout << "\nError: unexpected token" << std::endl;
        return 0;
        exit(EXIT_FAILURE);
    } else {
        if (figure[tokens.close_bracket + 1] != '\0') {
            std::cout << "\nError at column " << tokens.close_bracket + 1
                      << ": unexpected token" << std::endl;
            return 0;
            exit(EXIT_FAILURE);
        }
        return 1;
    }
}

Circle tokens_return(const char* figure)
{
    Circle tokens;
    int i;
    int checker = point_check(figure, tokens.open_bracket, tokens.space);
    if (checker != 0) {
        int j = 0;
        char* coordX = new char[tokens.space - tokens.open_bracket];
        for (i = tokens.open_bracket + 1; i < tokens.space; ++i) {
            coordX[j] = figure[i];
            j++;
        }
        tokens.x = atof(coordX);

        checker = point_check(figure, tokens.space, tokens.comma);
        if (checker != 0) {
            j = 0;
            char* coordY = new char[tokens.comma - tokens.space];
            for (i = tokens.space; i < tokens.comma; ++i) {
                coordY[j] = figure[i];
                j++;
            }
            tokens.y = atof(coordY);

            checker = radius_check(figure, tokens.comma, tokens.close_bracket);
            if (checker != 0) {
                j = 0;
                char* rad = new char[tokens.close_bracket - tokens.comma];
                for (i = tokens.comma + 1; i < tokens.close_bracket; ++i) {
                    rad[j] = figure[i];
                    j++;
                }
                tokens.r = atof(rad);
            }
        }
    }
    return tokens;
}

bool num_check(const char* figure, int circle_length)
{
    string str = "";
    string tmp_string = "";
    for (int i = 0; i < circle_length; i++) {
        str = str + figure[i];
    }
    tmp_string = str.substr(str.find('('), str.find(')'));

    for (auto chr : tmp_string)
        if (chr != ',' && chr != ' ' && (chr >= '0' && chr <= '9') && chr != '('
            && chr != ')' && chr != '.') {
            std::cout << "\nError: unexpected values" << std::endl;
            return 0;
            exit(EXIT_FAILURE);
        } else
            return 1;
    return 0;
}