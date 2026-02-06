#include <iostream>
//изменения уже измененных переменных в начальный вид не является изменением?(32 строка)
//45-строка ошибка с переизбытком памяти на лекции но у меня нету
//принцип 1 - Абстракция
//принцип 2 - Инкапсулляция
//class
class Car {
public:
	Car(int n) :arr_(new int[n_]), n_(n) {
		std::cerr << "ctor" << std::endl;
	}
	~Car() {
		delete[] arr_;
		std::cerr << "dtor" << std::endl;
	}
	Car(int x, int y, float r) :x_(x), y_(y), r_(r) {
		std::cerr << "ctor param" << std::endl;
	}
	//метод
	void move() {
		x_ += 10;
		y_ += 10;
	}
	//сеттер
	void set_r(float r) {
		if (is_radius_valid_(r)) {
			return;
		}
		r_ = r;
	}
	//геттер
	int get_x() const { return x_; }
private:
	bool is_radius_valid_(float r) {
		if (r < 0.01) {
			throw std::invalid_argument("radius useless");
		}
	}
private:
	int x_;
	int y_;
	float r_;

	int* arr_;
	int n_;
};

void intersect(const Car c1, const Car c2) {
	c1.get_x();
}
int main()
{
	try {
		/*Car car(10); //Объект
		std::cerr << "===" << std::endl;
		car.set_r(1);
		std::cerr << "===" << std::endl;
		*/
		Car* car = new Car(100);
		//delete car;
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
	}
	catch (const std::bad_alloc& ex) {
		std::cerr << ex.what() << std::endl;
	}

}
