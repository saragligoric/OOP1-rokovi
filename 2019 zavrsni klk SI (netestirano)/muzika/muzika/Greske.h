#pragma once
#include <exception>

using namespace std;

class GDodaj :public exception {
public:
	GDodaj() :exception("Nije moguce dodavanje elementa") {};
};

class GPozicija :public exception {
public:
	GPozicija() :exception("Zadati indeks je van opsega") {};
};

class GOktava :public exception {
public:
	GOktava() :exception("Zadata oktava je van opsega") {};
};

class GTrajanje :public exception {
public:
	GTrajanje() :exception("Prekoracenje maksmalnog trajanja") {};
};

class GKraj :public exception {
public:
	GKraj() :exception("Takt je zavrsen") {};
};

class GNezavrsen :public exception {
public:
	GNezavrsen() :exception("Takt je nezavrsen") {};
};

class GDuzine :public exception {
public:
	GDuzine() :exception("Nejednake duzine") {};
};