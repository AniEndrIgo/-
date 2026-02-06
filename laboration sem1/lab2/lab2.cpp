#include <iostream>
#include <stdlib.h>

int cnt = 0;

void PrintMat(int** mat, int a, int b) {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintArr(int* arr) {
    for (int i = 0; i < cnt; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

int* FindRows(int** mat, int rows, int colls) {
    int* FoundRows = (int*)calloc(rows, sizeof(int));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colls; ++j) {
            if (mat[i][j] == 0) {
                FoundRows[cnt] = i;
                cnt += 1;
                break;
            }
        }
    }
    int* NewFoundRows = (int*)realloc(FoundRows, cnt * sizeof(int));
    return NewFoundRows;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Пункт №1
    int** mat = (int**)calloc(2, sizeof(int)); // Создание матрицы 2х2
    for (int i = 0; i < 2; ++i) {
        mat[i] = (int*)calloc(2, sizeof(int));
    }
    // Заполнение изначальной матрицы
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cin >> mat[i][j];
        }
    }
    std::cout << std::endl;
    PrintMat(mat, 2, 2);
    int a = mat[0][0];
    int b = mat[0][1];
    int c = mat[1][0];
    int d = mat[1][1];

    // Новая матрица
    int rows = 2 + a;
    int colls = 2 + b;
    int** NewMat = (int**)realloc(mat, rows * sizeof(int));
    for (int i = 0; i < colls; ++i) {
        if (i < 2) {
            NewMat[i] = (int*)realloc(mat[i], colls * sizeof(int));
        }
        else {
            NewMat[i] = (int*)calloc(colls, sizeof(int));
        }
    }

    PrintMat(NewMat, rows, colls);

    NewMat[rows - 1][colls - 1] = d;
    NewMat[rows - 1][colls - 2] = c;
    NewMat[rows - 2][colls - 1] = b;
    NewMat[rows - 2][colls - 2] = a;

    PrintMat(NewMat, rows, colls);

    // Заполнение новой матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < colls; ++j) {
            if (i < a || j < b) NewMat[i][j] = i * c + j * d;
        }
    }
    PrintMat(NewMat, rows, colls);

    // Поиск строк, содержащих 0
    int* ZeroRows = FindRows(NewMat, rows, colls);
    PrintArr(ZeroRows);

    // Перемещение строк и удаление строк, сордержащих 0
    if (cnt == rows) {
        std::cout << "От матрицы ничего не осталось :(" << std::endl;

        //std::cout << "начало конца" << std::endl;
        for (int i = 0; i < rows; i++) {
            //std::cout << "перед фри 1" << std::endl;
            free(NewMat[i]);
            //std::cout << "после фри 1" << std::endl;
        }
        //std::cout << "перед фри 2" << std::endl;
        free(NewMat);

        //std::cout << "Конец";
    }
    else {
        for (int i = 0; i < cnt; ++i) {
            int CurRow = ZeroRows[i];
            for (int x = CurRow; x < rows - 1; ++x) {
                std::swap(NewMat[x], NewMat[x + 1]);
            }
        }
        free(ZeroRows);
        PrintMat(NewMat, rows, colls);

        for (int i = rows - 1; i >= rows - cnt; --i) {
            free(NewMat[i]);
        }
        rows -= cnt;
        //int **NewNewMat = (int**)realloc(NewMat, rows * sizeof(int));
        std::cout << "Итоговая матрица:" << std::endl;
        PrintMat(NewMat, rows, colls);

        //std::cout << "начало конца" << std::endl;
        for (int i = 0; i < rows; i++) {
            //std::cout << "перед фри 1" << std::endl;
            free(NewMat[i]);
            //std::cout << "после фри 1" << std::endl;
        }
        //std::cout << "перед фри 2" << std::endl;
        free(NewMat);

        //std::cout << "Конец";
    }

    //=============================================

    // Пункт №2 с new/delete
        /*
        int a, b;
        std::cin >> a >> b;

        int* ptrA = new int;
        int* ptrB = new int;
        *ptrA = a;
        *ptrB = b;

        *ptrA *= 2;
        a = *ptrA;
        std::cout << "a = " << a << ", b = " << b << std::endl;