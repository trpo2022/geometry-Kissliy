#include "circle.h"
#include "cross.h"
#include "triangle.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
float all[9];
float digit_circle[3] = {0};

void circle(char str[])
{
    int i = 0, c = 0;
    bool flag_c = false;
    while (str[i] != ')') {
        flag_c = false;
        if ((0x30 <= str[i] && str[i] <= 0x39) && str[i - 1] != '.') {
            if (str[i - 1] == '-') {
                flag_c = true;
            }
            if (str[i + 1] == '.') {
                digit_circle[c] = (str[i] & 0x0F) + (str[i + 2] & 0x0F) * 0.1;
                if (flag_c == true) {
                    digit_circle[c] *= -1;
                }
                c++;
            } else {
                digit_circle[c] = str[i] & 0x0F;
                if (flag_c == true) {
                    digit_circle[c] *= -1;
                }
                c++;
            }
        }
        i++;
    }
    if (digit_circle[2] < 0) {
        printf("Error. Radius < 0.");
        _Exit(1);
    }
    for (i = 0; i < 3; i++) {
        all[i + 6] = digit_circle[i];
    }
    printf("%s\n\n", str);
    printf("AREA CIRCLE: %f\nPERIMETR CIRCLE: %f\n",
           circle_area(digit_circle),
           circle_perimetr(digit_circle));
    if (cross(all))
        printf("\n\nFIGURES DON'T INTERSECT\n");
    else {
        printf("\n\nFIGURES INTERSECT\n");
    }
}

float circle_area(float digit_circle[])
{
    float area, rad;
    rad = digit_circle[2];
    area = rad * rad * M_PI;
    return area;
}

float circle_perimetr(float digit_circle[])
{
    float rad = digit_circle[2];
    float perimetr = (rad + rad) * M_PI;
    return perimetr;
}
