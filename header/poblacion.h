#ifndef POBLACION_H
#define POBLACION_H

#include <iostream>
#include <vector>
#include <utility>
#include "cromosoma.h"

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

		void print(std::ostream &);

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

