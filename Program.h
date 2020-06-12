#pragma once
#include <fstream>
using namespace std;

// �����, ����������� ��� ��������� ������.
// �������� �����������, �����������, ��� ����� �������� ����������
class shape {
public:
	// �������������, ���������� � ���� ������ �� ������
	static shape* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
};
class ccomplex: public shape
{
	double real, imag; // �������������� � ������ �����
	public:
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		ccomplex() {} // �������� ��� �������������.
};
class fractions: public shape
{
	int x, y; // ��������� � �����������
	public:
		void InData(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		fractions() {} // �������� ��� �������������.
};
// ���������� ��������� �� ������ ����������� �������
class container {
	enum { max_len = 100 }; // ������������ �����
	int len; // ������� �����
	shape *cont[max_len];
	public: 
		void In(ifstream& ifst); // ����
		void Out(ofstream& ofst); // �����
		void Clear(); // ������� ���������� �� �����
		container(); // ������������� ����������
		~container() { Clear(); } // ���������� ����������
};