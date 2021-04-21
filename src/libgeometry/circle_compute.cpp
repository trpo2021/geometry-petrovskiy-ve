#include "circle_compute.h"
#include <math.h>

Calculations circle_compute(double radius)
{
    Calculations result;
    result.perimeter = 2 * 3.1415 * radius;
    result.area = 3.1415 * pow(radius, 2);

    return result;
}