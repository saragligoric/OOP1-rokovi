#include "Vocka.h"

ostream& operator<<(ostream& os, const Vocka& v)
{
    os << v.naziv << "(" << v.starost << "/" << v.vek << "):" << v.prihod << endl;
       return os;
}
