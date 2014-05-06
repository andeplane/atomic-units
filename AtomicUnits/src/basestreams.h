#pragma once
#include <baseunits.h>

std::ostream& operator<< (std::ostream &out, const Speed &v) {
    out << v.value << " m/s";
    return out;
}

std::ostream& operator<< (std::ostream &out, const Time &v) {
    out << v.value << " s";
    return out;
}

std::ostream& operator<< (std::ostream &out, const Distance &v) {
    out << v.value << " m";
    return out;
}
