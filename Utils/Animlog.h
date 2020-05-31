#pragma once

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

class Animlog {
	std::ofstream log_file;
public:
	Animlog(std::string filename) : log_file(filename) {
	}

	~Animlog() {
		log_file.close();
	}

	void clearScreen();
	void putInfo(std::string info);
	void putIteration(int iteration);
	void putFitness(double fitness);
	void putPoint(double x, double y, std::string color);
	void putLine(double x1, double y1, double x2, double y2, std::string color);
	void putArrow(double x1, double y1, double x2, double y2, std::string color);
};
