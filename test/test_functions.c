#include <ctest.h>
#include <libgeo/circle.h>
#include <libgeo/cross.h>
#include <libgeo/triangle.h>
#include <stdio.h>
#define size_intersects 9
#define size_circle_area 3

float intersects[size_intersects];
float for_circle_area[size_circle_area];

CTEST(geometry_suite, simple_intersection_0)
{
    const int exp = 0;
    intersects[0] = 3.2, intersects[1] = 2, intersects[2] = 1.5,
    intersects[3] = 2.8, intersects[4] = 1.5, intersects[5] = 5,
    intersects[6] = 0, intersects[7] = 1, intersects[8] = 2.5;
    int res = cross(intersects);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_intersection_1)
{
    const int exp = 1;
    intersects[0] = 3.2, intersects[1] = 15, intersects[2] = 1.5,
    intersects[3] = 2.8, intersects[4] = 1.5, intersects[5] = 5,
    intersects[6] = 0, intersects[7] = 1, intersects[8] = 0.5;
    int res = cross(intersects);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_area_circle)
{
    const float exp = 50.265482457436691815402294132472;
    for_circle_area[0] = 4, for_circle_area[1] = 1, for_circle_area[2] = 4;
    float res = circle_area(for_circle_area);
    ASSERT_DBL_NEAR(exp, res);
}
