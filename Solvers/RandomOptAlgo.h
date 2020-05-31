#ifndef RANDOMOPTALGO_H
#define RANDOMOPTALGO_H

#include "Random.h"
#include "TravellingSalesman.h"

#include <iostream>

using namespace std;

class RandomOptAlgo
{


public:
    RandomOptAlgo(int mMean, int mVariance, double mGoalFitness, const string &filename)
        : mMean(mMean), mVariance(mVariance), mGoalFitness(mGoalFitness), filename(filename)
    {
        tsp = TravellingSalesmanProblem();
        tsp.loadTownsFromFile(filename);
    }
    virtual ~RandomOptAlgo()
    {

    }
    void Solve(){
        auto route = tsp.getTowns();
        while (CalculateFitness(route) > mGoalFitness){
            cout << "current: fitt: " << CalculateFitness(route)<<"\n";

            vector<Town> newRoute = GenerateRoute(route);


            if(CalculateFitness(newRoute) < CalculateFitness(route)){
                route = newRoute;
                cout << "fitt: " << CalculateFitness(route)<<"\n";
            }
        }
        cout << "fitt: " << CalculateFitness(route)<<"\n";

    }



private:
    int mMean, mVariance;
    double mGoalFitness;
    string filename;
    TravellingSalesmanProblem tsp;
    double CalculateFitness(vector<Town> route){
        tsp.objective(route);
    }

    vector<Town> MixRouteNormalDist(vector<Town> route)
    {
        int n = route.size();
        while (n > 1){
            n--;
            int shift = randomNormal(mMean, mVariance);
            int randomIndex = n + shift;
            if(randomIndex < 0 )
            {
                randomIndex =0;
            }
            if(randomIndex >= route.size())
            {
                randomIndex = route.size()-1;
            }
            Town town = route[randomIndex];
            route[randomIndex] = route[n];
            route[n] = town;
        }
        return route;
    }

    vector<Town> GenerateRoute(vector<Town> route)
    {
        vector<Town> newRoute = route;
        //cout << "ok: fitt: " << CalculateFitness(newRoute)<<"\n";
        newRoute = MixRouteNormalDist(newRoute);
        //cout << "mixed: fitt: " << CalculateFitness(newRoute)<<"\n";
        return newRoute;
    }
};


#endif //RANDOMOPTALGO_H
