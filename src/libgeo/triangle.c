#include "triangle.h"
#include "circle.h"
#include "cross.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
float digit_treug[8] = {0};
float all[9] = {0};

void triangle(char str[])
{
    float p1, area, perimetr, a, b, z;
    int i = 0, c = 0;
    bool flag_t = false;
    float digit_treug[8] = {0};
    while (str[i] != ')') {
        flag_t = false;
        if ((0x30 <= str[i] && str[i] <= 0x39) && str[i - 1] != '.') {
            if (str[i - 1] == '-') {
                flag_t = true;
            }
            if (str[i + 1] == '.') {
                digit_treug[c] = (str[i] & 0x0F) + (str[i + 2] & 0x0F) * 0.1;
                if (flag_t == true) {
                    digit_treug[c] *= -1;
                }
                c++;
            } else {
                digit_treug[c] = str[i] & 0x0F;
                if (flag_t == true) {
                    digit_treug[c] *= -1;
                }
                c++;
            }
        }
        i++;
    }

    if (digit_treug[0] && digit_treug[1] != digit_treug[7] && digit_treug[8]) {
        printf("Error. First and last coordinates must be equal.\n");
        _Exit(1);
    }
    printf("%s\n", str);
    float x1 = digit_treug[2], x2 = digit_treug[4], x3 = digit_treug[6],
          y1 = digit_treug[3], y2 = digit_treug[5], y3 = digit_treug[7];
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    z = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    if (a > 0 || b > 0 || z > 0) {
        perimetr = a + b + c;
        p1 = perimetr / 2;
        area = sqrtf(p1 * (p1 - a) * (p1 - b) * (p1 - z));
        printf("PERIMETR TRIANGLE: %.2f\nAREA TRIANGLE: %.2f\n\n",
               perimetr,
               area);
        for (i = 0; i < 6; i++) {
            all[i] = digit_treug[i];
        }
    } else {
        printf("Error. Sides must be > 0\n");
        _Exit(1);
    }
}
