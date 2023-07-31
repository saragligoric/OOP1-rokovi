#include "Kladionica.h"

Kladionica::~Kladionica()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	prvi = posl = nullptr;
}

//trenutna zarada kladionice
//razlika sume svih uplata na svim tiketima i sume dobitnih tiketa
double Kladionica::operator++() const
{
	double uplate=0;
	double dobici=0;
	for (Elem* pom = prvi; pom; pom = pom->sled) {
		uplate += pom->tiket->getuplata();
		dobici += pom->tiket->operator*();
	}
	return uplate - dobici;
}

ostream& operator<<(ostream& os, const Kladionica& k)
{
	os << k.naziv << k.operator++() << endl;
	for (Kladionica::Elem* pom = k.prvi; pom; pom = pom->sled) {
		os << *pom->tiket << endl;
	}
	return os;
}
