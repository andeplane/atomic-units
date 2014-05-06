#include <iostream>
#include <compphysunits.h>

using namespace std;

int main()
{
    Distance d1 = 1.0_m;
    Distance d2 = 2.0_m;
    AUDistance d3 = 2.0_au_L;
    Time t1 = 1.0_s;

    Speed velocity = d1/t1;

    cout << "Distance SI: " <<  d1 << endl;
    cout << "Distance AU: " <<  d1 << endl;
    cout << "Ratio SI: " <<  d1/d2 << endl;
    cout << "Ratio SI/AU: " <<  d1/d3 << endl;
    cout << "Velocity " <<  velocity << endl;

    return 0;
}

