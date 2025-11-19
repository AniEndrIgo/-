#include <iostream>
#include <cstdlib>

int* onemss(int** mss, int strok, int stolb) { //первая функция из условия
    int pos = 0;
    int* nullstolb = (int*)calloc(stolb, sizeof(int));
    for (int j = 0; j < stolb; j++) {
        for (int i = 0; i < strok; i++) {
            if (mss[i][j] == 0) {
                nullstolb[pos] = j+1;
                pos += 1;
                break;
            }
        }
    }
    return nullstolb;
}



int main() {
    setlocale(LC_ALL, "Russian");
    int** mss = (int**)calloc(2, sizeof(int**));
    for (int i = 0; i < 2; i++) {
        mss[i] = (int*)calloc(2, sizeof(int));
    }
    while (true) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                std::cin >> mss[i][j];
            }
        }
        if (mss[0][0] < 0 || mss[0][1] < 0) {
            std::cout << "error, false option. rewrite pls" << std::endl;
            free(mss[0]);
            free(mss[1]);
            free(mss);
            mss = (int**)calloc(2, sizeof(int**));
            for (int i = 0; i < 2; i++) {
                mss[i] = (int*)calloc(2, sizeof(int));
            }
        }
        else {
            std::cout << "nexting" << std::endl;
            break;
        }
    }
    int A = mss[0][0];
    int B = mss[0][1];
    int C = mss[1][0];
    int D = mss[1][1];
    int nstrok = 2 + A;
    int nstolb = 2 + B;
    mss = (int**)realloc(mss, nstrok * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        mss[i] = (int*)realloc(mss[i], nstolb * sizeof(int));
    }
    for (int i = 2; i < nstrok; i++) {
        mss[i] = (int*)calloc(nstolb, sizeof(int));
    }
    for (int i = 0; i < nstrok; i++) {
        for (int j = 2; j < nstolb; j++) {
            mss[i][j] = (i - 1) * C + (j - 1) * D;//для формулы заполнения у меня не хватит мозгов так, что попросил у дипсика
        }
    }
    for (int i = 2; i < nstrok; i++) {
        for (int j = 0; j < 2; j++) {
            mss[i][j] = (i - 1) * C + (j - 1) * D;
        }
    }
    //for (int i = 0; i < nstrok; i++) {
    //    std::cout << "| ";
    //    for (int j = 0; j < nstolb; j++) {
    //        std::cout << mss[i][j] << "\t";
    //    }
    //    std::cout << "|" << std::endl;
    //}//вывод оригинальной матрицы

    for (int i = 0; i < nstrok; i++) {//вывод матрицы с игнорированием столбцов с нулями
        std::cout << "| ";
        for (int j = 0; j < nstolb; j++) {
            bool h = false;
            for (int k = 0; k < nstrok; k++) {
                if (mss[k][j] == 0) {
                    h = true;
                    break;
                }
            }
            if (!h) {
                std::cout << mss[i][j] << "\t";
            }
        }
        std::cout << "|" << std::endl;
    }
    int* xc = onemss(mss, nstrok, nstolb);
    std::cout << "Столбцы с нулями = ";
    bool n = false;
    for (int i = 0; i < nstolb; i++) {
        if (xc[i] != 0) {
            std::cout << xc[i] << " ";
            n = true;
        }
    }
    if (n == false) {
        std::cout << "таких нету";
    }
    free(xc);
    for (int i = 0; i < nstrok; i++) {
        free(mss[i]);
    }
    free(mss);

    //int a, b;
    //std::cin >> a >> b;

    //int* A = new int;
    //int* B = new int;
    //*A = a;
    //*B = b;

    //*A = *A * 3;
    //b = *A;
    //a = *B;
    //std::cout << "a = " << a << " b = " << b << std::endl;

    //int AA = *A;
    //*A = *B;
    //*B = AA;
    //std::cout << "a = " << a << " b = " << b << std::endl;

    //delete A;
    //delete B;
}