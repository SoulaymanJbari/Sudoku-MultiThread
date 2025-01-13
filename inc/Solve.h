#ifndef SOLVE_H
#define SOLVE_H

#include "Sudoku.h"
#include "SudokuSet.h"

class Solve{
public:
    static bool solve(Sudoku &sudoku);
    static bool solveMP(Sudoku &sudoku);
    static void preSolve(SudokuSet &SudokuSet,Sudoku &sudoku,int depth);
};

#endif