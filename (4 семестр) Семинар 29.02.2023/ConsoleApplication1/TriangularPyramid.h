// TriangularPyramid.h
#ifndef TRIANGULAR_PYRAMID_H
#define TRIANGULAR_PYRAMID_H

#include "Shape3D.h"
#include "Triangle.h"  // ��� ������������� ������� ���������

class TriangularPyramid : public Shape3D {
private:
    Triangle base;  // ���������� ����� Triangle ��� ���������
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
        std::cout << "� ����������� ��������!" << std::endl;
        std::cout << "��� ����� = " << volume << std::endl;
        std::cout << "����� ��������� = " << base.GetBase() << std::endl;
        std::cout << "������ = " << height << std::endl;
    }

    std::string GetName() const override {
        return "TriangularPyramid";
    }

    void CalculateVolume() override {
        volume = (base.GetArea() * height) / 3.0f;
    }
};

#endif // TRIANGULAR_PYRAMID_H