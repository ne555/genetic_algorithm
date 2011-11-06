#include <iostream>
#include <vector>
#include <valarray>

#include "agente_viajero.h"

using namespace std;
using namespace ic;

template<class T>
T factorial(T v){
	T result = 1;
	if(v)
		for(size_t K=v; K>0; --K)
			result *= K;
	return result;
}

static size_t nth_disp(size_t n, const std::vector<bool> &disponible){
	size_t count = 0;
	for(size_t K=0; K<disponible.size(); ++K){
		if(disponible[K]) count++;
		if(count == n) return K;
	}
	return -1;
}

static std::vector<int> nth_permutation(uli n, size_t size){
	//la permutacion numero n, de size elementos
	vector<bool> disponible(size, true);
	vector<int> secuencia(size);
	uli limit = factorial<uli>(size);

	n %= limit;

	for(size_t K=0; K<size; ++K){
		limit /= (size-K);
		size_t valor = n/limit + 1;
		secuencia[K] = nth_disp(valor, disponible);
		disponible[secuencia[K]] = false;
		n %= limit;
	}
	return secuencia;
}

std::vector<int> agente_viajero::map(ic::uli v) const{
	return nth_permutation(v,size);
}

agente_viajero::agente_viajero(const matrix &mapa):
	mapa(mapa),
	size(mapa.size()){}

double agente_viajero::distance(const std::vector<int> &secuencia) const{
	double d = mapa[secuencia.back()][secuencia.front()];
	for(size_t K=1; K<secuencia.size(); ++K)
		d += mapa[secuencia[K]][secuencia[K-1]];
	return d;
}

double agente_viajero::operator()(uli n) const{
	return -distance(nth_permutation(n,size)); //minimizar
}

void agente_viajero::print_value(ic::uli v, std::ostream &out) const{
	vector<int> secuencia = map(v);
	//out << "Orden: ";
	for(size_t K=0; K<secuencia.size(); ++K)
		out << secuencia[K] << ' ';
	//out << "; ";
}

