#include <iostream>
#include <array>
void sortcopy(std::array<int, 10> arr, bool var) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            bool swap = false;

            switch (var) {
            case true:
                if (arr[j] > arr[j + 1]) swap = true;
                break;
            case false:
                if (arr[j] < arr[j + 1]) swap = true;
                break;
            }

            if (swap) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void sortoriginal(std::array<int, 10>& arr, bool var) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minmax = i;
        for (int j = i + 1; j < arr.size(); j++) {
            switch (var) {
            case true:
                if (arr[j] < arr[minmax]) minmax = j;
                break;
            case false:
                if (arr[j] > arr[minmax]) minmax = j;
                break;
            }
        }
        if (minmax != i) {
            int dos = arr[i];
            arr[i] = arr[minmax];
            arr[minmax] = dos;
        }
    }
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void sortukaz(std::array<int, 10>* arr, bool var) {
    for (int i = 1; i < arr->size(); i++) {
        int h = (*arr)[i];
        int j = i - 1;
        while (j >= 0) {
            bool swap = false;
            switch (var) {
            case true:
                if ((*arr)[j] > h) swap = true;
                break;
            case false:
                if ((*arr)[j] < h) swap = true;
                break;
            }
            if (!swap) break;
            (*arr)[j + 1] = (*arr)[j];
            j--;
        }
        (*arr)[j + 1] = h;
    }
    for (int num : *arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void print(const std::array<int, 10>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    std::srand(std::time(nullptr));
    std::array<int, 10> mss;
    for (int i = 0; i < 10; i++) {
        mss[i] = std::rand() % 21 - 10;
    }
    std::cout << "Массив случайных чисел от -10 до 10:" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << mss[i] << " ";
    }
    std::cout << std::endl;
    std::array<int, 10> original = mss;
    std::cout << "\n1.ПЕРЕДАЧА ПО ЗНАЧЕНИЮ:" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "исходный массив:";
    print(original);
    std::cout << "сортировка по возрастанию:";
    sortcopy(original, true);
    std::cout << "сортировка по убыванию:";
    sortcopy(original, false);
    std::cout << "исходный массив теперь: ";
    print(original);
    std::cout << "Массив не изменился тк функция изменила копию" << std::endl;
    std::cout << "\n2.ПЕРЕДАЧА ПО ССЫЛКЕ:" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    original = mss;
    std::cout << "исходный массив:";
    print(original);
    std::cout << "сортировка по возрастанию:";
    sortoriginal(original, true);
    std::cout << "сортировка по убыванию:";
    sortoriginal(original, false);
    std::cout << "исходный массив теперь: ";
    print(original);
    std::cout << "Массив изменился тк работали с оригиналом" << std::endl;
    std::cout << "\n3.ПЕРЕДАЧА ПО УКАЗАТЕЛЮ:" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    original = mss;
    std::cout << "исходный массив:";
    print(original);
    std::cout << "сортировка по возрастанию:";
    sortukaz(&original, true);
    std::cout << "сортировка по убыванию:";
    sortukaz(&original, false);
    std::cout << "исходный массив теперь: ";
    print(original);
    std::cout << "Массив изменился тк работали с оригиналом" << std::endl;
}