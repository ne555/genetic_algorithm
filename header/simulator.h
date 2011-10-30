#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>

namespace ic{
	class poblacion;
}

class simulator{
public:
	simulator(ic::poblacion &p): p(p){}
	void run(size_t cant, std::ostream *out);
private:
	ic::poblacion &p;
};

#endif