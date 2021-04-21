#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circle_compute.h"
#include "control_count.h"
#include "point_check.h"
#include "radius_check.h"
#include "wkt_check.h"

using namespace std;

int main()
{
    char obj[25];
    cout << "Enter figure: ";
    scanf("%[^\n]s", obj);
    int obj_length = strlen(obj);

    int check_flag = wkt_check(obj, obj_length);
    if (check_flag == 1) {
        Circle tokens;
        tokens = circle_wkt_check(obj, obj_length);

        Calculations result_calc;
        result_calc = circle_compute(tokens.r);

        cout << obj << endl;
        cout << "P = " << result_calc.perimeter << endl;
        cout << "S = " << result_calc.area << endl;
    }
}