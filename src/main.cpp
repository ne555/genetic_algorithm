#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "poblacion.h"
#include "simulator.h"

using namespace std;
typedef unsigned long int uli;

double fenotipo(uli v){
	double mapeo = double(v)/numeric_limits<uli>::max();
	mapeo *= 2;
	mapeo -= 1;
	return mapeo * 512;
}

double f1(uli v){
	double value = fenotipo(v);
	//return sin(cos(value));
	return value * sin (sqrt( fabs(value) ) );
}

int main(int arc, char **argv){
	const int n = 50;
	float limit = 515;
	srand( time(NULL) );
	ic::poblacion p(30, f1);
	simulator s(p);

	cout << n << endl;
	cout << -limit << ' ' << limit << endl;
	s.run(1000, &cout);
	cout << endl;

	return 0;
}


