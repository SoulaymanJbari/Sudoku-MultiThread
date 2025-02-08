#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>

class MyWindow : public QWidget {
    Q_OBJECT

public:
    MyWindow(QWidget *parent = nullptr);
    ~MyWindow();

private slots:
    void onSolveClicked();  // Slot pour résoudre la grille
    void onClearClicked();  // Slot pour réinitialiser la grille

private:
    void createGrid();  // Fonction pour créer la grille de Sudoku
    void setupUI();     // Fonction pour configurer l'interface graphique

    QGridLayout *gridLayout;  // Layout pour les cases de la grille
    QLineEdit *cells[9][9];   // Tableau pour les champs de texte des cellules
    QPushButton *solveButton; // Bouton pour résoudre la grille
    QPushButton *clearButton; // Bouton pour réinitialiser la grille
};

#endif // MYWINDOW_H
