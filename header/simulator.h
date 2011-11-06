#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <utility>

#include "typedef.h"

namespace ic{
	class poblacion;
}

class simulator{
public:
	simulator(ic::poblacion &p): p(p){}
	ic::gen_valor run(size_t cant, std::ostream *out);
private:
	ic::poblacion &p;
};

#endif
