#include "wkt_check.h"
#include <iostream>

int wkt_check(char* figure, int length)
{
    int i, n;
    char example_circle[] = "circle(x y, r)";

    for (i = 0; (figure[i] != '(') && (i < length); ++i) {
        n = i;
    }
    if (n == 5) {
        for (i = 0; i < n; ++i) {
            if ((figure[i]) != example_circle[i]) {
                std::cout << "Error at column" << i << ": expected 'circle'"
                          << std::endl;
                exit(EXIT_FAILURE);
            } else {
                figure[i] = (figure[i]);
                continue;
            }
        }
        return 1;
    } else {
        std::cout << "Error at column" << n + 1 << ": expected 'circle'"
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}