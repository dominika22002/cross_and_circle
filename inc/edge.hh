#ifndef EDGE_HH
#define EDGE_HH

#include "library.hh"

using namespace std;

class Edge
{
    int coordinates[2];
    int weight;
public:
    Edge(){
        coordinates[0] = 0;
        coordinates[1] = 0;
        weight = 0;
    }
    int operator[](int Ind) const { return coordinates[Ind]; }
    int &operator[](int Ind) { return coordinates[Ind]; }
    int getweight() const { return weight; }
    int &getweight() { return weight; }
};

#endif
