#include <iostream>
#include "../inc/Solve.h"
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
bool Solve::solveMP(Sudoku &sudoku, int depth){
            bool found = false;
            for (int i=0;i<9;i++){
                for (int j=0;j<9;j++){
                    if(sudoku.array[i][j]==0){
                        if (depth > 0){
                            for (int num=1;num<=9;num++){
                                sudoku.array[i][j] = num;
                                if (sudoku.isCorrect()){
                                    if (solveMP(sudoku, depth+1)){
                                        return true;
                                    }
                                }
                                sudoku.array[i][j] = 0;
                            }
                            return false;
                        }
                        else{
                            #pragma omp parallel for firstprivate(array) shared(found)
                            for (int num=1;num<=9;num++){
                                if (found) continue;
                                sudoku.array[i][j] = num;
                                if (sudoku.isCorrect()){
                                    if (solveMP(sudoku,depth+1)){
                                        #pragma omp critical
                                        {
                                            found = true;
                                        }
                                    }
                                }
                                sudoku.array[i][j] = 0;
                            }
                            return found;
                        }
                    }
                }
            }
            return true;
        }