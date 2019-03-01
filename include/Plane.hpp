#ifndef _PLANE_H
#define _PLANE_H

#include <Point.hpp>

class Plane {
    Point<double> mNormal;
    Point<double> mV;
    Point<double> mW;
public:
    Plane(const Point<double>& normal);
    bool IsZero(double d) {
        return std::abs(d) < std::numeric_limits<double>::epsilon();
    }

    void Debug() ;
    
private:
    void Orthonormalize(); 
};


#endif
