#ifndef CHOICE_HH
#define CHOICE_HH

#include "library.hh"
#include "board.hh"
#include "mgraph.hh"
#include "vertice.hh"
#include "value.hh"
#include "edge.hh"

using namespace std;

void Board::choice(){

}





// int Min(int *cost, bool *visited)
// {
//     int min = -1;
//     int value = inf;
//     for (int i = 0; i < 3; i++)
//     {
//         if ((!visited[i]) && (cost[i] < value))
//         {
//             min = i;
//             value = cost[i];
//         }
//     }
//     return min;
// }

// void MGraph::Dijkstra(int *cost)
// {
//     int *previous = new int[MAX_VAL];
//     bool *visited = new bool[MAX_VAL];
//     for (int i = 0; i < size; i++)
//     {
//         if (i == properties[2])
//             cost[i] = 0;
//         else
//             cost[i] = inf;

//         previous[i] = -1;
//         visited[i] = false;
//     }
//     int min = Min(cost, visited);
//     while (min != -1)
//     {
//         visited[min] = true;
//         for (int i = 0; i < size; i++)
//         {
//             if ((neighbour_matrix[min][i] > 0) && (cost[min] + neighbour_matrix[min][i] < cost[i]))
//             {
//                 cost[i] = cost[min] + neighbour_matrix[min][i];
//                 previous[i] = min;
//             }
//         }
//         min = Min(cost, visited);
//     }
//     delete[] previous;
//     delete[] visited;
// }

#endif
