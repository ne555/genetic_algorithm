#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long int uli;

template<class T>
T factorial(T v){
	T result = 1;
	if(v)
		for(size_t K=v; K>0; --K)
			result *= K;
	return result;
}

size_t nth_disp(size_t n, const std::vector<bool> &disponible){
	size_t count = 0;
	for(size_t K=0; K<disponible.size(); ++K){
		if(disponible[K]) count++;
		if(count == n) return K;
	}
	return -1;
}

std::vector<int> nth_permutation(uli n, size_t size){
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

double distancia(const std::vector<int> &secuencia){
	double d = mapa[secuencia.back()][secuencia.front()];
	for(size_t K=1; K<secuencia.size(); ++K)
		d += mapa[secuencia[K]][secuencia[K-1]];
	return d;
}

struct point{
	valarray<double> coord(2);
	double& operator[](size_t index){
		return coord[index];
	}
	double operator[](size_t index) const{
		return coord[index];
	}
	double distance(const point &p) const{
		return norm2(coord-p.coord);
	}
	double norm2() const{
		return sqrt( (coord*coord).sum() );
	}
};

int main(){
	int k,n;
	while(cin>>k>>n){
		vector<int> v = nth_permutation(k,n);
		for(size_t K=0; K<n; ++K)
			cout << v[K] << ' ';
		cout << endl;
	}

	cin>>number_of_points;
	vector<point> ciudades;
	for(size_t K=0; K<number_of_points; ++K)
		cin>>ciudades[K][0]>>ciudades[K][1];
	
	for(size_t K=0; K<number_of_points; ++K)
		for(size_t L=0; L<number_of_points; ++L)
			mapa[K][L] = ciudades[K].distancia( ciudades[L] );
	return 0;
}

