#include <iostream>
#include "blank.hpp"
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");
	mt::Blank blank1;
	blank1.printInfo();
	std::cout << "-------------------" << std::endl;
	std::cout << "Использование геттеров:" << std::endl;
	std::cout << "Имя: " << blank1.get_name() << std::endl;
	std::cout << "Фамилия: " << blank1.get_surname() << std::endl;
	std::cout << "Долги: ";
	std::vector<std::string> dolg1 = blank1.get_dolg();
	for (std::vector<std::string>::size_type i = 0; i < dolg1.size(); ++i) {
		std::cout << dolg1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "-------------------Студенты с долгами-------------------" << std::endl;
	std::vector<std::string> dolg2 = { "matanalyz", "istoria", "programmirovanie" };
	mt::Blank blank2("leonid", "pechevisty", dolg2);
	std::cout << "\nblank2:" << std::endl;
	blank2.printInfo();

	std::vector<std::string> dolg3 = { "matanalyz", "istoria", "algebra" };
	mt::Blank blank3("anton", "ushakov", dolg3);
	std::cout << "\nblank3:" << std::endl;
	blank3.printInfo();

	std::cout << "-------------------ТЕСТ 3: Оператор + (объединение долгов)-------------------" << std::endl;

	mt::Blank blank4 = blank2 + blank3;
	std::cout << "Результат blank2 + blank3:" << std::endl;
	blank4.printInfo();

	std::cout << "-------------------ТЕСТ 4: Оператор -= (вычитание долгов)-------------------" << std::endl;

	mt::Blank blank5 = blank2;
	std::cout << "До вычитания (blank5 - копия blank2):" << std::endl;
	blank5.printInfo();

	blank5 -= blank3;
	std::cout << "После blank5 -= blank3:" << std::endl;
	blank5.printInfo();

	std::cout << "-------------------ТЕСТ 5: Оператор / (общие долги)-------------------" << std::endl;

	mt::Blank blank6 = blank2 / blank3;
	std::cout << "Результат blank2 / blank3:" << std::endl;
	blank6.printInfo();

	std::cout << "-------------------ТЕСТ 6: Оператор присваивания-------------------" << std::endl;

	mt::Blank blank7;
	std::cout << "blank7 до присваивания:" << std::endl;
	blank7.printInfo();

	blank7 = blank2;
	std::cout << "blank7 после blank7 = blank2:" << std::endl;
	blank7.printInfo();

	std::cout << "-------------------ТЕСТ 7: Добавление долга через add_debt-------------------" << std::endl;

	blank1.add_debt("angliyskiy");
	std::cout << "blank1 после add_debt(angliyskiy):" << std::endl;
	blank1.printInfo();

	std::cout << "-------------------Вывод неправильных данных-------------------" << std::endl;
	try {
		std::cout << "Попытка установить пустое имя:" << std::endl;
		blank1.set_name("");
	}
	catch (const std::exception& ex) {
		std::cerr << "Ошибка: " << ex.what() << std::endl;
	}
	try {
		std::cout << "Попытка добавить пустой долг:" << std::endl;
		blank1.add_debt("");
	}
	catch (const std::exception& ex) {
		std::cerr << "Ошибка: " << ex.what() << std::endl;
	}

	return 0;
}
