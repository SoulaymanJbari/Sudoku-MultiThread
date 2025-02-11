#include "MyWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QElapsedTimer>
#include "../inc/Sudoku.h"
#include "../inc/Solve.h"
#include "../inc/SudokuSet.h"

MyWindow::MyWindow(QWidget *parent) : QWidget(parent) {
    setupUI();
}

MyWindow::~MyWindow() {
}

void MyWindow::setupUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    solveButton = new QPushButton("Résoudre", this);
    clearButton = new QPushButton("Réinitialiser", this);

    connect(solveButton, &QPushButton::clicked, this, &MyWindow::onSolveClicked);
    connect(clearButton, &QPushButton::clicked, this, &MyWindow::onClearClicked);

    createGrid();

    
    mainLayout->addLayout(gridLayout);

    // Création du label pour afficher le temps de calcul
    timeLabel = new QLabel("Temps de calcul : -- ms", this);
    timeLabel->setAlignment(Qt::AlignCenter);

    // Ajout du label au layout
    mainLayout->addWidget(timeLabel);


    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(solveButton);
    buttonLayout->addWidget(clearButton);

    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle("Sudoku Solver");
    resize(500, 500);
}

void MyWindow::createGrid() {
    gridLayout = new QGridLayout();
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col] = new QLineEdit(this);
            cells[row][col]->setMaxLength(1);
            cells[row][col]->setAlignment(Qt::AlignCenter);
            cells[row][col]->setFixedSize(40, 40);  // Taille des cases

            gridLayout->addWidget(cells[row][col], row, col);
        }
    }
}



void MyWindow::onSolveClicked() {
    int array[9][9] = {0};
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            bool ok;
            int value = cells[row][col]->text().toInt(&ok);
            if (ok) {
                array[row][col] = value;
            }
        }
    }
    Sudoku sudoku(array);
    QElapsedTimer timer;
    timer.start();
    Solve::solve(sudoku);
    qint64 elapsedTime = timer.elapsed();
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            int value = sudoku.array[row][col];
            cells[row][col]->setText(QString::number(value));
        }
    }
    timeLabel->setText(QString("Temps de calcul : %1 ms").arg(elapsedTime));
    QMessageBox::information(this, "Résultat", "Grille résolue !");
}

void MyWindow::onClearClicked() {

    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col]->clear();
        }
    }
}
