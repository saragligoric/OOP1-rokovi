#include <iostream>
#include "Vocka.h"
#include "Vocnjak.h"

using namespace std;

int main() {
	Vocka v1("kruska", 1500, 50);
	v1.operator++();
	Vocka v2("jabuka", 1000, 20);
	v2.operator++();
	v2.operator++();
	v2.operator++();
	
	Vocnjak v(3, 3);
	v.operator+=(v1);
	v.operator+=(v2);
	cout << v;
	v.operator++();
	cout << v;
}