#ifndef POBLACION_H
#define POBLACION_H

#include <vector>
#include <utility>
#include "cromosoma.h"


	#include <iostream>

namespace ic{
	class poblacion{
	public: 
		typedef unsigned long int uli;
		typedef std::pair<uli, double> gen_valor;
		typedef double (*function) (uli);
		typedef cromosoma individuo;
		typedef std::vector<individuo> poblado;

		poblacion(size_t tamanio, function fitness);
		void siguiente_generacion();
		gen_valor mejor();

		void print(){
			for(size_t K=0; K<size; ++K)
				std::cerr << popullation[K].value() << ' ';
		}

	private:
		std::vector<int> competir() const;
		void lucha_por_la_vida();

		poblado popullation;
		const size_t size;
		std::vector<double> puntaje;
		function fitness;
	};
}

#endif

