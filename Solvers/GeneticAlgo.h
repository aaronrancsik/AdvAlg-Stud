#ifndef GENETICALGO_H
#define GENETICALGO_H

#include "../Optimization/FunctionApproximation.h"
#include "../Utils/Random.h"
#include <string>
// S keresesi ter
// f fitness
// StopCondition
// mutacios rata
using namespace std;
class GeneticAlgo
{
public:
    void Solve();
    GeneticAlgo(string input, int population, int mutation, int parents,int elitism, double goalFitness);
    ~GeneticAlgo();


private:
    string mInput;
    int mPopulation, mMutation, mElitism, mParents;
    double mGoalFitness;
    vector<double> best;
    FunctionApproximation funcApproximation;

    void setFunction(string file);
    vector<vector<double>> initPopulation();
    vector<double> mGetBest(vector<vector<double>> population);
    vector<vector<double>> mElite(vector<vector<double>> population);
    vector<vector<double>> mGetParents(vector<vector<double>> population);
    vector<double> mCrossover (vector<vector<double>> parents);
    vector<double> mMutate(vector<double> chromosome);
    double mCalcFitness(vector<double> chromosome);
    double genMutate();
};


#endif //GENETICALGO_H
