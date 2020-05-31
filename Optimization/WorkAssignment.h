#pragma once
#include <vector>
#include <string>

class Person
{
public:
	double salary;
	double quality;
};

class WorkAssignmentProblem
{
protected:
	std::vector<Person> persons;
	int requested_time;

	double sumSalary(std::vector<int> solution);
	double avgQuality(std::vector<int> solution);

public:
	virtual void loadFromFile(std::string fileName);
};