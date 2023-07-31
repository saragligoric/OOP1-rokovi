#pragma once
#include "Znak.h"

class Pauza :public Znak{
public:
	Pauza(const Razlomak& r) :Znak(r) {}
	string opis() const {
		return "_";
	}
};

