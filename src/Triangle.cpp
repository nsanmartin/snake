#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>


#include <Media.hpp>
#include <Polygon/Triangle.hpp>

void Triangle::Draw(Media& media) const {

    // Point<int> center{};
    // for (auto& p : mVertices) {
    //     if (p.mX > center.mX) center.mX = p.mX;
    //     if (p.mY > center.mY) center.mY = p.mY;
    // }
    
    // center /= 2;
    // Point pos {mPos};
    // int rotation {mAngle.mRot};
    
    // std::vector<Point<int>> vertices;
    // std::transform(mVertices.begin(), mVertices.end(),
    //                std::back_inserter(vertices),
    //                [&center, &rotation, &pos](const Point<int>& p) {
    //                    Point<int> res {p - center};
    //                    res.Rotate(rotation);
    //                    res += pos + center;
    //                    return Point<int>{res.mX, res.mY};
    //                });
    
    // media.FillTriangle(vertices);
};
