// Shape2D.h
#ifndef SHAPE2D_H
#define SHAPE2D_H

#include "Shape.h"

class Shape2D : public Shape {
protected:
    float area;

public:
    Shape2D() : area(0.0f) {}

    virtual float GetArea() const { return area; }

    virtual bool operator>(const Shape2D& rhs) const { return this->area > rhs.area; }
    virtual bool operator<(const Shape2D& rhs) const { return this->area < rhs.area; }
    virtual bool operator==(const Shape2D& rhs) const { return this->area == rhs.area; }

    virtual void CalculateArea() = 0;
};

#endif // SHAPE2D_H