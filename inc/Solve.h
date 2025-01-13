#ifndef SOLVE_H
#define SOLVE_H

#include "Sudoku.h"
#include "SudokuSet.h"
#include <omp.h>

class Solve{
public:
    static bool solve(Sudoku &sudoku);
    static bool solveMP(Sudoku &sudoku,int depth);
    static void preSolve(SudokuSet &SudokuSet,Sudoku &sudoku,int depth);
};

#endif