#ifndef WKT_CHECK_H
#define WKT_CHECK_H

struct Circle {
    double r;
    int x;
    int y;
    int space;
    int comma;
    int open_bracket;
    int close_bracket;
};

int wkt_check(char* figure, int length);
Circle circle_wkt_check(char* figure, int circle_length);
#endif