#ifndef POBLACION_H
#define POBLACION_H

#include <iostream>
#include <vector>
#include <utility>
#include "cromosoma.h"
#include "fenotipo.h"
#include "typedef.h"

namespace ic{
	class poblacion{
	public: 
		//typedef double (*function) (uli);
		typedef fenotipo function;
		typedef cromosoma individuo;
		typedef std::vector<individuo> poblado;

		poblacion(size_t tamanio, const function &fitness);
		void siguiente_generacion();
		gen_valor mejor();

		void print(std::ostream &);

		const function &fitness;
	private:
		std::vector<int> competir() const;
		void lucha_por_la_vida();

		poblado popullation;
		const size_t size;

		std::vector<double> puntaje;
		std::vector<indice_fitness> ind_fit; 

		std::vector<int> ventaneo(int ventana) const;
		void ordenar();
	};
}

#endif

