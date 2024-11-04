#include <iostream>

class Sudoku {
    public:
        Sudoku(int array[9][9]){
            for (int i=0;i<9;i++){
                for (int j=0;j<9;j++){
                    this->array[i][j] = array[i][j];
                }
            }
            this->checked = 0;
            this->finished = false;
        }
        void afficherSudoku() {
            for (int i = 0; i < 9; ++i) {
                // Affichage des lignes de séparation tous les 3 lignes
                if (i % 3 == 0 && i != 0) {
                    std::cout << "---------------------\n"; // Ligne de séparation
                }

                for (int j = 0; j < 9; ++j) {
                    // Affichage des colonnes de séparation tous les 3 colonnes
                    if (j % 3 == 0 && j != 0) {
                        std::cout << "| "; // Colonne de séparation
                    }
                    std::cout << array[i][j] << " "; // Affichage de la valeur
                }
                std::cout << '\n'; // Nouvelle ligne après chaque ligne du tableau
            }
        }

        bool isFinished(){
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

        bool verify_line(){
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

        bool verify_col(){
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

        bool verify_grid(){
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

        bool isCorrect(){
            if (verify_line() && verify_col() && verify_grid()){
                correct = true;
                return true;
            }
            else{
                correct = false;
                return false;
            }
        }

        bool getFinished(){
            return finished;
        }
        
        bool getCorrect(){
            return correct;
        }
        bool solve(){
            for (int i=0;i<9;i++){
                for (int j=0;j<9;j++){
                    if(array[i][j]==0){
                        for (int num=1;num<=9;num++){
                            array[i][j] = num;
                            if (isCorrect()){
                                if (solve()){
                                    return true;
                                }
                            }
                            array[i][j] = 0;
                        }
                        return false;
                    }
                }
            }
            return true;
        }
    private:
        int array[9][9];
        int checked;
        bool finished;
        bool correct;
};