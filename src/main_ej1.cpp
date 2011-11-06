#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "poblacion.h"
#include "simulator.h"
#include "fenotipo.h"

using namespace std;


int main(int arc, char **argv){
	time_t seed; //= 1320079363;/*time(NULL);*/
	seed = time(NULL);
	srand( seed );
	ic::poblacion p(50, f1());
	simulator s(p);

	s.run(2000, &cout);
	cout << endl;
	cout << "Seed " << seed << endl;

	return 0;
}


