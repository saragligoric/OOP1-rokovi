#pragma once
#include "Znak.h"
#include "Sekvenca.h"
#include <iostream>

using namespace std;

class Takt{
	Sekvenca<Znak*> s;
	Razlomak maks,tek=0;
	bool kraj = false;
public:
	Takt(const Razlomak& r):maks(r){}
	Takt(const Takt& t) = delete;
	Takt& operator=(const Takt& t) = delete;

	Razlomak getmaks() const { return maks; }
	Razlomak gettek()const { return tek; }

	Takt& dodaj(Znak& z){
		if (kraj) throw GKraj();
		if ((tek + z.gettrajanje()) > maks) throw GTrajanje();
			s.dodaj(&z);
			tek = tek + z.gettrajanje();
			return *this;
	}

	Takt& zavrsi() {
		kraj = true;
		return *this;
	}

	bool zavrsen()const { return kraj; }
	bool nepotpun()const {
		if (maks > tek) return true;
		else return false;
	}

	friend ostream& operator<<(ostream& os, const Takt& t);
};

