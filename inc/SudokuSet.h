#ifndef SUDOKUSET
#define SUDOKUSET

#include "Sudoku.h"
#include <vector>

class SudokuSet {
    public:
        std::vector<Sudoku> vector;
        SudokuSet();
        void addSudoku(Sudoku Sudoku);
        Sudoku at(int i);
        int getSize();
        void printSet();
};




#endif