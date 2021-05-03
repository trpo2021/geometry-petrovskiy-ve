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
<<<<<<< HEAD
bool control_count(int normal_value, int get_count);
int point_check(const char* figure, int indx1, int indx2);
int radius_check(const char* figure, int indx1, int indx2);
bool wkt_check(const char* figure, int length);
bool circle_wkt_check(const char* figure, int circle_length);
Circle tokens_return(const char* figure);
bool num_check(const char* figure, int circle_length);
||||||| cc6a09f
bool control_count(int normal_value, int get_count);
int point_check(const char* figure, int indx1, int indx2);
int radius_check(const char* figure, int indx1, int indx2);
bool wkt_check(const char* figure, int length);
bool circle_wkt_check(const char* figure, int circle_length);
Circle tokens_return(const char* figure);
=======

bool wkt_check(string str);
>>>>>>> test-re-create
#endif