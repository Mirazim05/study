#include <iostream>
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "TriangularPyramid.h"
#include "Cylinder.h"
#include "Sphere.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Square square(5.0f);
    square.ShowInfo();

    Triangle triangle(10.0f, 2.0f);
    triangle.ShowInfo();

    Circle circle(3.0f);
    circle.ShowInfo();

    TriangularPyramid pyramid(10.0f, 2.0f, 5.0f);
    pyramid.ShowInfo();

    Cylinder cylinder(3.0f, 7.0f);
    cylinder.ShowInfo();

    Sphere sphere(4.0f);
    sphere.ShowInfo();

    return 0;
}