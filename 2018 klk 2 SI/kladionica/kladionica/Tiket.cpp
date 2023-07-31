#include "Tiket.h"

void Tiket::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	prvi = posl = nullptr;
}

void Tiket::kopiraj(const Tiket& t)
{
	prvi = posl = nullptr;
	for (Elem* pom = t.prvi; pom; pom = pom->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(pom->par, pom->ishod);
	}
	uplata = t.uplata;
}

void Tiket::premesti(Tiket& t)
{
	uplata = t.uplata;
	prvi = t.prvi;
	posl = t.posl;
	t.prvi = t.posl = nullptr;
}

Tiket& Tiket::dodaj(Par* p, Par::Ishod i)
{
	posl=(!prvi?prvi:posl->sled)= new Elem(p, i);
	return *this;
}

ostream& operator<<(ostream& os, const Tiket& t)
{
	os << "Tiket-" << ~t << ":" << "(" << t.uplata << ")" << *t << endl;
	for (Tiket::Elem* pom = t.prvi; pom; pom = pom->sled) {
		os << *(pom->par) << "|" << pom->ishod << endl;
	}
	return os;
}
