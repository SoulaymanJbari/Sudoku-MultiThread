#include <iostream>
#include "../inc/Sudoku.h"


Sudoku::Sudoku(int array[9][9]){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            this->array[i][j] = array[i][j];
        }
    }
    this->checked = 0;
    this->finished = false;
}
Sudoku::Sudoku(){
    array[9][9] = {0};
    this->checked = 0;
    this->finished = false;
}
void Sudoku::printSudoku() {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "---------------------\n";
        }

        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << array[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool Sudoku::isFinished(){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (array[i][j] == 0){
                finished = false;
                return false;
            }
        }
    }
    finished = true;
    return true;
}

bool Sudoku::verify_line(){
    for (int i =0;i<9;i++){
        int line[9] = {0};
        for (int j=0;j<9;j++){
            if (array[i][j]!=0){
                if (line[array[i][j]-1] == 0){
                    line[array[i][j]-1]++;
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}

bool Sudoku::verify_col(){
    for (int i =0;i<9;i++){
        int col[9] = {0};
        for (int j=0;j<9;j++){
            if (array[j][i] !=0){
                if (col[array[j][i]-1] == 0){
                    col[array[j][i]-1]++;
                }
                else{
                    return false;
                }
            }
        }
    }
    return true;
}

bool Sudoku::verify_grid(){
    for (int gridRow = 0;gridRow<3;gridRow++){
        for (int gridCol = 0;gridCol<3;gridCol++){
            int grid[9] = {0};
            for (int i=0;i<3;i++){
                for (int j=0;j<3;j++){
                    int num = array[gridRow*3 + i][gridCol*3+j];
                    if (num !=0){
                        if (grid[num-1] == 0){
                            grid[num-1]++;
                        }
                        else{
                            return false;
                    }
                    }
                }
            }
        }
    }
    return true;
}

bool Sudoku::isCorrect(){
    if (verify_line() && verify_col() && verify_grid()){
        correct = true;
        return true;
    }
    else{
        correct = false;
        return false;
    }
}