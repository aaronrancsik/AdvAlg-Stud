#include "stdafx.h"
#include "Random.h"
#include <random>
#include <iostream>

using namespace std;

random_device rd;
mt19937 gen(rd());

// random double between [min, max[
double randomUniform(double min, double max) {
	uniform_real_distribution<double> dis(min, max);
	auto ret =dis(gen);
	//cout<<ret;
	return ret;
}

// random integer between [min, max]
int randomUniform(int min, int max) {
	uniform_real_distribution<double> dis((double)min, (double)max + 1);
	return (int)dis(gen);
}

// random unsigned integer between [min, max]
unsigned int randomUniform(unsigned int min, unsigned int max) {
	return (unsigned int)randomUniform((int)min, (int)max);
}

// random double between [0, 1[
double randomUniform() {
	uniform_real_distribution<double> dis(0, 1);
	return dis(gen);
}

// ranom gaussian number
double randomNormal(double mean, double stddev) {
	normal_distribution<double> dis(mean, stddev);
	return dis(gen);
}