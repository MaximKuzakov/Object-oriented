#pragma once
#include <fstream>
#include <string>
using namespace std;

// Êëàññ, îáîáùàþùàåò âñå èìåþùèåñÿ ôèãóðû.
// ßâëÿåòñÿ àáñòðàêòíûì, îáåñïå÷èâàÿ, òåì ñàìûì ïðîâåðêó èíòåðôåéñà
class shape {
public:
	// èäåíèòôèêàöèÿ, ïîðîæäåíèå è ââîä ôèãóðû èç ïîòîêà
	static shape* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ââîä
	virtual void Out(ofstream& ofst) = 0; // âûâîä
};
class ccomplex: public shape
{
	double real, imag; // äåéñòâèòåëüíàÿ è ìíèìàÿ ÷àñòè
	public:
		void InData(ifstream& ifst); // ââîä
		void Out(ofstream& ofst); // âûâîä
		ccomplex() {} // ñîçäàíèå áåç èíèöèàëèçàöèè.
};
class fractions: public shape
{
	int x, y; // ÷èñëèòåëü è çíàìåíàòåëü
	std::string unit; // добавление нового поля в специализацию
	public:
		void InData(ifstream& ifst); // ââîä
		void Out(ofstream& ofst); // âûâîä
		fractions() {} // ñîçäàíèå áåç èíèöèàëèçàöèè.
};
class polar_coordinates : public shape
{
	double angle;
	int distance;
	public:
		void InData(ifstream& ifst); // ввод
		void Out(ofstream& ofst); // вывод
		polar_coordinates() {} // создание без инициализации.
};
// Ïðîñòåéøèé êîíòåéíåð íà îñíîâå îäíîìåðíîãî ìàññèâà
class container {
	enum { max_len = 100 }; // ìàêñèìàëüíàÿ äëèíà
	int len; // òåêóùàÿ äëèíà
	shape *cont[max_len];
	public: 
		void In(ifstream& ifst); // ââîä
		void Out(ofstream& ofst); // âûâîä
		void Clear(); // î÷èñòêà êîíòåéíåðà îò ôèãóð
		container(); // èíèöèàëèçàöèÿ êîíòåéíåðà
		~container() { Clear(); } // óòèëèçàöèÿ êîíòåéíåðà
};
