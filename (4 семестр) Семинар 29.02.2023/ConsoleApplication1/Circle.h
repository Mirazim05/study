// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape2D.h"
#include <cmath>

class Circle : public Shape2D {
private:
    float radius;

public:
    Circle(float radius) : radius(radius) { CalculateArea(); }

    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() const override {
        std::cout << "Я круг!" << std::endl;
        std::cout << "Моя площадь = " << area << std::endl;
        std::cout << "Радиус = " << radius << std::endl;
    }

    std::string GetName() const override {
        return "Circle";
    }

    void CalculateArea() override {
        area = 3.14159265358979323846 * radius * radius;
    }

    float GetRadius() const {
        return radius;
    }
};

#endif // CIRCLE_H