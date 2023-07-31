#pragma once
#include "Razlomak.h"

class Znak{
protected:
	Razlomak trajanje;
public:
	Znak(const Razlomak& r) :trajanje(r) {}
	virtual ~Znak(){};

	Razlomak gettrajanje() const { return trajanje; }
	friend Razlomak operator+(Znak& z1, Znak& z2) { return z1.trajanje + z2.trajanje; }
	virtual string opis() const= 0;
	friend ostream& operator<<(ostream& it, const Znak& z) {
		return it << z.opis() << "(" << z.trajanje<< ")";
	}
	operator Razlomak()const { return trajanje; }
};

