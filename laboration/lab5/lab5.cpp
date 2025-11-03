#include <iostream>
#include <cmath>

int for2(int a, int b) {
    std::cout << "исп. функция 2х чисел" << std::endl;
    return a + 2 * b + 3;
}
int for3a(int a, int b, int c) {
    std::cout << "исп. функция 3х чисел" << std::endl;
    int g = a + b;
    int h = b + c;
    int l = a + c;
    int max = 0;
    if (g > h) {
        h = g;
    }
    if (h > l) {
        l = h;
    }
    else {
        h = l;
    }
    return h;
}
void l1(int a, int b, int c) {
    float gip = sqrt((pow(a, 2) + pow(b, 2))); // float т.к гипотенуза не обязательно целочисленное число
    std::cout << "\nЗначение гипотенузы:" << gip << "(" << typeid(gip).name() << ")";

    float p = (a + b + gip);
    std::cout << "\nЗначение периметра:" << p << "(" << typeid(p).name() << ")";
}
int main() {
    setlocale(LC_ALL, "Russian");
    const int A = 3;
    int mss[A];
    for (int i = 0; i < A; i++) {
        std::cin >> mss[i];
    }
    int cnt = 3;
    for (int i = 0; i < A; i++) {
        if (mss[i] == 0) {
            cnt -= 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (mss[i] == 0) {
            for (int j = i + 1; j < 3; j++) {
                if (mss[j] != 0) {
                    std::swap(mss[i], mss[j]);
                    break;
                }
            }
        }
    }
    int a;
    if ((cnt == 2 || cnt == 3)) {
        if (cnt == 2) {
            std::cout << "a+2b+3="  << for2(mss[0], mss[1]);
        }
        if (cnt == 3) {
            std::cout << "максимальное из попарных сумм = " << for3a(mss[0], mss[1], mss[2]);
        }
    }
    else {
        std::cout << "введенные числа не подходят!";
    }
    l1(mss[0], mss[1], mss[2]);
}