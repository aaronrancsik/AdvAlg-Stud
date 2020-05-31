#include <algorithm>
#include <iostream>
#include <iomanip>
#include "GeneticAlgo.h"

GeneticAlgo::GeneticAlgo(string input, int population, int mutation, int parents,int elitism, double goalFitness)
{
    mMutation =mutation;
    mInput =input;
    mPopulation=population;
    mParents = parents;
    mElitism=elitism;
    mGoalFitness=goalFitness;
    setFunction(mInput);
}
GeneticAlgo::~GeneticAlgo()
{

}
void GeneticAlgo::setFunction(string)
{
    funcApproximation = FunctionApproximation();
    funcApproximation.loadKnownValuesFromFile(mInput);
}
void GeneticAlgo::Solve()
{
    vector<vector<double>> pop = initPopulation();

    best = mGetBest(pop);
    while (mCalcFitness(best) > mGoalFitness){
        vector<vector<double>> newPop = mElite(pop);
        while(pop.size()!= newPop.size()) {
            vector<vector<double>> parents = mGetParents(pop);
            vector<double> chrome = mCrossover(parents);
            chrome = mMutate(chrome);
            newPop.push_back(chrome);
        }
        pop = newPop;
        best = mGetBest(pop);

        for(auto b : best){
            cout << b << " ";
        }
        cout << " fit:  " << mCalcFitness(best)<< endl;
    }



}
vector<vector<double>> GeneticAlgo::initPopulation()
{
    vector<vector<double>> pop = vector<vector<double>>();
    for(int i = 0; i < mPopulation; i++){
        vector<double> current = vector<double>();
        for(int j = 0; j < 5; j++){
            current.push_back(randomUniform(0.0f,7.0f));
        }
        pop.push_back(current);
    }
    return pop;
}
vector<double> GeneticAlgo::mGetBest(vector<vector<double>> population)
{
    vector<double> max = vector<double>(5,0);
    for(auto p : population){
        double cur = mCalcFitness(p);
        double old = mCalcFitness(max);
        if(cur < old){
            max = p;
        }
    }
    return max;
}


vector<double> GeneticAlgo::mCrossover(vector<vector<double>> parents)
{
    vector<double> child = vector<double>();
    child.push_back(parents[1][0]);
    child.push_back(parents[1][1]);
    child.push_back(parents[0][2]);
    child.push_back(parents[0][3]);
    child.push_back(parents[0][4]);
    return child;
}
vector<double> GeneticAlgo::mMutate(vector<double> chromosome)
{
    chromosome[0] *= genMutate();
    chromosome[1] *= genMutate();
    chromosome[2] *= genMutate();
    chromosome[3] *= genMutate();
    chromosome[4] *= genMutate();
    return chromosome;
}
double GeneticAlgo::genMutate()
{
    double min = 1.0f - (mMutation / 100.0f);
    double max = 1.0f + (mMutation / 100.0f);
    double r = randomUniform(0.0f,1.0f);
    //cout<<r<<"\n";
    return (min+(max-min)*r);
}
double GeneticAlgo::mCalcFitness(vector<double>  chromosome)
{
    return funcApproximation.objective(chromosome);
}

vector<vector<double>> GeneticAlgo::mElite(vector<vector<double>> population)
{
    sort(population.begin(), population.end(), [this](const vector<double> & a, const vector<double> & b) -> bool
    {
        return mCalcFitness(a) < mCalcFitness(b);
    });

    vector<vector<double>> eliteCrew =vector<vector<double>>();
    for (int i = 0; i < mElitism; ++i) {
        eliteCrew.push_back(population[i]);
    }
    return eliteCrew;
}
vector<vector<double>> GeneticAlgo::mGetParents(vector<vector<double>> population)
{
    sort(population.begin(), population.end(), [this](const vector<double> & a, const vector<double> & b) -> bool
    {
        return mCalcFitness(a) < mCalcFitness(b);
    });

    vector<vector<double>> parents =vector<vector<double>>();
    for (int i = 0; i < mParents; ++i) {
        parents.push_back(population[i]);
    }
    return parents;
}

