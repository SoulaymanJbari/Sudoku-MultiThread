#include <iostream>
#include "Sudoku.cpp"


int main(){
    int array[9][9] = {0};
    Sudoku sudoku(array);
    sudoku.afficherSudoku();
    bool solved = sudoku.solve();
    std::cout <<"la sudoku est il resolu ? " << solved << "\n";
    sudoku.afficherSudoku();
    return 0;


}