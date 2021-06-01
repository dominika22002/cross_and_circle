#ifndef VERTICE_HH
#define VERTICE_HH

#include "library.hh"

using namespace std;

class Vertice
{
    int number;

public:
    int getnumber() const { return number; }
    int &getnumber() { return number; }

    void create(int tmp)
    {
       number = tmp;
    }
};

#endif
