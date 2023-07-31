#pragma once
#include <string>
#include <iostream>

using namespace std;

class Par{
public:
	enum Ishod{JEDAN,IKS,DVA,NEODREDJEN};
private:
	static int prethid;
	int id=++prethid;
	string opis;
	double kvote[3];
	Ishod ishod = NEODREDJEN;
public:
	Par(string s, double k1, double k2, double k3) :opis(s) {
		kvote[0] = k1;
		kvote[1] = k2;
		kvote[2] = k3;
	}
	Par(const Par& p) = delete;
	Par& operator=(const Par& p) = delete;

	//vraca kvotu za dati ishod
	double operator[](Ishod i) const{
		if (i == NEODREDJEN) return 0;
		else return kvote[i];
	}

	//postavlja ishod
	Par& operator()(Ishod i) {
		ishod = i;
		return *this;
	}
	//vraca ishod
	Ishod operator()() const{
		return ishod;
	}

	friend ostream& operator<<(ostream& os, const Par& p) {
		os << p.id << "-" << p.opis << "(" << (p.ishod==JEDAN?"T":"") << p.kvote[0] << "," << (p.ishod == IKS ? "T" : "") << p.kvote[1] << "," 
			<< (p.ishod == DVA ? "T" : "") << p.kvote[2] << ")";
		return os;
	}
};

