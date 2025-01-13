#include <iostream>
#include "../inc/SudokuSet.h"
#include <vector>

SudokuSet::SudokuSet(){
    std::vector<Sudoku> vector;
    this->vector = vector;
}
void SudokuSet::addSudoku(Sudoku sudoku){
    vector.push_back(sudoku);
}
Sudoku SudokuSet::at(int i){
    return vector.at(i);
}
int SudokuSet::getSize(){
    return vector.size();
}
void SudokuSet::printSet(){
    int size = this->getSize();
    Sudoku sudoku;
    for (int i=0;i<size;i++){
        sudoku = this->at(i);
        sudoku.printSudoku();
        std::cout<<"########## \n\n";
    }
}