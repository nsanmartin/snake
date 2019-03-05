#include <algorithm>

#include <Plane.hpp>
#include <RectBox.hpp>
#include <World.hpp>

std::vector<std::vector<size_t>> RectBox::mDrawOrder = {
    {4, 0, 1, 2, 3, 0},
    {3, 7, 6, 5, 4, 7},
    {2, 6},
    {1, 5}
};
    



RectBox::RectBox(double x, double y, double z)
    : mVertices{
    {{0,0,0},{0,y,0},{x,y,0},{x,0,0},{0,0,z},{0,y,z},{x,y,z},{x,0,z}}},
      mPos{}
{
}

RectBox::RectBox(int x, int y, int z):
    RectBox(static_cast<double>(x),
            static_cast<double>(y),
            static_cast<double>(z)) { }


void RectBox::Draw(Media& media) {
    std::array<Point<double>, 8> vertices{mVertices};
    World& w{media.GetWorld()};
    Plane& plane{w.GetPlane()}; 

    std::for_each(
        vertices.begin(), vertices.end(),
        [this, &plane] (Point<double>& p)
        {
            p = plane.Project(p + this->mPos);
        });
    
    std::for_each(
        mDrawOrder.begin(), mDrawOrder.end(),
        [&vertices, &media] (std::vector<size_t>& order) {
            std::vector<Point<double>> points;
            std::transform(
                order.begin(), order.end(),
                std::back_inserter(points),
                [&vertices](size_t index) {
                    return vertices.at(index);
                });

            media.DrawLines(points);
        });
}
