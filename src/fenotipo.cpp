#include "fenotipo.h"
#include <vector>
#include <bitset>
#include <cmath>


using namespace ic;
using namespace std;

static vector<double>  mapeo_uli_sol2(unsigned long int v){
	vector<double> vn;
	bitset<sizeof(v)*8> valor(v);
	
	bitset<sizeof(v)*4> valorx(valor.to_string().substr(0,16));
	bitset<sizeof(v)*4> valory(valor.to_string().substr(16,16));
	
	unsigned long int ulx = valorx.to_ulong();
	unsigned long int uly = valory.to_ulong();
	double x = ((((double) ulx)/pow(2,16)) * 2 - 1) * 100; 
	double y = ((((double) uly)/pow(2,16)) * 2 - 1) * 100; 
	vn.push_back(x);
	vn.push_back(y);
	
	return vn;
}

double f1::map(uli v) const{
	return mapeo(-512, 512)(v);
}

double f2::map(uli v) const{
	return mapeo(0, 20)(v);
}

vector<double> f3::map(uli v) const{
	return mapeo_uli_sol2(v);

	vector<double> vn(2);
	const int size = sizeof(v)*8;
	const int size2 = size/2;
	bitset<size> valor(v);
	
	bitset<size2> valorx(valor.to_string().substr(0,size2));
	bitset<size2> valory(valor.to_string().substr(size2,size2));
	
	uli ulx = valorx.to_ulong();
	uli uly = valory.to_ulong();

	vn[0] = double(ulx) / std::numeric_limits<uli>::max();
	vn[1] = double(uly) / std::numeric_limits<uli>::max();
	
	for(size_t K=0; K<vn.size(); ++K)
		vn[K] = (vn[K]*2-1)*100; //rango [-1;1]

	return vn;
}

double f1::operator()(uli v) const{
	double x = map(v);
	double result = -x * sin(sqrt(abs(x)));
	return -result; //minimizar
}

double f2::operator()(uli v) const{
	double x = map(v);
	double result = x+5*sin(3*x)+8*cos(5*x);
	return -result; //minimizar
}

double f3::operator()(uli v) const{
	vector<double> vv = map(v);
	double xx = vv[0]*vv[0];
	double yy = vv[1]*vv[1];
	double ss = sin(50*pow(xx+yy, 0.1));
	ss *= ss;
	double result = pow(xx+yy, 0.25) * (ss+1);
	return -result; //minimizar
}

void f1::print_value(uli v, ostream &out) const{
	out << "X = " << map(v) << "; ";
}

void f2::print_value(uli v, ostream &out) const{
	out << "X = " << map(v) << "; ";
}

void f3::print_value(uli v, ostream &out) const{
	vector<double> x = map(v);
	out << "X = (" << x[0] << ", " << x[1] << "); ";
}

