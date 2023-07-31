#pragma once
#include <string>
#include <iostream>

using namespace std;

class Vocka{
	string naziv;
	double prihod;
	int vek;
	int starost = 0;
public:
	Vocka(string n, double p, int v) :naziv(n), prihod(p), vek(v) {}
	
	double getprihod() const { return prihod; }
	int getpreostgod()const { return vek - starost; }

	Vocka operator++() {
		Vocka v = (*this);
		starost++;
		return v;
	}

	friend ostream& operator<<(ostream& os, const Vocka& v);
};
