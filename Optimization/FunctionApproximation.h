#pragma once
#include <vector>
#include <string>

class ValuePair
{
public:
	double input;
	double output;
};

class FunctionApproximation
{
protected:
	std::vector<ValuePair> known_values;
public:
    double objective(std::vector<double> coefficients);
	void loadKnownValuesFromFile(std::string fileName);
};
