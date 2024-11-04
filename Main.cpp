#include <iostream>
#include "Sudoku.cpp"


int main(){
    int array[9][9];
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            array[i][j] = i+1;
        }
    }
    Sudoku sudoku(array);
    sudoku.afficherSudoku();
    bool finished = sudoku.isFinished();
    bool correct = sudoku.isCorrect();
    bool col = sudoku.verify_col();
    std::cout <<"la sudoku est il fini ? " << finished << "\n";
    std::cout <<"la sudoku est il correct ? " << correct << "\n";
    std::cout <<"les colonnes sont bonnes ? " << col << "\n";
    return 0;


}