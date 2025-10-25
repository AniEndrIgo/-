#include <iostream>
#include <cmath>
#include <typeinfo>
#include <limits>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	cout << sizeof(int) * 8 << " - это значение в битах";
	cout << "\nнижняя граница:" << INT_MAX << "\nверхняя граница:" << INT_MIN << "\n(это границы int)" << endl;

	cout << sizeof(float) * 8 << " - это значение в битах";
	cout << "\nнижняя граница:" << numeric_limits<float>::lowest() << "\nверхняя граница:" << FLT_MAX << "\n(это границы float)" << endl;

	int a, b;// int т.к по условию катеты целочисленные
	cout << "\nЗадайте длины катетов 1-го и 2-го через пробел" << endl;
	cin >> a >> b;

	float gip = sqrt((pow(a, 2) + pow(b, 2))); // float т.к гипотенуза не обязательно целочисленное число
	cout << "\nЗначение гипотенузы:" << gip << "(" << typeid(gip).name() << ")" << endl;

	float p = (a + b + gip);
	cout << "\nЗначение периметра:" << p << "(" << typeid(p).name() << ")" << endl;

	return 0;
}