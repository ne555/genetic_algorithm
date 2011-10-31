#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <utility>

namespace ic{
	class poblacion;
}

class simulator{
public:
	simulator(ic::poblacion &p): p(p){}
	std::pair<unsigned long int, double> run(size_t cant, std::ostream *out);
private:
	ic::poblacion &p;
};

#endif
