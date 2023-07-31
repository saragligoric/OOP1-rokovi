#pragma once
#include "Vocka.h"


class Vocnjak{
	static int prethid;
	int id = ++prethid;
	Vocka*** vocnjak;
	int red, kolona;
	void kopiraj(const Vocnjak& v);
	void premesti(Vocnjak& v);
	void brisi();
public:
	Vocnjak(int r, int k);
	Vocnjak& operator+=(const Vocka& v);

	Vocnjak(const Vocnjak& v) { kopiraj(v); }
	Vocnjak(Vocnjak&& v) { premesti(v); }
	Vocnjak& operator=(const Vocnjak& v) {
		if (this != &v) {
			brisi();
			kopiraj(v);
		}
		return *this;
	}
	Vocnjak& operator=(Vocnjak&& v) {
		if (this != &v) {
			brisi();
			premesti(v);
		}
		return *this;
	}
	~Vocnjak() { brisi(); }

	Vocnjak operator++();

	double getukprihod() const;
	int getid()const { return id; }

	friend bool operator<(const Vocnjak& v1, const Vocnjak& v2);

	friend ostream& operator<<(ostream& os, const Vocnjak& v);
};

