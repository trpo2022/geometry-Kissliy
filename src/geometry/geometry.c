#include "libgeo/circle.h"
#include "libgeo/triangle.h"
#include <math.h>
#include <stdio.h>

int main()
{
    int a;
    printf("1. Cirle\n2. Triangle\nChoose your figure: ");
    scanf(" %d", &a);
    if (a == 1) {
        circle();
    }
    if (a == 2) {
        triangle();
    } else {
        printf("Error\n");
        return 0;
    }
    return 0;
}
