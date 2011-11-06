#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "poblacion.h"
#include "util.h"
#include "typedef.h"
using namespace std;
using namespace ic;

static bool comp (indice_fitness i,indice_fitness j) { return (i.second>j.second); }

namespace ic{
	poblacion::poblacion(size_t tamanio, const function &fitness):
		popullation(tamanio),
		fitness(fitness),
		size(tamanio),
		puntaje(tamanio){
		lucha_por_la_vida();
	}

	gen_valor poblacion::mejor(){
		int index = max_element(
				puntaje.begin(), 
				puntaje.end()
			) - puntaje.begin();
		//return make_pair( popullation[index].value(), puntaje[index] );
		return make_pair( popullation[index].value(), puntaje[index] );
	}
#if 1
	void poblacion::siguiente_generacion(){
		//seleccion de los padres, 
		//mediante algoritmo de competencias
		const float mutante = 0.20;
		poblado new_age;
		ordenar();
		//new_age.push_back( popullation[ind_fit[0].first] );
		for(size_t K=0; K<size; ++K){
			//vector<int> padre = competir();
			vector<int> padre = ventaneo(size-floor(K*0.1)*10);
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
#else
	void poblacion::siguiente_generacion(){
		//seleccion de los padres, 
		//mediante algoritmo de competencias
		const float mutante = 0.10;
		poblado new_age; new_age.reserve(popullation.size());
		//new_age.push_back( popullation[mejor().first] );
		for(size_t K=0; K<size-1; ++K){
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
#endif

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

/*
	void poblacion::print(std::ostream &out){
		for(size_t K=0; K<size; ++K)
			out << setprecision(9) << fixed << fitness.map(popullation[K].value()) << ' ';
		out << endl;
	}
*/

	vector<int> poblacion::ventaneo(int ventana) const{
		vector<int> mejores(2);
	
		for(size_t K=0; K<mejores.size(); ++K){
			int maxi = math::random::randomize<int>(0,ventana)();
			mejores[K] = ind_fit[maxi].first;
		}
		return mejores;
	}
	
	void poblacion::ordenar(){
		ind_fit.clear();
		for(size_t K=0;K<size;++K)
			ind_fit.push_back(make_pair(K, puntaje[K] ));
		sort(ind_fit.begin(),ind_fit.end(), comp);
	}
}

