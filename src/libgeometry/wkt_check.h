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
bool control_count(int normal_value, int get_count);
int point_check(const char* figure, int indx1, int indx2);
int radius_check(const char* figure, int indx1, int indx2);
bool wkt_check(const char* figure, int length);
bool circle_wkt_check(const char* figure, int circle_length);
Circle tokens_return(const char* figure);
bool num_check(const char* figure, int circle_length);
#endif