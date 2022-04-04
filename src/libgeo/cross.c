#include "cross.h"
#include "circle.h"
#include "triangle.h"
#include <math.h>
#include <stdio.h>

#define size 256

int cross(float all[])
{
    float a, b, c;
    float x0 = all[6], x1 = all[0], x2 = all[2], x3 = all[4], y0 = all[7],
          y1 = all[1], y2 = all[3], y3 = all[5], r = all[8];
    a = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
    b = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2));
    c = sqrt((x0 - x3) * (x0 - x3) + (y0 - y3) * (y0 - y3));
    if (((a > r) && (b > r) && (b > r)) || ((a < r) && (b < r) && (c < r))) {
        return 1;
    } else {
        return 0;
    }
}
