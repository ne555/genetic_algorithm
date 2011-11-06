#include <iostream>
#include <valarray>
#include <vector>
#include <cmath>

#include "simulator.h"
#include "poblacion.h"
#include "agente_viajero.h"
using namespace std;

static double norm2(const valarray<double> &coord){
	return sqrt( (coord*coord).sum() );
}

struct point{
	valarray<double> coord;
	point(): coord(2){}
	double& operator[](size_t index){
		return coord[index];
	}
	double operator[](size_t index) const{
		return coord[index];
	}
	double distance(const point &p) const{
		return norm2(coord-p.coord);
	}
};


int main(){
	vector<vector<double> > mapa;
	vector<point> ciudades;
	size_t number_of_points;

	cin>>number_of_points;
	cout<<number_of_points<<endl;
	mapa.resize(number_of_points, vector<double>(number_of_points, 0));
	ciudades.resize(number_of_points);

	for(size_t K=0; K<number_of_points; ++K){
		cin>>ciudades[K][0]>>ciudades[K][1];
		cout<<ciudades[K][0]<<' '<<ciudades[K][1]<<endl;
	}
	
	for(size_t K=0; K<number_of_points; ++K)
		for(size_t L=0; L<number_of_points; ++L)
			mapa[K][L] = ciudades[K].distance( ciudades[L] );
			
	cerr << "\nDistancias:\n";
	for(size_t K=0; K<number_of_points; ++K){
		for(size_t L=0; L<number_of_points; ++L)
			cerr << mapa[K][L] << ' ';
		cerr << endl;
	}

	const int n = 50;
	time_t seed = time(NULL);
	srand( seed );
	//ic::poblacion p(30, ic::fenotipo(mapeo(-limit, limit), f1));
	ic::poblacion p(n, agente_viajero(mapa));
	simulator s(p);

	cerr << n << endl;
	s.run(5000, &cout);
	cerr << endl;
	cerr << "Seed " << seed << endl;

	return 0;
}


