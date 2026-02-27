#include "blank.hpp"
#include <iostream>
#include <exception>
#include <string>

namespace mt {
	Blank::Blank() : name_("igor"), surname_("androsov"), dolg_{ "matematika", "fizika" } {
		std::cerr << "ctor = default" << std::endl;
	}
	Blank::Blank(const std::string& name_, const std::string& surname_, const std::vector<std::string>& dolg)) {
		std::cerr << "ctor = full" << std::endl;

		set_name(name_);
		set_surname(surname_);
		set_dolg(dolg);
	}
	Blank::Blank(const Blank& other) {
		std::cerr << "ctor = copy" << std::endl;
		name_ = other.name_;
		surname_ = other.surname_;
		dolg_ = other.dolg_;
	}
	Blank::~Blank() {
		std::cerr << "dtor runned" << std::endl;
		dolg_.clear();
		std::cerr << "dtor finished" << std::endl;
	}

	Blank& Blank::operator=(const Blank& other) {
		std::cerr << "operator= called" << std::endl;

		if (this != &other) {
			name_ = other.name_;
			surname_ = other.surname_;
			dolg_ = other.dolg_;
		}
		return *this;
	}

	Blank Blank::operator+(const Blank& other) const {
		std::cerr << "operator+ called" << std::endl;

		std::string new_name = name_ + " и " + other.name_;
		std::string new_surname = surname_ + " и " + other.surname_;
		std::vector<std::string> new_dolg = merge(dolg_, other.dolg_);

		return Blank(new_name, new_surname, new_dolg);
	}

	Blank& Blank::operator-=(const Blank& other) {
		std::cerr << "operator-= called" << std::endl;

		name_ = name_ + " без " + other.name_;
		surname_ = surname_ + " без " + other.surname_;
		dolg_ = down(dolg_, other.dolg_);

		return *this;
	}

	Blank Blank::operator/(const Blank& other) const {
		std::cerr << "operator/ called" << std::endl;

		std::string new_name = name_ + " и " + other.name_;
		std::string new_surname = surname_ + " и " + other.surname_;
		std::vector<std::string> new_dolg = detect(dolg_, other.dolg_);

		return Blank(new_name, new_surname, new_dolg);
	}

	void Blank::set_name(const std::string& name) {
		if (name.empty()) {
			throw std::invalid_argument("name no have");
		}
		name_ = name;
	}
	void Blank::set_surname(const std::string& surname) {
		if (surname.empty()) {
			throw std::invalid_argument("surname no have");
		}
		surname_ = surname;
	}
	void Blank::set_dolg(const std::vector<std::string>& dolg) {dolg_ = dolg;}
	void Blank::add_debt(const std::string& debt) {
		if (debt.empty()) {
			throw std::invalid_argument("debt no have");
		}
		dolg_.push_back(debt);
	}
	std::string Blank::get_name() const { return name_;}
	std::string Blank::get_surname() const { return surname_;}

	void Blank::printInfo() const {
		std::cout << "Информация о студенте:" << std::endl;
		std::cout << "Имя: " << name_ << std::endl;
		std::cout << "Фамилия: " << surname_ << std::endl;
		std::cout << "Долги: ";
		if (dolg_.empty()) {
			std::cout << "нет";
		}
		else {
			for (size_t i = 0; i < dolg_.size(); ++i) {
				std::cout << dolg_[i];
				if (i < dolg_.size() - 1) std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
	std::vector<std::string> Blank::merge(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
		std::vector<std::string> result = v1;

		for (const auto& item : v2) {
			if (std::find(result.begin(), result.end(), item) == result.end()) {
				result.push_back(item);
			}
		}

		return result;
	}
	std::vector<std::string> Blank::down(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
		std::vector<std::string> result;

		for (const auto& item : v1) {
			if (std::find(v2.begin(), v2.end(), item) == v2.end()) {
				result.push_back(item);
			}
		}

		return result;
	}
	std::vector<std::string> Blank::detect(const std::vector<std::string>& v1, const std::vector<std::string>& v2) {
		std::vector<std::string> result;

		for (const auto& item : v1) {
			if (std::find(v2.begin(), v2.end(), item) != v2.end()) {
				if (std::find(result.begin(), result.end(), item) == result.end()) {
					result.push_back(item);
				}
			}
		}

		return result;
	}
}