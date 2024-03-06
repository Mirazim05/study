// Cylinder.h
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape3D.h"
#include "Circle.h"  // Для использования площади основания

class Cylinder : public Shape3D {
private:
    Circle base;  // Используем класс Circle для основания
    float height;

public:
    Cylinder(float radius, float height)
        : base(radius), height(height) {
        CalculateVolume();
    }

    void Scale(float scaleFactor) override {
        base.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() const override {
        std::cout << "Я цилиндр!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "Радиус основания = " << base.GetRadius() << std::endl;
        std::cout << "Высота = " << height << std::endl;
    }

    std::string GetName() const override {
        return "Cylinder";
    }

    void CalculateVolume() override {
        volume = base.GetArea() * height;
    }
};

#endif // CYLINDER_H