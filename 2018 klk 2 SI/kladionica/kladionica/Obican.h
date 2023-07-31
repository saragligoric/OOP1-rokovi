#pragma once
#include "Tiket.h"

class Obican :public Tiket{
public:
	Obican(double u) :Tiket(u) {}
	//racuna vrednost isplate tiketa
	double operator*() const override;
	//odredjuje da li je tiket dobitan
	bool operator~() const override;

	Obican* kopija() const { return new Obican(*this); }
};

