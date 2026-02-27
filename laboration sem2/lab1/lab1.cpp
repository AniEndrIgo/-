#include <iostream>
#include <string>

class Blank {
public:
	Blank(): name_("igor"), surname_("androsov"), direction_("informatika & matematika"), curs_(1), group_(2), var_(1) {
		std::cerr << "ctor = default" << std::endl;
	}
	Blank(const std::string& name_, const std::string& surname_, const std::string& direction_, int curs_, int group_, int var_) {
		std::cerr << "ctor = full" << std::endl;

		set_name(name_);
		set_surname(surname_);
		set_direction(direction_);
		set_curs(curs_);
		set_group(group_);
		set_var(var_);
	}
	Blank(const Blank& other) {
		std::cerr << "ctor = copy" << std::endl;
		name_ = other.name_;
		surname_ = other.surname_;
		direction_ = other.direction_;
		curs_ = other.curs_;
		group_ = other.group_;
		var_ = other.var_;
	}
	~Blank() {
		std::cerr << "dtor runned" << std::endl;
	}

	//СЕТТЕРЫ-------------------------------------------------------------------------------------
	void set_var(int var) {
		if (var < 1 || var > 8) {
			throw std::invalid_argument("var no valid");
		}
		var_ = var;
	}
	void set_curs(int curs) {
		if (curs < 1 || curs > 5) {
			throw std::invalid_argument("curs no valid");
		}
		curs_ = curs;
	}
	void set_group(int group) {
		if (group < 1 || group > 3) {
			throw std::invalid_argument("group no valid");
		}
		group_ = group;
	}
	void set_name(const std::string& name) {
		if (name.empty()) {
			throw std::invalid_argument("name no have");
		}
		name_ = name;
	}
	void set_surname(const std::string& surname) {
		if (surname.empty()) {
			throw std::invalid_argument("surname no have");
		}
		surname_ = surname;
	}
	void set_direction(const std::string& direction) {
		if (direction.empty()) {
			throw std::invalid_argument("direction no have");
		}
		direction_ = direction;
	}

	//ГЕТТЕРЫ-------------------------------------------------------------------------------------
	std::string get_name() const {
		return name_;
	}
	std::string get_surname() const {
		return surname_;
	}
	std::string get_direction() const {
		return direction_;
	}
	int get_curs() const {
		return curs_;
	}
	int get_group() const {
		return group_;
	}
	int get_var() const {
		return var_;
	}

	void printInfo() const {
		std::cout << "Информация о студенте:" << std::endl;
		std::cout << "Имя: " << name_ << std::endl;
		std::cout << "Фамилия: " << surname_ << std::endl;
		std::cout << "Направление: " << direction_ << std::endl;
		std::cout << "Курс: " << curs_ << std::endl;
		std::cout << "Группа: " << group_ << std::endl;
		std::cout << "Вариант: " << var_ << std::endl;
	}
	void next_course() {
		if (curs_ < 5) {
			curs_++;
			std::cout << name_ << " " << surname_ << " переведен на " << curs_ << " курс" << std::endl;
		}
		else {
			std::cout << name_ << " " << surname_ << " уже на последнем курсе" << std::endl;
		}
	}

private:
	std::string name_;
	std::string surname_;
	std::string direction_;
	int curs_;
	int group_;
	int var_;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Blank blank1;
	blank1.printInfo();
	std::cout << "-------------------" << std::endl;
	std::cout << "Использование геттеров:" << std::endl;
	std::cout << "Имя: " << blank1.get_name() << std::endl;
	std::cout << "Фамилия: " << blank1.get_surname() << std::endl;
	std::cout << "Направление: " << blank1.get_direction() << std::endl;
	std::cout << "Курс: " << blank1.get_curs() << std::endl;
	std::cout << "Группа: " << blank1.get_group() << std::endl;
	std::cout << "Вариант: " << blank1.get_var() << std::endl;
	std::cout << "==================================================================================================================" << std::endl;


	Blank blank2("leonid", "pechevisty", "informatika & matematika", 1, 2, 3);
	blank2.printInfo();

	std::cout << "-------------------Вывод через сеттеры-------------------" << std::endl;

	try {
		blank1.set_name("anton");
		blank1.set_surname("ushakov");
		blank1.set_direction("informatika & matematika");
		blank1.set_curs(1);
		blank1.set_group(2);
		blank1.set_var(6);

		blank1.printInfo();
	}
	catch (const std::exception& ex) {
		std::cerr << "Ошибка: " << ex.what() << std::endl;
	}

	std::cout << "-------------------Перевод на next курс-------------------" << std::endl;
	blank2.next_course();
	std::cout << "Прошел год:" << std::endl;
	blank2.printInfo();
	
	std::cout << "==================================================================================================================" << std::endl;
	Blank blank3 = blank2;
	blank3.printInfo();
	std::cout << "-------------------Используем сеттеры на копию-------------------" << std::endl;
	blank3.set_name("anton");
	blank3.set_surname("ushakov");
	blank3.printInfo();

	std::cout << "-------------------Вывод неправильных данных через сеттеры-------------------" << std::endl;
	try {
		blank1.set_name("");
	}
	catch (const std::exception& ex) {
		std::cerr << "Имя: " << ex.what() << std::endl;
	}
	try {
		blank1.set_curs(0);
	}
	catch (const std::exception& ex) {
		std::cerr << "Курс: " << ex.what() << std::endl;
	}
	try {
		blank1.set_group(-1);
	}
	catch (const std::exception& ex) {
		std::cerr << "Группа: " << ex.what() << std::endl;
	}
	try {
		blank1.set_var(10);
	}
	catch (const std::exception& ex) {
		std::cerr << "Вариант: " << ex.what() << std::endl;
	}

	return 0;
}