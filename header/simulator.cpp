#include <iostream>
#include "simulator.h"
#include "poblacion.h"

using namespace std;
typedef unsigned long int uli;
extern double fenotipo(uli v);

void simulator::run(size_t cant, ostream *out){
	for(size_t K=0; K<cant; ++K){
		p.siguiente_generacion();
		double fitness = p.mejor().second;
		if(out) 
			(*out) << fitness << ' ' << fenotipo(p.mejor().first) << endl;
	}
}

