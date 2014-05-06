#pragma once
#include <complex>

template<int SIL, int SIt, int SIm, int SIT>
struct SIUnit {
    enum {m = SIL, kg = SIm, s = SIt, K = SIT};
};

template<int AUL, int AUt, int AUm, int AUT>
struct AtomicUnit {
    enum {au_L = AUL, au_m, au_t = AUt, au_T = AUT};
};

template<typename SIUnit>
class Unit;

template <typename SIUnit>
const Unit<SIUnit> operator+(const Unit<SIUnit>&, const Unit<SIUnit>&);

template <typename SIUnit>
const Unit<SIUnit> operator-(const Unit<SIUnit>&, const Unit<SIUnit>&);

template<typename SIUnit>
class Unit {
public:
    constexpr explicit Unit(double d) : value(d) {}

    Unit& operator+=(const Unit& rhs){
                   value+=rhs.value;
                   return *this;
    }
    Unit& operator-=(const Unit& rhs){
                   value-=rhs.value;
                   return *this;
    }

    double value;
};
using Distance = Unit<SIUnit<1,0,0,0>>;
using Mass = Unit<SIUnit<0,0,1,0>>;
using Time = Unit<SIUnit<0,1,0,0>>;
using Temperature = Unit<SIUnit<0,0,0,1>>;
using Speed = Unit<SIUnit<1,-1,0,0>>;
using Acceleration = Unit<SIUnit<1,-2, 0,0>>;
using Energy = Unit<SIUnit<2,-2,2,0>>;
using Force = Unit<SIUnit<1,-2,1,0>>;

constexpr Distance operator "" _m(long double d) {
    return Distance(static_cast<double>(d));
}

constexpr Mass operator "" _kg(long double d) {
    return Mass(static_cast<double>(d));
}

constexpr Time operator "" _s(long double d) {
    return Time(static_cast<double>(d));
}

constexpr Temperature operator "" _K(long double d) {
    return Temperature(static_cast<double>(d));
}

constexpr Energy operator "" _J(long double d) {
    return Energy(static_cast<double>(d));
}

constexpr Force operator "" _N(long double d) {
    return Force(static_cast<double>(d));
}

double operator / (Distance distance1, Distance distance2) {
    return distance1.value / distance2.value;
}

Speed operator /(Distance distance, Time time) {
    return Speed(distance.value / time.value);
}

