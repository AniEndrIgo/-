#include <iostream>
#include <cmath>

using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int vv = pow(2, 32) / 2 - 1;
	int nn = pow(-2, 31);//в моем случае int занимает 4 байта
	cout << "нижняя граница:" << nn << "\nверхняя граница:" << vv << "\n(это границы int)" << endl;

	//cout << sizeof(float);посмотреть значение в байтах (вышло 4 байта)
	float vf = pow(10, 38) * 3.4;
	float nf = pow(10, -38) * 1.17;
	cout << "нижняя граница:" << nf << "\nверхняя граница:" << vf << "\n(это границы float)" << endl;

	int a, b;// int т.к по условию катеты целочисленные
	cout << "\nЗадайте длины катетов 1-го и 2-го через пробел" << endl;
	cin >> a >> b;

	float gip = sqrt((pow(a, 2) + pow(b, 2))); // float т.к гипотенуза не обязательно целочисленное число
	cout << "\nЗначение гипотенузы:" << gip << endl;

	float p = (a + b + gip);
	cout << "\nЗначение периметра:" << p << endl;

	return 0;
}