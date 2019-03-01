#ifndef _TRIANGLE_H
#define _TRIANGLE_H


#include <cassert>


#include <Polygon/Polygon.hpp>
class Media;
class Triangle : public Polygon {
public:
    Triangle(std::vector<Point<int>> vertices, uint64_t color,
             Point<int> pos = Point<int>{})
        : Polygon{vertices, color, pos}
        {
            assert(vertices.size() == 3);
        }
    void Draw(Media& media) const;
};



#endif
