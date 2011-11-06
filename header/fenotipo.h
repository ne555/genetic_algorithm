#ifndef FENOTIPO_H
#define FENOTIPO_H

#include <limits>
#include <iostream>
#include <vector>
#include "typedef.h"

struct mapeo{
	typedef ic::uli uli;
	mapeo(double lower, double upper):
		lower(lower), upper(upper){}

	inline double operator()(uli v) const{
		double value = double(v)/std::numeric_limits<uli>::max();
		value *= (upper-lower);
		value += lower;
		return value;
	}

	double lower, upper;
};

namespace ic{
	class fenotipo{
	public:
		virtual double operator()(uli v) const = 0;
		virtual void print_value(uli v, std::ostream &out) const = 0;
	};
}

class f1: public ic::fenotipo{
public:
	virtual double operator()(ic::uli v) const;
	virtual void print_value(ic::uli v, std::ostream &out) const;
private:
	double map(ic::uli v) const;
};

class f2: public ic::fenotipo{
public:
	virtual double operator()(ic::uli v) const;
	virtual void print_value(ic::uli v, std::ostream &out) const;
private:
	double map(ic::uli v) const;
};

class f3: public ic::fenotipo{
public:
	virtual double operator()(ic::uli v) const;
	virtual void print_value(ic::uli v, std::ostream &out) const;
private:
	std::vector<double> map(ic::uli v)const;
};

#endif
