#include <iostream>
#include "Sudoku.cpp"
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
    sudoku.afficherSudoku();
    bool solved = sudoku.solve();
    std::cout <<"\nLa solution normale est \n\n";
    sudoku.afficherSudoku();
    Sudoku sudoku2(array);
    bool solved2 = sudoku2.solveMP(0);
    std::cout <<"\nLa solution openMP est \n\n";
    sudoku2.afficherSudoku();
    return 0;


}