#ifndef fitness_H
#define fitness_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

vector<double>  mapeo_uli_sol2(unsigned long int v);

double  mapeo_uli_sol(unsigned long int v);

double f1(double x);

double f2(double x);

double f3(double x, double y);

double fitness(unsigned long int c);

#endif
