#ifndef AGENTE_VIAJERO_H
#define AGENTE_VIAJERO_H

#include "fenotipo.h"
#include <vector>
#include <iostream>

class agente_viajero : public ic::fenotipo{
public:
	typedef std::vector< std::vector<double> > matrix;
	agente_viajero(const matrix &distancias);
	double operator()(ic::uli v) const;
	void print_value(ic::uli v, std::ostream &out) const;

private:
	std::vector<int> map(ic::uli v) const;
	double distance(const std::vector<int> &secuencia) const;
	const matrix &mapa;
	size_t size;
};

#endif
