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
int control_count(int normal_value, int get_count);
int point_check(char* figure, int indx1, int indx2);
int radius_check(char* figure, int indx1, int indx2);
int wkt_check(const char* figure, int length);
Circle circle_wkt_check(char* figure, int circle_length);
#endif