#include <vector>
#include <iostream>

std::vector<int> element(std::vector<int>& vec) {
    std::vector<int> vector = vec;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] % 2 == 0) {
            vector[i] *= 2;
        }
        else {
            vector[i] *= -1;
        }
    }
    return vector;
}
void print(const std::vector<int>& vec) {
    for (int xmss : vec) {
        std::cout << xmss << " ";
    }
}
void plusbegin(std::vector<int>& vec, int b) {
    vec.insert(vec.begin(), b);
}
void write(std::vector<int>& vec, int g) {
    vec.reserve(vec.size() + 1);
    vec.push_back(g);
}
int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::vector<int> mss = { 1, 32, 4 };
    std::vector<int> first_mss = mss;
    int a;
    do {
        std::cout << "выбери действие\nвыйти = 0\nпросмотр массива = 1\nдобавить число в начало = 2\nдобавить число в конец массива = 3\nОчистка всего массива = 4\nПоиск элемента в массиве = 5\nВывести до/после = 6" << std::endl;
        std::cin >> a;
        if (a == 0) {
            std::cout << "Результат до/после редактирования четных и нечетных чисел) соответсвенно: ";
            print(first_mss);
            std::cout << "/ ";
            print(element(mss));
            std::cout << "Пока";
            return 0;
        }
        if (a == 1) {
            system("cls");
            std::cout << "массив: ";
            print(mss);
            std::cout << std::endl;
            std::cout << "массив(ред. числа): ";
            print(element(mss));
            std::cout << std::endl;
            std::cout << "----------------------------------------------------" << std::endl;
        }
        if (a == 2) {
            system("cls");
            std::cout << "введите число: ";
            int b;
            std::cin >> b;
            plusbegin(mss, b);
            std::cout << std::endl;
        }
        if (a == 3) {
            system("cls");
            std::cout << "введите число: ";
            int g;
            std::cin >> g;
            write(mss, g);
            system("cls");
        }
        if (a == 4) {
            system("cls");
            mss.clear();
            std::cout << "Массив очищен";
            std::cout << std::endl;
            std::cout << "----------------------------------------------------" << std::endl;
        }
        if (a == 5) {
            system("cls");
            if (mss.size() == 0) {
                std::cout << "массив пуст\n";
                std::cout << "----------------------------------------------------" << std::endl;
                continue;
            }
            int n;
            std::cout << "Введите количество выводимых чисел: ";
            std::cin >> n;
            while (n < 0) {
                std::cout << "Бро число не должно быть отрицательным: ";
                std::cin >> n;
            }
            std::vector<int> ind(n);
            std::cout << "Введите индексы чисел: ";
            for (int i = 0; i < n; i++) {
                int index;
                std::cin >> index;
                while (index >= mss.size()) {
                    std::cout << "такого индекса нету в массиве(введи заного)";
                    std::cin >> index;
                }
                ind[i] = index;
            }
            for (int i = 0; i < ind.size(); i++) {
                int index = ind[i];
                std::cout << mss[index] << " ";
            }
            std::cout << std::endl;
            std::cout << "----------------------------------------------------" << std::endl;
        }
        if (a == 6) {
            system("cls");
            std::cout << "Результат до/после соответсвенно: ";
            print(first_mss);
            std::cout << "/ ";
            if (mss.size() == 0) {
                std::cout << "массив пуст";
            }
            print(element(mss));
            std::cout << "\n----------------------------------------------------" << std::endl;
        }
    } while (true);

}