#include <iostream>
#include <limits>
int main()
{
    setlocale(LC_ALL, "Russian");
    const int G = 4;
    int minB = 9;
    int minA = 9;
    int sum = 0;
    std::cout << "введи 4 числа:" << std::endl;
    int massiv[G];
    for (int i = 0; i < 4; i++) {
        std::cin >> massiv[i];
    }
    std::cout << "массив = ";
    for (int i = 0; i < 4; i++) {
        std::cout << massiv[i] << " ";
    }
    std::cout << std::endl;
    while (massiv[0] > 0) {
        int B = massiv[0] % 10;
        if (minB > B)
            minB = B;
        massiv[0] /= 10;
    }
    while (massiv[G - 1] > 0) {
        int A = massiv[G - 1] % 10;
        if (minA > A)
            minA = A;
        massiv[G - 1] /= 10;
    }
    if (minA == minB) {
        for (int i = 0; i < G - 1; i++) {
            for (int j = i + 1; j < G; j++) {
                if (massiv[i] > massiv[j]) {
                    std::swap(massiv[i], massiv[j]);
                }
            }
        }
        std::cout << "\nупорядоченный массив = ";
        for (int i = 0; i < 4; i++) {
            std::cout << massiv[i] << " ";
        }
    }
    std::cout << "введи матрицу 3 на 4:" << std::endl;
    const int strok = 3, stolb = 4;
    int mat[strok][stolb];
    for (int i = 0; i < strok; ++i) {
        for (int j = 0; j < stolb; ++j) {
            std::cin >> mat[i][j];
        }
    }
    int min1 = std::numeric_limits<int>::max();
    int minsumm = 0;
    for (int i = 0; i < strok; i++) {
        int sum = 0;
        for (int j = 0; j < stolb; j++) {
            sum += mat[i][j];
        }
        int minp = std::abs(sum);
        if (minp < min1) {
            min1 = minp;
            minsumm = i;
        }
    }
    for (int j = 0; j < stolb; j++) {
        mat[minsumm][j] = 0;
    }
    std::cout << "\nОбновленная матрица:\n";
    for (int i = 0; i < strok; i++) {
        for (int j = 0; j < stolb; j++) {
            std::cout << mat[i][j];
        }
        std::cout << "\n";
    }
}