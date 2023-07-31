#pragma once
#include "Znak.h"
#include "Greske.h"
#include <string>

using namespace std;

class Nota :public Znak{
public:
	enum visina { DO, RE, MI, FA, SOL, LA, SI };
private:
	int oktava;
	visina vis;
public:
	Nota& operator>>=(int i) {
		oktava += i;
		return *this;
	}
	Nota& operator<<=(int i) {
		oktava -= i;
		return *this;
	}
	Nota(const Razlomak& r, int o, visina v) :Znak(r) {
		if (o < 1 || o >= 5) throw GOktava();
		else oktava = o;
		vis=v;
	}

	string opis()const override {
		string s[]{ "DO", "RE", "MI", "FA", "SOL", "LA", "SI" };
		return s[vis];
	}
};

