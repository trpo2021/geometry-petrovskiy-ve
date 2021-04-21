#include "control_count.h"

int control_count(int normal_value, int get_count)
{
    if (normal_value == get_count) {
        return 1;
    } else {
        return 0;
    }
}