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
    r3vec<T> mVec;
public:
    Point(T x = 0, T y = 0, T z = 0) : mVec{{x,y,z}} {}
    Point(r3vec<T> vec ) : mVec{vec} {}
    void Rotate(int angle);
    Point<T>& operator=(const Point<T>& o) {
        mVec = o.mVec; return *this;
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
    
    double Norm2() {
        // return std::sqrt(std::accumulate(mVec.begin(), mVec.end(), 0,
        //                                  [](double acc, T& x) {
        //                                      return acc + x*x;
        //                                  }));
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
        // return std::accumulate(std::next(mVec.begin()), mVec.end(),
        //                        std::to_string(mVec[0]),
        //                        [](std::stringstream stream, T& x) {
        //                            return std::move(a) + ' ' + std::to_string(x);
        //                        });
        return res.str();
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



template <typename T>
void Point<T>::Rotate(int angle) {
    //todo: redo for R^3
//     static const double pi{3.1415926535897};
//     double radians{angle * pi/180};
//     double cos_angle{cos(radians)};
//     double sin_angle{sin(radians)};

//     double x{static_cast<double>(mX)};
//     double y{static_cast<double>(mY)};
//     mX = x * cos_angle - y * sin_angle;
//     mY = x * sin_angle + y * cos_angle;
}

#endif
