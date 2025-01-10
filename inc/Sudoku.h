#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
    public:
        int array[9][9];
        int checked;
        bool finished;
        bool correct;
        Sudoku(int array[9][9]);
        void printSudoku();
        bool isFinished();
        bool verify_line();
        bool verify_col();
        bool verify_grid();
        bool isCorrect();

};

#endif