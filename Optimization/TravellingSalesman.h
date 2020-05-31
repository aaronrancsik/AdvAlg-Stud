#pragma once
#include <vector>
#include <string>

class Town
{
public:
	double x;
	double y;
};

class TravellingSalesmanProblem
{
protected:
	std::vector<Town> towns;
public:
    const std::vector<Town> &getTowns() const;

public:
    double objective(std::vector<Town> solution);
	void loadTownsFromFile(std::string fileName);
	void saveTownsToFile(std::string fileName, std::vector<Town> townVector);
};
