#include "stdafx.h"
#include "FunctionApproximation.h"
#include <fstream>
#include "math.h"

using namespace std;

//
// Basic IO
//
void FunctionApproximation::loadKnownValuesFromFile(string fileName) {
	ifstream fvalues(fileName);
	while (!fvalues.eof()) {
		ValuePair valuepair;
		fvalues >> valuepair.input;
		fvalues >> valuepair.output;
		known_values.push_back(valuepair);
	};
	fvalues.close();
}

//
// Objective functions
//
double FunctionApproximation::objective(std::vector<double> coefficients) {
	double sum_diff = 0;
	for (auto valuepair : known_values) {
		double x = valuepair.input;
		double y = coefficients[0] * pow(x - coefficients[1], 3) +
   			      coefficients[2] * pow(x - coefficients[3], 2) +
			      coefficients[4];
		auto diff = (double)pow(y - valuepair.output, 2);
		sum_diff += diff;
	}
	return sum_diff;
}
