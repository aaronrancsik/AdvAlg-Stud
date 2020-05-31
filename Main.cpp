#include "stdafx.h"
#include <string>
#include "iostream"
#include "Solvers/GeneticAlgo.h"
#include "Solvers/HillClimbAlgo.h"
#include "Solvers/RandomOptAlgo.h"
#include "time.h"

int main(int argc, char *argv[])
{
    clock_t start = clock();

    string arg1 = argv[1];
    if(arg1.compare("0") == 0)
    {
        GeneticAlgo ga = GeneticAlgo("FuncAppr1.txt",300,5,2,100,60);
        ga.Solve();
    }
    else if(arg1.compare("1") == 0)
    {
        RandomOptAlgo ra = RandomOptAlgo(0,1,4000,"Towns.txt");
        ra.Solve();
        /* */
    }
    else
    {
        HillClimbAlgo ro = HillClimbAlgo(10, 3, 400, 1, "Points.txt");
        ro.Solve();
    }



    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);

    return 0;
}

