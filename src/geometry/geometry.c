#include "libgeo/circle.h"
#include "libgeo/triangle.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define size 256

int main()
{
    char str[size];
    FILE* input;
    if ((input = fopen("input.txt", "r")) == NULL) {
        perror("Error. File not found.\n");
        return 1;
    }
    while ((fgets(str, size, input)) != 0) {
        if (str[0] == 'c')
            circle(str);
        if (str[0] == 't')
            triangle(str);
    }
    return 0;
}
