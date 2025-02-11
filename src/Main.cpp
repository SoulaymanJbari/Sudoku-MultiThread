#include <iostream>
#include "../inc/Sudoku.h"
#include "../inc/Solve.h"
#include "../inc/SudokuSet.h"
#include <omp.h>
#include <chrono>
#include <QApplication>
#include "MyWindow.h"

int main(int argc,char *argv[]){
    QApplication app(argc, argv);

    MyWindow window;
    window.show();
    
    return app.exec();

}