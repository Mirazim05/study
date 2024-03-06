// Square.h
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape2D.h"

class Square : public Shape2D {
private:
    float side;

public:
    Square(float side) : side(side) { CalculateArea(); }

    void Scale(float scaleFactor) override {
        side *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() const override {
        std::cout << "� �������!" << std::endl;
        std::cout << "��� ������� = " << area << std::endl;
        std::cout << "����� ������� = " << side << std::endl;
    }

    std::string GetName() const override {
        return "Square";
    }

    void CalculateArea() override {
        area = side * side;
    }
};

#endif // SQUARE_H