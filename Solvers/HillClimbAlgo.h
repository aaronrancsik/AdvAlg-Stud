#ifndef HILLCLIMBALGO_H
#define HILLCLIMBALGO_H


#include <iostream>
#include "Random.h"
#include "SmallestBoundaryPolygon.h"

using namespace std;

class HillClimbAlgo
{
public:
    HillClimbAlgo(int mEpsilon, int mDimension, int mMaxCoordinates, int mGoalFitness, const string &filename)
        : mEpsilon(mEpsilon), mDimension(mDimension), mMaxCoordinates(mMaxCoordinates), mGoalFitness(mGoalFitness),
          filename(filename)
    {
        sbpp.loadPointsFromFile(filename);
    }
    ~HillClimbAlgo(){

    }
    void Solve(){

        vector<Point> polygon = InitPolygon();

        while (CalculateFitness(polygon) > mGoalFitness){
            vector<Point> newPolygon = GenerateRandomPolygon(polygon);
            if(CalculateFitness(newPolygon)<CalculateFitness(polygon)){
                polygon = newPolygon;
                cout << "new poly: \n";
                cout << ToString(polygon) << " fitt: "<< CalculateFitness(polygon)<<"\n";
            }
        }
        cout << ToString(polygon) << " fitt: "<< CalculateFitness(polygon);
    }
private:

    int mEpsilon, mDimension, mMaxCoordinates, mGoalFitness;
    string filename;
    SmallestBoundaryPolygonProblem sbpp = SmallestBoundaryPolygonProblem();


    double CalculateFitness (vector<Point> polygon){
        double fitt = 0;
        if(sbpp.outerDistanceToBoundary(polygon) != 0){
            fitt = sbpp.objective(polygon);
        }else{
            fitt = 10000000;
        }
        return fitt;
    }

    string ToString (vector<Point> polygon){
        string ret="";
        for(auto p : polygon){
             ret += "(" + to_string(p.x) + "," + to_string(p.y) + ") ";
        }
        return ret;
    }

    vector<Point> GenerateRandomPolygon(vector<Point> polygon)
    {
        vector<Point> newPoly = vector<Point>();
        for(auto p : polygon){
            Point newPoint = Point();
            newPoint.x = p.x + randomUniform(-1*mEpsilon, mEpsilon-1);
            newPoint.y = p.y + randomUniform(-1*mEpsilon, mEpsilon-1);
            newPoly.push_back(newPoint);
        }
        return  newPoly;
    }


    vector<Point> InitPolygon(){
        static vector<Point> polygon = vector<Point>();
        for (int i = 0; i < mDimension; ++i) {
            auto p = Point();
            p.x = randomUniform(0,mMaxCoordinates-1);
            p.y = randomUniform(0,mMaxCoordinates-1);
            polygon.push_back(p);
        }
        return polygon;
    }
};


#endif //HILLCLIMBALGO_H
