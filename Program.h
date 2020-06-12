#pragma once
#include <fstream>
using namespace std;

// Класс, обобщающает все имеющиеся фигуры.
// Является абстрактным, обеспечивая, тем самым проверку интерфейса
class shape {
public:
	// иденитфикация, порождение и ввод фигуры из потока
	static shape* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
};
class ccomplex: public shape
{
	double real, imag; // действительная и мнимая части
	public:
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		ccomplex() {} // создание без инициализации.
};
class fractions: public shape
{
	int x, y; // числитель и знаменатель
	public:
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		fractions() {} // создание без инициализации.
};
// Простейший контейнер на основе одномерного массива
class container {
	enum { max_len = 100 }; // максимальная длина
	int len; // текущая длина
	shape *cont[max_len];
	public: 
		void In(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		void Clear(); // очистка контейнера от фигур
		container(); // инициализация контейнера
		~container() { Clear(); } // утилизация контейнера
};