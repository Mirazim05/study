// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape2D.h"

class Triangle : public Shape2D {
private:
    float base;
    float height;

public:
    Triangle(float base, float height) : base(base), height(height) { CalculateArea(); }

    void Scale(float scaleFactor) override {
        base *= scaleFactor;
        height *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() const override {
        std::cout << "� �����������!" << std::endl;
        std::cout << "��� ������� = " << area << std::endl;
        std::cout << "����� ����� ��������� = " << base << std::endl;
        std::cout << "��� ������ = " << height << std::endl;
    }

    std::string GetName() const override {
        return "Triangle";
    }

    void CalculateArea() override {
        area = 0.5f * base * height;
    }

    float GetBase() const {
        return base;
    }
};

#endif // TRIANGLE_H