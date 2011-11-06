#ifndef CROMOSOMA_H
#define CROMOSOMA_H

#include <bitset>

namespace ic{
	class cromosoma{
	public:
		typedef unsigned long int uli;
		static const size_t size = 8*sizeof(uli);
		typedef std::bitset<size> adn;
		cromosoma();
		cromosoma(const cromosoma &a, const cromosoma &b); //sex
		void mutate();
		inline uli value() const{
			return genes.to_ulong();
		}
	private:
		void randomize();
		adn genes;
	};
}

#endif
