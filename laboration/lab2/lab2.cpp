#include <iostream>
#include <bitset>

using namespace std;
int main() {
	setlocale(LC_ALL, "RUSSIAN");

	short A, i;
	cin >> A >> i;
	bitset<16> BinA = A;
	cout << A << " - " << BinA;

}