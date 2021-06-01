#ifndef DIJKSTRY_HH
#define DIJKSTRY_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
// #include "vgraph.hh"
#include "mgraph.hh"
#include "vertice.hh"
#include "value.hh"
#include "edge.hh"

using namespace std;

//dla macierzy
int Min(int s,int *cost, bool *visited)
{
    int min = -1;
    int value = inf;
    for (int i = 0; i < s; i++)
    {
        if ((!visited[i]) && (cost[i] < value))
        {
            min = i;
            value = cost[i];
        }
    }
    return min;
}


void MGraph::Dijkstra(int *cost)
{
    int *previous = new int[MAX_VAL];
    bool *visited = new bool[MAX_VAL];
    for (int i = 0; i < size*size; i++)
    {
        if (i == 0)
            cost[i] = 0;
        else
            cost[i] = 10000000;

        previous[i] = -1;
        visited[i] = false;
    }
    int min = Min(size*size,cost, visited);
    while (min != -1)
    {
        visited[min] = true;
        for (int i = 0; i < size*size; i++)
        {
            if (((neighbour_matrix[min][i] > 0) && (cost[min] + neighbour_matrix[min][i] < cost[i])))
            {
                cost[i] = cost[min] + neighbour_matrix[min][i];
                previous[i] = min;
            }
        }
        min = Min(size*size,cost, visited);
    }
    delete[] previous;
    delete[] visited;
}


#endif
