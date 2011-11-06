#include <iostream>
#include <iomanip>
#include <utility>
#include "simulator.h"
#include "poblacion.h"
#include "typedef.h"

ic::gen_valor simulator::run(size_t cant, std::ostream *out){
	ic::gen_valor fitness = p.mejor();
	for(size_t K=0; true; ++K){
		fitness = p.mejor();
		p.siguiente_generacion();
		if(out){
		//	p.print(*out);
			//(*out) << "Iter " << K << ' ';
			std::cerr << "Iter " << K << ' ';
			p.fitness.print_value(fitness.first, *out);
			p.fitness.print_value(fitness.first, std::cerr);
			//(*out) << " F(x) = " << fitness.second << std::endl;
			std::cerr << " F(x) = " << fitness.second << std::endl;
		}

		if( fitness.second > 410 ) break;

	}
	return fitness;
}

