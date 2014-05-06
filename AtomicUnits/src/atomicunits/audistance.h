#pragma once
#include <compphysunits.h>
class AUDistance : public Unit<AtomicUnit<1,0,0,0> >
{
public:
    constexpr static const double siFactor = 5.2917721092e-11;

    constexpr AUDistance(double d) :
        Unit<AtomicUnit<1,0,0,0> > (d)
    {}
    constexpr AUDistance(const Distance &d) :
        Unit<AtomicUnit<1,0,0,0> >(d.value / siFactor)
    {}

    AUDistance& operator= (const Distance &distance) {
        value = distance.value / siFactor;
        return *this;
    }
};

constexpr AUDistance operator "" _au_L(long double d) {
    return AUDistance(static_cast<double>(d));
}

std::ostream& operator<< (std::ostream &out, const AUDistance &distance) {
    out << distance.value << " au_L";
    return out;
}

double operator / (Distance distance1, AUDistance distance2) {
    return distance1.value * AUDistance::siFactor / (distance2.value);
}

double operator / (AUDistance distance1, Distance distance2) {
    return distance1.value / (distance2.value * AUDistance::siFactor);
}
