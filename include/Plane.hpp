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
        std::cout << mNormal.ToString() << " => ";
            mNormal.RotateX(6);
        std::cout << mNormal.ToString() << std::endl;
    }
    void MoveBackward() { mNormal.RotateX(354); }
    void MoveRight() {
        std::cout << mNormal.ToString() << " => ";
        mNormal.RotateY(6);
        std::cout << "\t" << mNormal.ToString() << std::endl;
    } 
    void MoveLeft() { mNormal.RotateY(354); }   
    
private:
    void Orthonormalize(); 
};


#endif
