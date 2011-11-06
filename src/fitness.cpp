#include "fitness.h"



using namespace std;

double  mapeo_uli_sol(unsigned long int v){
	//double vn = ((((double) v)/(numeric_limits<unsigned long int>::max())) * 2 - 1) *512;
	
	double vn = ((((double) v)/(numeric_limits<unsigned long int>::max())))*20;
	
	return vn;
}

vector<double>  mapeo_uli_sol2(unsigned long int v){
	vector<double> vn;
	bitset<sizeof(v)*8> valor(v);
	
	bitset<sizeof(v)*4> valorx(valor.to_string().substr(0,15));
	bitset<sizeof(v)*4> valory(valor.to_string().substr(16,31));
	
	unsigned long int ulx = valorx.to_ulong();
	unsigned long int uly = valory.to_ulong();
	double x = ((((double) ulx)/pow(2,16)) * 2 - 1) * 100; 
	double y = ((((double) uly)/pow(2,16)) * 2 - 1) * 100; 
	vn.push_back(x);
	vn.push_back(y);
	
	return vn;
}


double f1(double x){
	return -x * sin(sqrt(abs(x)));
}

double f2(double x){
	return x+5*sin(3*x)+8*cos(5*x);
}

double f3(double x, double y){
	return pow((pow(x,2)+pow(y,2)),0.25) * (pow(sin(50*pow((pow(x,2)+pow(y,2)),0.1)),2)+1);
}



double fitness(unsigned long int c){
	double (*funcion)(double,double);
	funcion = &f3;
	vector<double> p = mapeo_uli_sol2(c); 
	double valor = funcion(p[0],p[1]);
	return  -valor;
}
