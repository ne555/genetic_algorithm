#include <cstdlib>
#include "cromosoma.h"
#include "util.h"

namespace ic{
	cromosoma::cromosoma(const cromosoma &a, const cromosoma &b){
		//size_t div = rand()%size;
		size_t div = math::random::randomize<int>(1, size-2)();
		for(size_t K=0; K<div; ++K)
			genes[K] = a.genes[K];
		for(size_t K=div; K<size; ++K)
			genes[K] = b.genes[K];
	}

	void cromosoma::mutate(){
	//cambiar un gen al azar
		size_t index = rand()%size;
		genes.flip(index);
	}

	void cromosoma::randomize(){
		for(size_t K=0; K<size; ++K)
			genes[K] = rand()%2;
	}

}

