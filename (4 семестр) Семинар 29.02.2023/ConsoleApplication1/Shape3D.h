// Shape3D.h
#ifndef SHAPE3D_H
#define SHAPE3D_H

#include "Shape.h"

class Shape3D : public Shape {
protected:
    float volume;

public:
    Shape3D() : volume(0.0f) {}

    virtual float GetVolume() const { return volume; }

    virtual bool operator>(const Shape3D& rhs) const { return this->volume > rhs.volume; }
    virtual bool operator<(const Shape3D& rhs) const { return this->volume < rhs.volume; }
    virtual bool operator==(const Shape3D& rhs) const { return this->volume == rhs.volume; }

    virtual void CalculateVolume() = 0;
};

#endif // SHAPE3D_H