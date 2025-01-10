#ifndef SOLVE_H
#define SOLVE_H

#include "Sudoku.h"

class Solve{
public:
    static bool solve(Sudoku &sudoku);
    static bool solveMP(Sudoku &Sudoku,int depth);
};

#endif