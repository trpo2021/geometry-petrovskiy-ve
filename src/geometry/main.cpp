#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circle_compute.h"
#include "wkt_check.h"

using namespace std;

int main()
{
    char obj[25];
    cout << "Enter figure: ";
    scanf("%[^\n]s", obj);
    int obj_length = strlen(obj);

    int check_flag_1 = wkt_check(obj, obj_length);
    int check_flag_2 = circle_wkt_check(obj, obj_length);
    if ((check_flag_1 == 1) && (check_flag_2 == 1)) {
        Circle tokens;
        tokens = tokens_return(obj);

        Calculations result_calc;
        result_calc = circle_compute(tokens.r);

        cout << obj << endl;
        cout << "P = " << result_calc.perimeter << endl;
        cout << "S = " << result_calc.area << endl;
    }
    return 0;
}