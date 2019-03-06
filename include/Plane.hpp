#ifndef _PLANE_H
#define _PLANE_H

#include <Point.hpp>

class Plane {
    Point<double> mNormal;
    // Point<double> mV;
    // Point<double> mW;
public:
    Plane(const Point<double>& normal);
    bool IsZero(double d) {
        return std::abs(d) < std::numeric_limits<double>::epsilon();
    }

    void Debug() ;

    Point<double> Project(Point<double> x) {
        return x - mNormal * (mNormal * x);
    }
    Point<double> Project(Point<int> p) {
        return Project(p.ToDouble());
    }

    void MoveForward() {
        mNormal.RotateX(6);
    }
    void MoveBackward() { mNormal.RotateX(354); }
    void MoveRight() {
        mNormal.RotateY(6);
    } 
    void MoveLeft() { mNormal.RotateY(354); }   
    
private:
    void Orthonormalize(); 
};


#endif
