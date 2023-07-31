#include <iostream>
#include "Takt.h"

using namespace std;

ostream& operator<<(ostream& os, const Takt& t)
{
	for (int i = 0; i < t.s.duz(); i++) {
		os << *t.s.operator[](i);
		os << " ";
	}
	os << "|";
	return os;
}
