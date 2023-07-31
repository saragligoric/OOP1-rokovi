#include "Vocnjak.h"

int Vocnjak::prethid = 0;

//pazi na id
void Vocnjak::kopiraj(const Vocnjak& v)
{
	red = v.red;
	kolona = v.kolona;
	vocnjak = new Vocka * *[red];
	for (int i = 0; i < red; i++) {
		vocnjak[i] = new Vocka * [kolona];
		for (int j = 0; j < kolona; j++) {
			vocnjak[i][j] = (v.vocnjak[i][j] ? new Vocka(*v.vocnjak[i][j]) : nullptr);
		}
	}
	id = ++prethid;
}

void Vocnjak::premesti(Vocnjak& v)
{
	red = v.red;
	kolona = v.kolona;
	id = ++prethid;
	vocnjak = v.vocnjak;
	v.vocnjak = nullptr;
}

void Vocnjak::brisi()
{
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			delete vocnjak[i][j];
		}
		delete[] vocnjak[i];
	}
	delete[]vocnjak;
	vocnjak = nullptr;
}

Vocnjak::Vocnjak(int r, int k)
{
	red = r;
	kolona = k;
	vocnjak = new Vocka * *[red];
	for (int i = 0; i < red; i++) {
		vocnjak[i] = new Vocka * [kolona];
		for (int j = 0; j < kolona; j++) {
			vocnjak[i][j] = nullptr;
		}
	}
}

Vocnjak& Vocnjak::operator+=(const Vocka& v)
{
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			if (vocnjak[i][j] == nullptr){
				vocnjak[i][j] = new Vocka(v); return *this;
			}
		}
	}
	return *this;
}

Vocnjak Vocnjak::operator++()
{
	Vocnjak v = (*this);
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			if (v.vocnjak[i][j] != nullptr) {
				v.vocnjak[i][j]->operator++();
				if (v.vocnjak[i][j]->getpreostgod() == 0) {
					delete v.vocnjak[i][j];
					v.vocnjak[i][j] = nullptr;
				}
			}
		}
	}
	return v;
}

double Vocnjak::getukprihod() const
{
	double uk = 0; 
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kolona; j++) {
			if (vocnjak[i][j]!=nullptr)
			uk += vocnjak[i][j]->getprihod();
		}
	}
	return uk;
}

bool operator<(const Vocnjak& v1, const Vocnjak& v2)
{
	if (v1.getukprihod() < v2.getukprihod()) return true;
	else return false;
}

ostream& operator<<(ostream& os,const Vocnjak& v)
{
	os << v.id << ":" <<v.getukprihod()<<endl;
	for (int i = 0; i < v.red; i++) {
		for (int j = 0; j < v.kolona; j++) {
			if (v.vocnjak[i][j] != nullptr) os << *(v.vocnjak[i][j]) << '\t'<< '\t'<< '\t';
			else os << "Prazno_mesto" << '\t'<< '\t'<< '\t';
		}
		os << endl;
	}	
	return os;
}
