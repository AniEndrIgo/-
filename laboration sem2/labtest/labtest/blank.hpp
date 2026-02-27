#pragma once 
#include <string>

namespace mt {
	class Blank {
	public:
		Blank();
		Blank(const std::string& name_, const std::string& surname_, const std::vector<std::string>& dolg);
		Blank(const Blank& other);
		~Blank();

		Blank& operator=(const Blank& other);  // Оператор присваивания
		Blank operator+(const Blank& other) const;  // Оператор сложения
		Blank& operator-=(const Blank& other);  // Оператор -= 
		Blank operator/(const Blank& other) const;  // Оператор деления

		//СЕТТЕРЫ-------------------------------------------------------------------------------------
		void set_name(const std::string& name);
		void set_surname(const std::string& surname);
		void set_dolg(const std::vector<std::string>& dolg);
		void add_dolg(const std::string& dolg);

		//ГЕТТЕРЫ-------------------------------------------------------------------------------------
		std::string get_name() const;
		std::string get_surname() const;
		std::vector<std::string> get_dolg() const;

		void printInfo() const;

	private:
		std::string name_;
		std::string surname_;
		static std::vector<std::string> merge(const std::vector<std::string>& v1, const std::vector<std::string>& v2);
		static std::vector<std::string> down(const std::vector<std::string>& v1, const std::vector<std::string>& v2);
		static std::vector<std::string> detect(const std::vector<std::string>& v1, const std::vector<std::string>& v2);
	};
	};
}