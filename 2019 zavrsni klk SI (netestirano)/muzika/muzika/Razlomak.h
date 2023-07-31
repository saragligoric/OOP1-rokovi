#pragma once
#include <iostream>

using namespace std;

class Razlomak{
	int br, im;
public:
	Razlomak(int b, int i=1) :br(b), im(i) {}
	friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2);
	friend bool operator>(const Razlomak& r1, const Razlomak& r2);
	friend ostream& operator<<(ostream& os, const Razlomak& r);
};

