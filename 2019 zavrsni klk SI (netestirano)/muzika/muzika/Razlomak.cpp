#include "Razlomak.h"

Razlomak operator+(const Razlomak& r1, const Razlomak& r2)
{
    return Razlomak(r1.br * r2.im + r2.br * r1.im, r1.im * r2.im);
}

bool operator>(const Razlomak& r1, const Razlomak& r2)
{
    if ((r1.br / r1.im)> (r2.br / r2.im)) return true;
    else return false;
}

ostream& operator<<(ostream& os, const Razlomak& r)
{  
    return os << r.br << "/" << r.im;
}
