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
double ccomplex::Real()
{
    return sqrt(pow(imag, 2) + pow(real, 2));
}
void fractions::InData(ifstream& ifst)
{
    ifst >> x >> y;
    int amount;
    ifst >> amount;
    for (int i = 0; i < amount; i++)
    {
        char sb;
        ifst >> sb;
        unit.push_back(sb);
    }
}
void fractions::Out(ofstream& ofst)
{
    ofst << "It is a Fraction: " << x << "/" << y << " ";
    cout << "It is a Fraction: " << x << "/" << y << " ";
    cout << unit << endl;
    ofst << unit << endl;
}
void polar_coordinates::InData(ifstream& ifst)
{
    ifst >> angle >> distance;
}
void polar_coordinates::Out(ofstream& ofst)
{
    ofst << "These are polar coordinates: " << angle << " (angle), " << distance << " (distance)" << endl;
    cout << "These are polar coordinates: " << angle << " (angle), " << distance << " (distance)" << endl;
}
double fractions::Real()
{
    double result = (double)x;
    return result / y;
}
double polar_coordinates::Real()
{
    return 0.0;
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
    case 3:
        sp = new polar_coordinates;
        break;
    default:
        return 0;
    }
    sp->InData(ifst);
    return sp;
}
// Èíèöèàëèçàöèÿ êîíòåéíåðà
container::container() : len(0) { }
// Î÷èñòêà êîíòåéíåðà îò ýëåìåíòîâ (îñâîáîæäåíèå ïàìÿòè)
void container::Clear()
{
    for (int i = 0; i < len; i++)
        delete cont[i];
    len = 0;
}
// Ââîä ñîäåðæèìîãî êîíòåéíåðà èç óêàçàííîãî ïîòîêà
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
// Âûâîä ñîäåðæèìîãî êîíòåéíåðà â óêàçàííûé ïîòîê
void container::Out(ofstream& ofst)
{
    ofst << "Container contains " << len << " elements." << endl;
    cout << "Container contains " << len << " elements." << endl;
    for (int i = 0; i < len; i++)
    {
        ofst << i << ": ";
        cout << i << ": ";
        cont[i]->Out(ofst);
        ofst << "Real equivalent = " << cont[i]->Real() << endl;
        cout << "Real equivalent = " << cont[i]->Real() << endl;
    }
}
}// сравнение двух объектов
bool shape::Compare(shape& other) 
{
    return Real() < other.Real();
}
void container::Sort() 
{
    for (int i = 0; i < len - 1; i++) 
    {
        for (int j = i + 1; j < len; j++) 
        {
            if (cont[i]->Compare(*cont[j])) 
            {
                shape* tmp = cont[i];
                cont[i] = cont[j];
                cont[j] = tmp;
            }
        }
    }
}

void shape::OutComplex(ofstream& ofst) 
{
    ofst << endl; // пустая строка
    cout << endl;
}
// Вывод данных только для комплексного числа
void ccomplex::OutComplex(ofstream& ofst) 
{
    Out(ofst);
}
// Вывод содержимого контейнера
void container::OutComplex(ofstream& ofst) 
{
    ofst << "Only Complex." << endl;
    for (int i = 0; i < len; i++) 
    {
        ofst << i << ": ";
        cout << i << ": ";
        cont[i]->OutComplex(ofst);
    }
}
