#include <iostream>
#include <cstdlib>

int* onemss(int** mss, int strok, int stolb) { //первая функция из условия
    int pos = 0;
    int* nullstolb = (int*)calloc(stolb + 1, sizeof(int));
    for (int j = 0; j < stolb; j++) {
        for (int i = 0; i < strok; i++) {
            if (mss[i][j] == 0) {
                nullstolb[pos] = j + 1;
                pos += 1;
                break;
            }
        }
    }
    nullstolb[pos] = 0;
    nullstolb = (int*)realloc(nullstolb, (pos + 1) * sizeof(int));
    return nullstolb;
}



int main() {
    setlocale(LC_ALL, "Russian");
    int** mss = (int**)calloc(2, sizeof(int*));
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
            mss = (int**)calloc(2, sizeof(int*));
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
            mss[i][j] = (i - 1) * C + (j - 1) * D;
        }
    }
    for (int i = 2; i < nstrok; i++) {
        for (int j = 0; j < 2; j++) {
            mss[i][j] = (i - 1) * C + (j - 1) * D;
        }
    }
    int* xc = onemss(mss, nstrok, nstolb);
    std::cout << "Столбцы с нулями = ";
    bool n = false;
    for (int i = 0; xc[i] != 0; i++) {
        std::cout << xc[i] << " ";
        n = true;
    }
    if (n == false) {
        std::cout << "таких нету";
    }
    std::cout << std::endl;
    for (int j = 0; j < nstolb; j++) {
        bool h = false;
        for (int i = 0; i < nstrok; i++) {
            if (mss[i][j] == 0) {
                h = true;
                break;
            }
        }
        if (h) {
            int swap = -1;
            for (int k = j + 1; k < nstolb; k++) {
                bool kh = false;
                for (int i = 0; i < nstrok; i++) {
                    if (mss[i][k] == 0) {
                        kh = true;
                        break;
                    }
                }
                if (!kh) {
                    swap = k;
                    break;
                }
            }
            if (swap != -1) {
                for (int i = 0; i < nstrok; i++) {
                    int seyf = mss[i][j];
                    mss[i][j] = mss[i][swap];
                    mss[i][swap] = seyf;
                }
            }
        }
    }
    int kfulls = 0;
    for (int j = 0; j < nstolb; j++) {
        bool h = false;
        for (int i = 0; i < nstrok; i++) {
            if (mss[i][j] == 0) {
                h = true;
                break;
            }
        }
        if (!h) {
            kfulls += 1;
        }
    }
    if (kfulls < nstolb) {
        for (int i = 0; i < nstrok; i++) {
            mss[i] = (int*)realloc(mss[i], kfulls * sizeof(int));
            if (mss[i] == nullptr) {
                std::cerr << "у нас больше нет матрицы" << std::endl;
                return 1;
            }
        }
        nstolb = kfulls;
    }
    for (int i = 0; i < nstrok; i++) {
        std::cout << "| ";
        for (int j = 0; j < nstolb; j++) {
            std::cout << mss[i][j] << "\t";
        }
        std::cout << "|" << std::endl;
    }

    free(xc);
    for (int i = 0; i < nstrok; i++) {
        free(mss[i]);
    }
    free(mss);
}