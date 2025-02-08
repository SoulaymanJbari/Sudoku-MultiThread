#include "MyWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

MyWindow::MyWindow(QWidget *parent) : QWidget(parent) {
    setupUI();
}

MyWindow::~MyWindow() {
    // Le destructeur, pour nettoyer si nécessaire
}

void MyWindow::setupUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Créer les éléments de l'interface
    solveButton = new QPushButton("Résoudre", this);
    clearButton = new QPushButton("Réinitialiser", this);

    // Connecter les signaux des boutons aux slots
    connect(solveButton, &QPushButton::clicked, this, &MyWindow::onSolveClicked);
    connect(clearButton, &QPushButton::clicked, this, &MyWindow::onClearClicked);

    // Créer et ajouter la grille
    createGrid();

    // Ajouter les éléments à la fenêtre
    mainLayout->addWidget(solveButton);
    mainLayout->addWidget(clearButton);
    mainLayout->addLayout(gridLayout);

    setLayout(mainLayout);
    setWindowTitle("Sudoku Solver");
    resize(400, 500);
}

void MyWindow::createGrid() {
    gridLayout = new QGridLayout();
    
    // Créer un tableau de 9x9 de champs de texte (QLineEdit) pour chaque cellule de la grille
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col] = new QLineEdit(this);
            cells[row][col]->setMaxLength(1);  // Limiter à un seul chiffre par cellule
            cells[row][col]->setAlignment(Qt::AlignCenter);
            gridLayout->addWidget(cells[row][col], row, col);
        }
    }
}

void MyWindow::onSolveClicked() {
    // Code pour résoudre la grille de Sudoku et afficher les résultats dans les QLineEdit
    // Exemple simple, tu peux adapter avec ta logique de résolution
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            bool ok;
            int value = cells[row][col]->text().toInt(&ok);
            if (ok) {
                // Si une valeur est présente dans la cellule, la traiter pour résoudre
                // Ajoute ici ta logique de résolution de Sudoku
            }
        }
    }

    // Afficher un message de succès (ou d'erreur) si nécessaire
    QMessageBox::information(this, "Résultat", "Grille résolue !");
}

void MyWindow::onClearClicked() {
    // Réinitialiser la grille
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            cells[row][col]->clear();
        }
    }
}
