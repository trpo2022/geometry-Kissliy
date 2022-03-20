#include "triangle.h"
#include <math.h>
#include <stdio.h>

void triangle()
{
    float a, b, c, p, p1, s;
    printf("Enter triangle(x, y, z)\n");
    scanf(" triangle(%f, %f, %f)", &a, &b, &c);
    if (a > 0 || b > 0 || c > 0) {
        if (a <= b + c && b <= c + a && c <= a + b) {
            p = a + b + c;
            p1 = p / 2;
            s = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c));
            printf("Perimetr: %.2f\nS: %.2f\n", p, s);
        } else {
            printf("Error\n");
        }
    } else {
        printf("Error\n");
    }
}
