#include <cassert>
#include <limits>
#include <iostream>
#include <Plane.hpp>

void Plane::Debug() {

    std::cout << mNormal.ToString() << std::endl;
    std::cout << mV.ToString() << std::endl;
    std::cout << mW.ToString() << std::endl;


}

void Plane::Orthonormalize() {
    mNormal = mNormal / mNormal.Norm2();
    
    double r12{mV * mNormal};
    mV = mV - (mNormal * r12);
    mV = mV / mV.Norm2();
    
    double r13{mNormal * mW};
    double r23{mV * mW};

    mW = mW - mNormal * r13 - mV * r23;
    mW = mW / mW.Norm2();
}


Plane::Plane(const Point<double>& normal)
    : mNormal{normal} {
    assert(! normal.IsZero());
    // get li vectors in the plane
    if (IsZero(normal[0]) && IsZero(normal[1])) {
        mV = {1, 0, 0};
        mW = {0, 1, 0};
    } else if (IsZero(normal[0])) {
        mV = {1, 0, 0};
        mW = {0, -normal[2]/ normal[1], 1};
    } else {
        mV = { -normal[1] / normal[0], 1, 0};
        mW = { -normal[2] / normal[1], 0, 1};
    }
    Orthonormalize();
}
