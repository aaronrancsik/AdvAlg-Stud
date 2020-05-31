#include "stdafx.h"
#include "Animlog.h"

using namespace std;

void Animlog::clearScreen() {
	log_file << "Clear" << endl;
}

void Animlog::putInfo(string info) {
	log_file << "Info" << "\t" << info << endl;
}

void Animlog::putIteration(int iteration) {
	log_file << "Iteration" << "\t" << iteration << endl;
}

void Animlog::putFitness(double fitness) {
	log_file << "Fitness" << "\t" << fitness << endl;
}

void  Animlog::putPoint(double x, double y, string color) {
	log_file << "Point" << "\t" << x << "\t" << y << "\t" << color << endl;
}

void  Animlog::putLine(double x1, double y1, double x2, double y2, string color) {
	log_file << "Line" << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << "\t" << color << endl;
}

void  Animlog::putArrow(double x1, double y1, double x2, double y2, string color) {
	log_file << "Arrow" << "\t" << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << "\t" << color << endl;
}
