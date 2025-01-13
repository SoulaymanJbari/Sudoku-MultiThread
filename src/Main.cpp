#include <iostream>
#include "../inc/Sudoku.h"
#include "../inc/Solve.h"
#include "../inc/SudokuSet.h"
#include <omp.h>
#include <chrono>


int main(){
    int array[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 2, 9, 0, 6, 5, 0},
        {1, 0, 0, 0, 7, 3, 0, 0, 0},
        {0, 3, 1, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 3, 8, 0, 0, 0, 0},
        {8, 2, 0, 0, 0, 0, 1, 0, 0},
        {0, 9, 0, 5, 0, 7, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 4, 9, 0, 0}
    };
    Sudoku sudoku(array);
    SudokuSet sudokuSet;
    Solve::preSolve(sudokuSet,sudoku,10);
    std::cout<<"La liste des sudokus possibles en depth 10 est :"<< sudokuSet.getSize() << "\n";


    return 0;


}