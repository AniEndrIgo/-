#include <iostream>
using namespace std;

int main() {
    int n;
    int A[1000];
    
    cout << "Введите n";
    cin >> n;
    
    cout << "Введите " << n << " натуральных чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int num1 = A[j];
            int sum1 = 0;
            while (num1 > 0) {
                sum1 += num1 % 10;
                num1 /= 10;
            }
            
            int num2 = A[j + 1];
            int sum2 = 0;
            while (num2 > 0) {
                sum2 += num2 % 10;
                num2 /= 10;
            }
            
            int first1 = A[j];
            while (first1 >= 10) {
                first1 /= 10;
            }
            
            int first2 = A[j + 1];
            while (first2 >= 10) {
                first2 /= 10;
            }
            
            if (sum1 > sum2) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
            else if (sum1 == sum2) {
                if (first1 > first2) {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
                else if (first1 == first2) {
                    if (A[j] > A[j + 1]) {
                        int temp = A[j];
                        A[j] = A[j + 1];
                        A[j + 1] = temp;
                    }
                }
            }
        }
    }
    
    cout << "Отсортированная последовательность: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}