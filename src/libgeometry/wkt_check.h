#ifndef WKT_CHECK_H
#define WKT_CHECK_H
#include <string>
using namespace std;

struct Circle {
    float x;
    float y;
    float r;
    int l_bracket = 0;
    int r_bracket = 0;
    int space = 0;
    int comma = 0;
};

bool wkt_check(string str);
#endif