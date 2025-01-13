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
    sudoku.printSudoku();

    std::cout << "La réponse séquentielle est : \n";
    auto start = std::chrono::high_resolution_clock::now();
    Solve::solve(sudoku);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Temps d'exécution : " << duration.count() << " ms" << std::endl;
    sudoku.printSudoku();


    Sudoku sudoku2(array);
    std::cout << "La réponse OpenMP est : \n";

    auto start2 = std::chrono::high_resolution_clock::now();
    Solve::solveMP(sudoku2,5);
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    std::cout << "Temps d'exécution : " << duration.count() << " ms" << std::endl;
    sudoku.printSudoku();

    return 0;


}