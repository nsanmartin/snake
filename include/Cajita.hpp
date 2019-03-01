#ifndef _CAJITA_H
#define _CAJITA_H

#include <cstdint>

#include <Angle.hpp>
#include <Point.hpp>


class Cajita {
    uint64_t mColor;
    Point<int> mDimentions;
    Point <int> mPos;
public:
    int mSize{};
    Angle mAngle;

    Cajita(int size = 1, Point <int> pos = Point<int>{}, Angle angle = Angle{})
        : mDimentions {Point<int>{size, size,size}},
          mPos{pos}, mAngle{angle} {}
    void Move(const Point<int>& p) { mPos += p; }
    void Rotate(int i) { mAngle += i; }
    
};



#endif
