#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class shape {
public:
	static shape* In(ifstream& ifst);
	virtual void OutComplex(ofstream& ofst); // виртуальная функция вывода только комплексных чисел
	virtual void InData(ifstream& ifst) = 0; // ââîä
	virtual void Out(ofstream& ofst) = 0; // âûâîä
	virtual double Real() = 0; // новая функция (2.3)
	// сравнение двух объектов
	bool Compare(shape& other);
};

class ccomplex: public shape {
	double real, imag; // äåéñòâèòåëüíàÿ è ìíèìàÿ ÷àñòè
	public:
		void InData(ifstream& ifst); // ââîä
		void Out(ofstream& ofst); // âûâîä
		double Real(); // приведение к действительному
		ccomplex() {} // ñîçäàíèå áåç èíèöèàëèçàöèè.
		void OutComplex(ofstream& ofst);
};

class fractions: public shape {
	int x, y; // ÷èñëèòåëü è çíàìåíàòåëü
	std::string unit; // добавление нового поля в специализацию
	public:
		void InData(ifstream& ifst); // ââîä
		void Out(ofstream& ofst); // âûâîä
		double Real(); // приведение к действительному
		fractions() {} // ñîçäàíèå áåç èíèöèàëèçàöèè.
};

class polar_coordinates : public shape {
	double angle;
	int distance;
	public:
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		polar_coordinates() {} // создание без инициализации.
};

class container {
	enum { max_len = 100 }; 
	int len; 
	shape *cont[max_len];
	public: 
		void In(ifstream& ifst); 
		void Out(ofstream& ofst); 
		void Real(ofstream& ofst); 
		void Sort(); // сортировка контейнерa
		void Clear(); 
		container(); 
		~container() { Clear(); } 
		void OutComplex(ofstream& ofst);
};
