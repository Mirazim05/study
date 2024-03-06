// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() const = 0;
    virtual std::string GetName() const = 0;
    virtual ~Shape() {}
};

#endif // SHAPE_H