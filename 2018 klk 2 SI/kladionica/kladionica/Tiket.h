#pragma once

#include <iostream>
#include "Par.h"

using namespace std;

class Tiket{
private:
	void brisi();
	void kopiraj(const Tiket& t);
	void premesti(Tiket& t);
protected:
	double uplata;
	struct Elem {
		Par* par;
		Par::Ishod ishod;
		Elem* sled;
		Elem(Par* p, Par::Ishod i, Elem* s = nullptr) :par(p), ishod(i), sled(s) {};
	};
	Elem* prvi = nullptr, *posl=nullptr;
public:
	Tiket(double u) :uplata(u) {}

	Tiket& dodaj(Par* p, Par::Ishod i);

	double getuplata() const { return uplata; }

	//racuna vrednost isplate tiketa
	virtual double operator*() const = 0;
	//odredjuje da li je tiket dobitan
	virtual bool operator~() const = 0;

	virtual Tiket* kopija() const = 0;

	friend ostream& operator<<(ostream& os, const Tiket& t);

	//sva sranja od konstruktora itd
	Tiket(const Tiket& t) { kopiraj(t); }
	Tiket(Tiket&& t) { premesti(t); }
	Tiket& operator=(const Tiket& t) {
		if (this != &t) {
			brisi();
			kopiraj(t);
		}
	}
	Tiket& operator=(Tiket&& t) {
		if (this != &t) {
			brisi();
			premesti(t);
		}
	}
	virtual ~Tiket() { brisi(); }
};

