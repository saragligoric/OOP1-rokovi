#ifndef _Sekvenca_h_
#define _Sekvenca_h_

#include "Greske.h"

template <typename T>
class Sekvenca {
	struct Elem {
		T pod;
		Elem* sled;
		Elem(T& t, Elem* s = nullptr) :pod(t), sled(s) {}
	};
	Elem* prvi=nullptr,*posl=nullptr;
	int d = 0;
	bool moze = true;
	void kopiraj(const Sekvenca& s);
	void premesti(Sekvenca& s);
	void brisi();
public:
	Sekvenca() = default;
	Sekvenca(const Sekvenca& s) {
		kopiraj(s);
	}
	Sekvenca(Sekvenca&& s) { 
		premesti(s); 
	}
	Sekvenca& operator=(const Sekvenca& s) {
		if (this != &s) { 
			brisi(); 
			kopiraj(s); 
		}
		return *this;
	}
	Sekvenca& operator=(Sekvenca&& s) {
		if (this != &s) {
			brisi(); 
			premesti(s);
		}
		return *this;
	}
	~Sekvenca() { brisi(); }

	Sekvenca& dodaj(T t);
	T& uzmi();
	int duz()const { return d; }
	T& operator[](int i);
	const T& operator[](int i)const {
		return const_cast<Sekvenca&>(*this)[i];
	}
};


template <typename T>
Sekvenca<T>& Sekvenca<T>::dodaj(T t) {
	if (!moze) throw GDodaj();
	posl = (!prvi ? prvi : posl->sled) = new Elem(t);
	d++;
	return *this;
}

template <typename T>
T& Sekvenca<T>::uzmi() {
	T t = prvi->pod;
	Elem* pom = prvi;
	prvi = prvi->sled;
	if (!prvi) posl = prvi;
	delete pom;
	moze = false;
	d--;
	return t;
}

template<typename T>
T& Sekvenca<T>::operator[](int i) {
	if (i<0 || i>=d) throw GPozicija();
	Elem* pom = prvi;
	for (; i > 0; i--, pom = pom->sled);
	return pom->pod;
}

//napravi sve potrebne konstruktore
template <typename T>
void Sekvenca<T>::kopiraj(const Sekvenca& s) {
	prvi = posl = nullptr;
	for (Elem* temp = s.prvi; temp; temp = temp->sled) {
		posl=(!prvi?prvi:posl->sled)= new Elem(temp->pod);
	}
}

template <typename T>
void Sekvenca<T>::premesti(Sekvenca& s) {
	moze = s.moze;
	d = s.d;
	prvi = s.prvi;
	posl = s.posl;
	s.prvi=s.posl = nullptr;
}

template <typename T>
void Sekvenca<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}

#endif
