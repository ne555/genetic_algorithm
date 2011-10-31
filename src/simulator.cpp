#include <iostream>
#include <iomanip>
#include <utility>
#include "simulator.h"
#include "poblacion.h"

using namespace std;
typedef unsigned long int uli;
extern double fenotipo(uli v);

pair<uli,double> simulator::run(size_t cant, ostream *out){
	pair<uli,double> fitness = p.mejor();
	for(size_t K=0; K<cant; ++K){
		p.siguiente_generacion();
		if(out) p.print(*out);
	}
	return fitness;
}

