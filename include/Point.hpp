#ifndef _POINT_H
#define _POINT_H

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <sstream>

template<typename T>
using r3vec = std::array<T, 3>;

const size_t r3size = 3;

template <typename T>
bool is_zero(const T& number) {
    return std::abs(number) < std::numeric_limits<T>::epsilon();
}


template <typename T>
class Point {
    static const double pi;
    r3vec<T> mVec;
public:
    Point(T x = 0, T y = 0, T z = 0) : mVec{{x,y,z}} {}
    Point(r3vec<T> vec ) : mVec{vec} {}


    double GetX() const { return static_cast<double>(mVec[0]); }
    double GetY() const { return static_cast<double>(mVec[1]); }
    double GetZ() const { return static_cast<double>(mVec[2]); }

    int GetXInt() const { return static_cast<int>(mVec[0]); }
    int GetYInt() const { return static_cast<int>(mVec[1]); }
    int GetZInt() const { return static_cast<int>(mVec[2]); }

    void SetX(T x) { mVec[0] = x; }
    void SetY(T y) { mVec[1] = y; }
    void SetZ(T z) { mVec[2] = z; }

    
    
    void RotateX(int angle);
    void RotateY(int angle);
    void RotateZ(int angle);

    Point<T>& operator=(const Point<T>& o) {
        mVec = o.mVec; return *this;
    }

    bool operator == (const Point<T>& p) {
        return mVec[0] == p.mVec[0] && mVec[1] == p.mVec[1]
            && mVec[2] == p.mVec[2];
    }
    Point<T>& operator += (const Point<T> &p) {
        for (size_t i = 0; i < r3size; i++) { mVec[i] += p.mVec[i]; }
        return *this;
    }
    Point<T>& operator -= (const Point<T> &p) {
        for (size_t i = 0; i < r3size; i++) { mVec[i] -= p.mVec[i]; }
        return *this;
    }

    Point<T> operator -() const {
        return *this * static_cast<T>(-1);
    }
    Point<T>& operator/=(int d) {
        std::for_each(mVec.begin(), mVec.end(), [&d](T& x) {
                x /= static_cast<T>(d); });
        return *this;
    }

    T& operator[](int i) { return mVec.at(i); }
    const T& operator[](int i) const { return mVec.at(i); }

    bool IsZero() const {
        return is_zero<T>(mVec[0]) && is_zero<T>(mVec[1]) && is_zero<T>(mVec[2]);
    }
    
    double Norm2() const {
        double acc{};
        for (auto& x : mVec) { acc += x*x; }
        return std::sqrt(acc);
    }

    template<typename T_>
    friend Point<T_> operator/(const Point<T_>& q, const T_& scalar);
    template<typename T_>
    friend Point<T_> operator*(const Point<T_>& q, const T_& scalar);

    std::string ToString(std::string sep = " ") {
        std::stringstream res;
        res.width(std::numeric_limits< double >::max_digits10 + 2);
        res.precision(std::numeric_limits< double > ::max_digits10);
        res << mVec[0] << sep << mVec[1] << sep << mVec[2];
        return res.str();
    }

    Point<double> ToDouble() {
        r3vec<double> transformed;
        std::transform(mVec.begin(), mVec.end(),
                       transformed.begin(),[] (int i) {
                           return static_cast<double>(i);
                       });
        return Point<double>{transformed};
    }
};

template <typename T>
Point<T> operator+ (const Point<T>& p, const Point<T>& q) {
    Point<T> res{p};
    res += q;
    return res;
}

template <typename T>
Point<T> operator- (const Point<T>& p, const Point<T>& q) {
    return p + -q;
}

template <typename T>
T operator*(const Point<T>& p, const Point<T>& q) {
    T res{};
    for (size_t i = 0; i < r3size; i++) {
        res += p[i] * q[i];
    }
    return res;
}

template <typename T>
Point<T> operator*(const Point<T>& q, const T& scalar) {
    Point<T> res{q};
    std::for_each(res.mVec.begin(), res.mVec.end(), [&scalar] (T& x) {
            x *= scalar;
        });
    return res;
}

template <typename T>
Point<T> operator/(const Point<T>& q, const T& scalar) {
    Point<T> res{q};
    std::for_each(res.mVec.begin(), res.mVec.end(), [&scalar] (T& x) {
            x /= scalar;
        });
    return res;
}

template<typename T>
const double Point<T>::pi{3.1415926535897};


template <typename T>
void Point<T>::RotateX(int angle) {

    double radians{angle * pi/180};
    double cos_angle{cos(radians)};
    double sin_angle{sin(radians)};

    double y{GetY()};
    double z{GetZ()};
    
    SetY(y * cos_angle - z * sin_angle);
    SetZ(y * sin_angle + z * cos_angle);
}


template <typename T>
void Point<T>::RotateY(int angle) {
    double radians{angle * pi/180};
    double cos_angle{cos(radians)};
    double sin_angle{sin(radians)};

    double x{GetX()};
    double z{GetZ()};
    
    SetX(x * cos_angle + z * sin_angle);
    SetZ(z * cos_angle - x * sin_angle);
}

template <typename T>
void Point<T>::RotateZ(int angle) {
    double radians{angle * pi/180};
    double cos_angle{cos(radians)};
    double sin_angle{sin(radians)};

    double x{GetX()};
    double y{GetY()};
    
    SetX(x * cos_angle - y * sin_angle);
    SetY(x * sin_angle + y * cos_angle);
}


#endif
