#pragma once
#include <string>
#include "Tiket.h"

using namespace std;

class Kladionica{
	string naziv;
	struct Elem {
		Tiket* tiket;
		Elem* sled;
		Elem(const Tiket& t, Elem* s=nullptr) :tiket(t.kopija()), sled(s) {}
		~Elem() { delete tiket; }
	};
	Elem* prvi = nullptr, *posl=nullptr;
public:
	Kladionica(string s) :naziv(s) {}
	~Kladionica();
	//posto nema kopiranja, onda nema ni kopirajuceg premestajuceg konstr itd
	Kladionica(const Kladionica&) = delete;
	Kladionica& operator=(Kladionica&) = delete;

	Kladionica& operator+=(const Tiket& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		return *this;
	}

	//odredjuje trenutu zaradu kladionice
	double operator++() const;

	friend ostream& operator<<(ostream& os, const Kladionica& k);
};

