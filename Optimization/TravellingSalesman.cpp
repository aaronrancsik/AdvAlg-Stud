#include "stdafx.h"
#include "TravellingSalesman.h"
#include <fstream>
#include "math.h"
using namespace std;

//
// Basic IO
//
void TravellingSalesmanProblem::loadTownsFromFile(string fileName) {
	ifstream ftowns(fileName);
	while (!ftowns.eof()) {
		Town town;
		ftowns >> town.x;
		ftowns >> town.y;
		towns.push_back(town);
	};
	ftowns.close();
}

void TravellingSalesmanProblem::saveTownsToFile(string fileName, vector<Town> townVector) {
	ofstream ftowns(fileName);
	for (Town twn : townVector) {
		ftowns << twn.x << "\t" << twn.y << endl;
	};
	ftowns.close();
}

//
// Objective functions
//
double TravellingSalesmanProblem::objective(vector<Town> route) {
	double sum_length = 0;

	for (unsigned int ti = 0; ti < route.size() - 1; ti++) {
		Town t1 = route[ti];
		Town t2 = route[ti + 1];
		sum_length += sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
	}
	return sum_length;
}
const vector<Town> &TravellingSalesmanProblem::getTowns() const
{
    return towns;
}


