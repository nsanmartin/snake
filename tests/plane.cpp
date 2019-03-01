#include <Plane.hpp>
#include <Point.hpp>

int main () {
    Point normal{0.21, 0.72, 3.0};
    Plane plane{normal};
    plane.Debug();
}
