#include <iostream>
#include "../inc/Sudoku.h"
#include "../inc/Solve.h"
#include <omp.h>


int main(){
    int array[9][9] = {
        {3, 0, 5, 8, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 3, 0, 0, 4},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 8, 7, 0, 4, 0},
        {0, 0, 0, 0, 1, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 5, 3, 9},
        {0, 0, 8, 0, 0, 0, 0, 0, 2},
        {0, 4, 0, 0, 0, 0, 9, 0, 0},
        {0, 7, 0, 2, 6, 0, 0, 0, 0}
    };
    Sudoku sudoku(array);
    sudoku.printSudoku();
    Solve::solve(sudoku);
    std::cout <<"\nLa solution normale est \n\n";
    sudoku.printSudoku();
    Sudoku sudoku2(array);
    Solve::solveMP(sudoku2,0);
    std::cout <<"\nLa solution openMP est \n\n";
    sudoku2.printSudoku();
    return 0;


}