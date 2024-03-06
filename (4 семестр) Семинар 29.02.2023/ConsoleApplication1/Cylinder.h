// Cylinder.h
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Shape3D.h"
#include "Circle.h"  // ��� ������������� ������� ���������

class Cylinder : public Shape3D {
private:
    Circle base;  // ���������� ����� Circle ��� ���������
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
        std::cout << "� �������!" << std::endl;
        std::cout << "��� ����� = " << volume << std::endl;
        std::cout << "������ ��������� = " << base.GetRadius() << std::endl;
        std::cout << "������ = " << height << std::endl;
    }

    std::string GetName() const override {
        return "Cylinder";
    }

    void CalculateVolume() override {
        volume = base.GetArea() * height;
    }
};

#endif // CYLINDER_H