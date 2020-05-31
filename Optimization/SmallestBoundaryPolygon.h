#pragma once
#include <vector>
#include <string>

const double PI = 3.14159265358979f;

class Point
{
public:
	double x;
	double y;
};

class SmallestBoundaryPolygonProblem
{
protected:
	std::vector<Point> points;
public:
    double distanceFromLine(Point lp1, Point lp2, Point p);
    double outerDistanceToBoundary(std::vector<Point> solution);
    double lengthOfBoundary(std::vector<Point> solution);
    double objective(std::vector<Point> solution);
    double constraint(std::vector<Point> solution);

	void loadPointsFromFile(std::string fileName);
	void savePointsToFile(std::string fileName, std::vector<Point> pointVector);
};