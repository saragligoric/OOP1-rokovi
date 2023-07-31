#include <iostream>
#include "Razlomak.h"
#include "Sekvenca.h"
#include "Nota.h"
#include "Pauza.h"
#include "Takt.h"
#include "Kompozicija.h"

using namespace std;

int main() {
	try {
		Razlomak r1(3, 5);
		Razlomak r2(12, 10);
		Nota n1(r1, 3, Nota::DO);
		Nota n2(r2, 2, Nota::MI);
		Pauza p1(r1);

		Takt t1(r2);
		t1.dodaj(n1);
		t1.dodaj(n2);

		Kompozicija k1;
		k1.dodaj(t1);
		cout << k1;
	}
	catch (exception e) {
		cout << e.what();
	}
}
