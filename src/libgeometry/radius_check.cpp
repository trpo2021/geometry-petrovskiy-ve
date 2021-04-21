#include "radius_check.h"
#include <iostream>

int radius_check(char* figure, int indx1, int indx2)
{
    int i;
    int checker = 0;
    for (i = indx1 + 1; i < indx2; ++i) {
        if (isdigit(figure[i]) != 0) {
            checker = 1;
        } else if (
                (figure[i] == ' ')
                || (((figure[i] == '+') || (figure[i] == '.'))
                    && (isdigit(figure[i + 1]) != 0)
                    && (isdigit(figure[i - 1]) != 0))) {
            continue;
        } else {
            std::cout << "Error at column" << i
                      << ": expected positive '<double>'" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return checker;
}