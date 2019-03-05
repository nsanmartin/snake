#ifndef _RECT_BOX_H
#define _RECT_BOX_H

#include <array>
#include <vector>

#include <Point.hpp>

class Media;

class RectBox {
    static std::vector<std::vector<size_t>> mDrawOrder;
    std::array<Point<double>, 8> mVertices;
    Point<double> mPos; // should it know it's pos or should yhe morld?

public:
    RectBox(int x, int y, int z);
    RectBox(double x = 1, double y = 1, double z = 1);
    void Move(Point<int> p) {
        mPos += Point<double>{p.GetX(),p.GetY(),p.GetZ()};
    }
    void Draw(Media& media) ; //todo: make const
    void CenterAt(Point<double> p) { mPos = p; }
    void CenterAt(Point<int> p) { mPos = p.ToDouble(); }

};

#endif
