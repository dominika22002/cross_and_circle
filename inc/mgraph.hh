
#ifndef MGRAPH_HH
#define MGRAPH_HH

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <memory>
#include "edge.hh"
#include "value.hh"
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>
// #include "vertice.hh"
// #include "vector.hh"
// #include <ctime>

using namespace std;

class MGraph
{
    vector<int> vertices;
    vector<Edge> edges;
    vector<vector<int> > neighbour_matrix;
    int properties[3];
    int size;
    vector<int> got;

public:
    // operatory indeksujace (dzieki nim mozna operowac na prywatnej czesci klasy)
    vector<int> operator[](int Ind) const { return neighbour_matrix[Ind]; }
    vector<int> &operator[](int Ind) { return neighbour_matrix[Ind]; }
    int getsize() const { return size; }
    int &getsize() { return size; }
    void Dijkstra(int *cost);
    MGraph()
    {
        cout << "MGraph()" << endl;
        size = 0;
        int pom = size * size;
        for (int i = 0; i < pom; i++)
        {
            vector<int> vector_pom;
            for (int j = 0; j < size * size; j++)
            {
                vector_pom.push_back(0);
            }
            neighbour_matrix.push_back(vector_pom);
            vertices.push_back(i);
        }
    }
    void generate_graph(int skok)
    {
        // int c = 0;
        // for (int i = 0; i < size; i++)
        // {
        //     Edge edge;
        //     for (int j = 0; j <= skok; j++)
        //     {
        //         edge[0] = i;
        //         edge[1] = j;
        //         edge.getweight() = c;
        //         cout << i <<" "<< j << endl;
        //     }
            
        // }
        



        cout << "void generate_graph()" << endl;
        int a = 0, b = 0,c = 1;
        for (int i = 0; i < size * size; i++)
        {
            if (i != 0 && i % size == 0)
            {
                b = b + size;
            }
            for (int j = 0 + a; j < size * size; j = j + size)
            {
                neighbour_matrix[i][j] = c;
            }
            c++;
            for (int k = b; k < size + b; k++)
            {
                neighbour_matrix[i][k] = c; 
            }
            c++;
            a++;
        }

        for (int i = 0; i < size * size - size * skok; i++)
        {
            for (int j = i + size * skok; j < size * size; j++)
            {
                neighbour_matrix[i][j] = 0;
            }
        }


        // a = 0;
        // b = 0;

        // for (int i = 0; i < size * size-size*skok; i++)
        // {
        //     cout << "i = " << i << endl;
        //     // if (i != 0 && i % size == 0)
        //     // {
        //     //     b = b + size;
        //     // }
        //     // for (int j = 0 + a; j < size * size; j = j + size+1)
        //     // {
        //     //     neighbour_matrix[i][j] = 2;
        //     // }
        //     // // for (int k = b; k < size + b; k++)
        //     // // {
        //     // //     neighbour_matrix[i][k] = 2;
        //     // // }
        //     // a++;
        // }
        for (int i = 0; i < size * size; i++)
        {
            for (int j = 0; j < size * size; j++)
            {
                neighbour_matrix[j][i] = neighbour_matrix[i][j];
                if (i == j)
                {
                    neighbour_matrix[i][j] = 0;
                }
            }
        }
    }
    void create(int skok)
    {
        cout << "void create(int skok)" << endl;
        for (int i = 0; i < size * size; i++)
        {
            vector<int> vector_pom;
            for (int j = 0; j < size * size; j++)
            {
                vector_pom.push_back(0);
            }
            neighbour_matrix.push_back(vector_pom);
            vertices.push_back(i);
        }
        generate_graph(skok);
    }
    void add_element(int number)
    {
        cout << "void add_element(int number)" << endl;
        got.push_back(number);
    }

    void remove_element(int number)
    {
        cout << "void remove_element(int number)" << endl;
        for (int i = 0; i < size * size; i++)
        {
            neighbour_matrix[number][i] = 0;
            neighbour_matrix[i][number] = 0;
        }
        // vertices.erase(vertices.begin() + number);
    }
    void random(vector<vector<int> > board, int pomoc[2])
    {
        bool wybor = true;

        int a = 0, b = 0;
        while (wybor)
        {
            cout << size << endl;
            a = rand() % size;
            b = rand() % size;
            if (board[a][b] == 0)
            {
                wybor = false;
            }
        }
        pomoc[0] = a;
        pomoc[1] = b;
    }

    void wypisz()
    {
        cout << "void wypisz()" << endl;
        for (int i = 0; i < size * size; i++)
        {
            for (int j = 0; j < size * size; j++)
            {
                cout << neighbour_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif
