#pragma once
#include <compphysunits.h>
class AUTime : public Unit<AtomicUnit<0,1,0,0> >
{
public:
    constexpr static const double siFactor = 2.418884326505e-17;

    constexpr AUTime(double d) :
        Unit<AtomicUnit<0,1,0,0> > (d)
    {}
    constexpr AUTime(const Distance &d) :
        Unit<AtomicUnit<0,1,0,0> >(d.value / siFactor)
    {}

    AUTime& operator= (const Distance &distance) {
        value = distance.value / siFactor;
        return *this;
    }
};

constexpr AUTime operator "" _au_t(long double d) {
    return AUTime(static_cast<double>(d));
}

std::ostream& operator<< (std::ostream &out, const AUTime &distance) {
    out << distance.value << " au_t";
    return out;
}
