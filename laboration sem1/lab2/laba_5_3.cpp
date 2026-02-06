#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    int A[100][100];

    cout << "Введите количество строк";
    cin >> n;
    cout << "Введите количество столбцов ";
    cin >> m;

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    
    int maxSum = -1;
    int maxRow = 0;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += A[i][j];
        }
        int absSum = abs(sum);
        if (absSum > maxSum) {
            maxSum = absSum;
            maxRow = i;
        }
    }
    for (int j = 0; j < m; j++) {
        A[maxRow][j] = 9999;
    }
    
    cout << "Ответ " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}