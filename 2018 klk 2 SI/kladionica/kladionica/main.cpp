#include <iostream>
#include "Par.h"
#include "Obican.h"
#include "Kladionica.h"

using namespace std;

int main() {
	Par p1("ne kladim se", 28.5, 15.7, 36.7);
	Par p2("ne kladim se", 64.5, 15, 54.6);
	Par p3("ne kladim se", 45.7, 23.9, 65.7);
	Par p4("ne kladim se", 76.2, 105.8, 159.3);
	Par p5("ne kladim se", 11.4, 12, 36.8);

	Obican o1(100);
	cout << o1;
	o1.dodaj(&p1, Par::JEDAN).dodaj(&p2, Par::DVA).dodaj(&p3, Par::IKS).dodaj(&p4, Par::JEDAN);
	cout << o1;

	Kladionica k1("wat");
	k1 += o1;
	cout << k1;
}