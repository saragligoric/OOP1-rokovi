#pragma once
#include "Sekvenca.h"
#include "Takt.h"

class Kompozicija{
	Sekvenca<Takt*> s;
	Razlomak tr = Razlomak(0);
	bool prvi = true;
	bool moze = true;
public:
	Kompozicija() {}
	Kompozicija(const Kompozicija& k) =delete;
	void operator=(const Kompozicija& k) =delete;

	friend ostream& operator<<(ostream& ot,const Kompozicija& k) {
		for (int i = 0; i < k.s.duz(); i++)
			ot << *k.s[i] << endl;
		return ot;
	}

	Kompozicija& dodaj(Takt& t) {
		if (!t.zavrsen()) throw GNezavrsen();
		if (prvi) { prvi = false; tr = t.getmaks(); }
		else {
			if (t.getmaks() > tr || tr > t.getmaks()) throw GDuzine();
			if (t.nepotpun()) {
				if (!moze) throw GDodaj();
				else moze = false;
			}
		}
		s.dodaj(&t);
		return *this;
	}
};

