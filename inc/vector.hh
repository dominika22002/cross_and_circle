#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "value.hh"
#include "vertice.hh"
using namespace std;

class Vector
{
  vector<int> v;

public:
  //konstruktor
  Vector(int ilosc)
  {
    for (int i = 0; i < ilosc; i++)
    {
      v.push_back(0);
    }
  }
  // operatory indeksujace (dzieki nim mozna operowac na prywatnej czesci klasy)
  int operator[](int Ind) const { return v[Ind]; }
  int &operator[](int Ind) { return v[Ind]; }
};

#endif
