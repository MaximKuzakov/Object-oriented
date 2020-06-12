#include "Program.h"
#include <fstream>
#include <iostream>
#include <cmath>
#define when_c_is_full 100
using namespace std;
void ccomplex::InData(ifstream& ifst)
{
    ifst >> real >> imag;
}
void ccomplex::Out(ofstream& ofst)
{
    ofst << "It is a Complex: " << real << " + " << imag << "i" << endl;
    cout << "It is a Complex: " << real << " + " << imag << "i" << endl;
}
void fractions::InData(ifstream& ifst)
{
    ifst >> x >> y;
}
void fractions::Out(ofstream& ofst)
{
    ofst << "It is a Fraction: " << x << "/" << y << endl;
    cout << "It is a Fraction: " << x << "/" << y << endl;
}
shape* shape::In(ifstream& ifst) {
    shape* sp;
    int k;
    ifst >> k;
    switch (k) {
    case 1:
        sp = new ccomplex;
        break;
    case 2:
        sp = new fractions;
        break;
    default:
        return 0;
    }
    sp->InData(ifst);
    return sp;
}
// ������������� ����������
container::container() : len(0) { }
// ������� ���������� �� ��������� (������������ ������)
void container::Clear()
{
    for (int i = 0; i < len; i++)
        delete cont[i];
    len = 0;
}
// ���� ����������� ���������� �� ���������� ������
void container::In(ifstream& ifst)
{

    while (!ifst.eof())
    {
        if ((cont[len] = shape::In(ifst)) != 0)
        {
            len++;
            if (len == when_c_is_full)
            {
                cout << "Container is full" << endl;
                break;
            }
        }
    }
}
// ����� ����������� ���������� � ��������� �����
void container::Out(ofstream& ofst)
{
    ofst << "Container contains " << len << " elements." << endl;
    cout << "Container contains " << len << " elements." << endl;
    for (int i = 0; i < len; i++)
    {
        ofst << i << ": ";
        cout << i << ": ";
        cont[i]->Out(ofst);
    }
}