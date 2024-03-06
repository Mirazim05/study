// TriangularPyramid.h
#ifndef TRIANGULAR_PYRAMID_H
#define TRIANGULAR_PYRAMID_H

#include "Shape3D.h"
#include "Triangle.h"  // Для использования площади основания

class TriangularPyramid : public Shape3D {
private:
    Triangle base;  // Используем класс Triangle для основания
    float height;

public:
    TriangularPyramid(float baseLength, float baseHeight, float height)
        : base(baseLength, baseHeight), height(height) {
        CalculateVolume();
    }

    void Scale(float scaleFactor) override {
        base.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }

    void ShowInfo() const override {
        std::cout << "Я треугольная пирамида!" << std::endl;
        std::cout << "Мой объем = " << volume << std::endl;
        std::cout << "Длина основания = " << base.GetBase() << std::endl;
        std::cout << "Высота = " << height << std::endl;
    }

    std::string GetName() const override {
        return "TriangularPyramid";
    }

    void CalculateVolume() override {
        volume = (base.GetArea() * height) / 3.0f;
    }
};

#endif // TRIANGULAR_PYRAMID_H