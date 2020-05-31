cmake_minimum_required(VERSION 3.17)
project(AdvAlg_Stud)

set(CMAKE_CXX_STANDARD 14)

include_directories(Optimization)
include_directories(Utils)

add_executable(AdvAlg_Stud
        Solvers/GeneticAlgo.h
        Solvers/GeneticAlgo.cpp
        Optimization/FunctionApproximation.cpp
        Optimization/FunctionApproximation.h
        Optimization/ImageSegmentation.cpp
        Optimization/ImageSegmentation.h
        Main.cpp
        Optimization/PathFinding.cpp
        Optimization/PathFinding.h
        Optimization/SmallestBoundaryPolygon.cpp
        Optimization/SmallestBoundaryPolygon.h
        Optimization/stdafx.cpp
        Optimization/stdafx.h
        Optimization/targetver.h
        Optimization/TravellingSalesman.cpp
        Optimization/TravellingSalesman.h
        Optimization/WorkAssignment.cpp
        Optimization/WorkAssignment.h
        Utils/Animlog.cpp
        Utils/Animlog.h
        Utils/Random.cpp
        Utils/Random.h
        Utils/stdafx.cpp
        Utils/stdafx.h
        Utils/targetver.h
        Utils/TextLog.cpp
        Utils/TextLog.h Solvers/HillClimbAlgo.h Solvers/RandomOptAlgo.h)
