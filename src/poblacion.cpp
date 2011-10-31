#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "poblacion.h"
#include "util.h"
using namespace std;

typedef unsigned long int uli;
typedef std::pair<uli, double> gen_valor;
extern double fenotipo(uli v);

namespace ic{
	poblacion::poblacion(size_t tamanio, function fitness):
		size(tamanio),
		popullation(tamanio),
		fitness(fitness),
		puntaje(tamanio){
		for(size_t K=0; K<tamanio; ++K)
			popullation[K].randomize();
		lucha_por_la_vida();
	}

	gen_valor poblacion::mejor(){
		int index = max_element(
				puntaje.begin(), 
				puntaje.end()
			) - puntaje.begin();
		return make_pair( popullation[index].value(), puntaje[index] );
	}

	void poblacion::siguiente_generacion(){
		//seleccion de los padres, 
		//mediante algoritmo de competencias
		const float mutante = 0.32;
		poblado new_age;
		for(size_t K=0; K<size; ++K){
			vector<int> padre = competir();
			individuo larva;

			if( rand()%2 )
				larva = individuo( popullation[padre[0]], popullation[padre[1]] );
			else
				larva = individuo( popullation[padre[1]], popullation[padre[0]] );

			if( math::random::randomize<float>(0,1)() < mutante )
				larva.mutate();
			new_age.push_back(larva);
		}
		popullation.swap(new_age);
		lucha_por_la_vida();
	}

	vector<int> poblacion::competir() const {
		//selecciona al azar n individuos
		//devuelve los mejores
		vector<int> mejores(2);
		const size_t n = 3;

		for(size_t K=0; K<mejores.size(); ++K){
			int maxi = math::random::randomize<int>(0,size-1)();
			for(size_t L=0; L<n; ++L){
				int index = math::random::randomize<int>(0,size-1)();
				if( puntaje[index] > puntaje[maxi] )
					maxi = index;
			}

			mejores[K] = maxi;
		}

		return mejores;
	}

	void poblacion::lucha_por_la_vida(){
		for(size_t K=0; K<size; ++K)
			puntaje[K] = fitness( popullation[K].value() );
	}

	void poblacion::print(std::ostream &out){
		for(size_t K=0; K<size; ++K)
			out << setprecision(9) << fenotipo(popullation[K].value()) << ' ';
		out << endl;
	}
}
