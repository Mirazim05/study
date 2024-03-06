// Sphere.h
#ifndef SPHERE_H
#define SPHERE_H

#include "Shape3D.h"
#include <cmath>

class Sphere : public Shape3D {
private:
    float radius;

public:
    Sphere(float radius) : radius(radius) {
        CalculateVolume();
    }

    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() const override {
        std::cout << "Я сфера!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "Радиус = " << radius << std::endl;
    }

    std::string GetName() const override {
        return "Sphere";
    }

    void CalculateVolume() override {
        volume = (4.0f / 3.0f) * 3.14159265358979323846 * pow(radius, 3);
    }
};

#endif // SPHERE_H