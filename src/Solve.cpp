#include <iostream>
#include "../inc/Solve.h"
#include <QApplication>

bool Solve::solve(Sudoku &sudoku){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if(sudoku.array[i][j]==0){
                for (int num=1;num<=9;num++){
                    sudoku.array[i][j] = num;
                    if (sudoku.isCorrect()){
                        if (solve(sudoku)){
                            return true;
                        }
                    }
                    sudoku.array[i][j] = 0;
                }
                return false;
            }
        }
    }
    return true;
}
void Solve::preSolve(SudokuSet &sudokuSet,Sudoku &sudoku, int depth){
    bool found = false;
    for (int i=0;i<9;i++){
        if (found){
            break;
        }
        for (int j=0;j<9;j++){
            if (found){
                break;
            }
            if (sudoku.array[i][j]==0){
                found = true;
                for (int num=1;num<=9;num++){
                    sudoku.array[i][j] = num;
                    if (sudoku.isCorrect()){
                        if(depth ==0){
                            sudokuSet.addSudoku(sudoku);
                        }
                        else{
                            preSolve(sudokuSet,sudoku,depth-1);
                        }
                    }
                    sudoku.array[i][j] = 0;
                }

            }
        }
    }
}
bool Solve::solveMP(Sudoku &sudoku, int depth){
    SudokuSet sudokuSet;
    preSolve(sudokuSet,sudoku,depth);
    int size = sudokuSet.getSize();
    bool found = false;
    #pragma omp parallel for
    for (int i=0;i<size;i++){
        if (found){
            continue;
        }
        Sudoku personalSudoku = sudokuSet.at(i);
        found = solve(personalSudoku);
        if (found){
            sudoku = personalSudoku;
        }
    }
    if (found){
        return true;
    }
    return false;
}