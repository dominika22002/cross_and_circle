#ifndef BOARD_HH
#define BOARD_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Board
{
    vector<vector<int> > board;
    int size;
    int row;

public:
    vector<int> operator[](int Ind) const { return board[Ind]; }
    vector<int> &operator[](int Ind) { return board[Ind]; }
    int getsize() const { return size; }
    int &getsize() { return size; }
    int getrow() const { return row; }
    int &getrow() { return row; }
    Board()
    {
        cout << "Board()" << endl;
        size = 0;
        for (int i = 0; i < size; i++)
        {
            vector<int> vector_pom;
            for (int j = 0; j < size; j++)
            {
                vector_pom.push_back(0);
            }
            board.push_back(vector_pom);
        }
    }

    Board(int wiel)
    {
        cout << "Board(int wiel)" << endl;
        size = wiel;
        for (int i = 0; i < size; i++)
        {
            vector<int> vector_pom;
            for (int j = 0; j < size; j++)
            {
                vector_pom.push_back(0);
            }
            board.push_back(vector_pom);
        }
    }

    bool isfull()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void wyswietl()
    {
        cout << "void wyswietl()" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << " " << i << "\t";
        }
        for (int i = 0; i < size; i++)
        {
            cout << "\n"
                 << i << " ";
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == 0)
                {
                    cout << "[ ]\t";
                }
                if (board[i][j] == -1)
                {
                    cout << "[X]\t";
                }
                if (board[i][j] == 1)
                {
                    cout << "[O]\t";
                }
            }
        }
    }
    int czy_wygrana()
    {
        int a = 0, b = 0, c = 0, d = 0;
        for (int i = 0; i < size; i++)
        {
            for (int k = 0; k <= size - row; k++)
            {
                a = board[i][k];
                c = board[k][i];
                if (a == 1 || a == -1)
                {
                    b = 0;
                    for (int j = k; j < row + k; j++)
                    {
                        if (board[i][j] == a)
                            b++;
                        if (b == row)
                        {
                            if (a == 1)
                                return 1; //wygrana O

                            if (a == -1)
                                return -1; //wygrana X
                        }
                    }
                }
                if (c == 1 || c == -1)
                {
                    b = 0;
                    for (int j = k; j < row + k; j++)
                    {
                        if (board[j][i] == c)
                            b++;
                        if (b >= row)
                        {
                            if (c == 1)
                                return 1; //wygrana O

                            if (c == -1)
                                return -1; //wygrana X
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= size - row; i++)
        {
            for (int k = 0; k <= size - row; k++)
            {
                d = board[i][k];
                if (d == 1 || d == -1)
                {
                    b = 0;
                    for (int j = 0; j < row; j++)
                    {
                        if (board[j + i][j + k] == d)
                            b++;
                        if (b >= row)
                        {
                            if (d == 1)
                                return 1; //wygrana O

                            if (d == -1)
                                return -1; //wygrana X
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= size - row; i++)
        {
            for (int k = size - 1; k >= row - 1; k--)
            {
                d = board[i][k];
                if (d == 1 || d == -1)
                {
                    b = 0;
                    for (int j = k; j > k - row; j--)
                    {
                        if (board[size - 1 - j][j] == d)
                            b++;
                        if (b >= row)
                        {
                            if (d == 1)
                                return 1; //wygrana O

                            if (d == -1)
                                return -1; //wygrana X
                        }
                    }
                }
            }
        }
        if (isfull())
        {
            // cout << "remis \n";
            return 0; //remis
        }
        return 2; //gra jeszcze trwa
    }

    void czyja_wygrana(int wygrana)
    {
        cout << "void czyja_wygrana(int wygrana)" << endl;
        if (wygrana == -1)
        {
            cout << "Wygrywaja krzyzyki!\n";
        }
        if (wygrana == 1)
        {
            cout << "Wygrywaja kolka!\n";
        }
        if (wygrana == 0)
        {
            cout << "remis!\n";
        }
    }

    // human - x ---- -1
    // ai    - o ----  1
};
int min_max(Board tablica, int depth, bool ishuman)
{
    int bestscore = 0;
    int result = 0;
    if (tablica.czy_wygrana() != 2)
    {
        return tablica.czy_wygrana();
    }
    if (ishuman)
    {
        bestscore = -10000000;
        for (int i = 0; i < tablica.getsize(); i++)
        {
            for (int j = 0; j < tablica.getsize(); j++)
            {
                // cout << "i. " << i << "  j." << j << endl;
                if (tablica[i][j] == 0)
                {
                    tablica[i][j] = -1;
                    result = min_max(tablica, depth + 1, !ishuman);
                    bestscore = max(bestscore, result);
                    if (bestscore != result)
                    {
                        cout <<i  <<" " << j<<" "<<bestscore <<" "<< result<< endl;
                    }
                    
                    
                    tablica[i][j] = 0;
                }
            }
        }
        return bestscore;
    }
    else
    {
        bestscore = 10000000;
        for (int i = 0; i < tablica.getsize(); i++)
        {
            for (int j = 0; j < tablica.getsize(); j++)
            {
                if (tablica[i][j] == 0)
                {
                    tablica[i][j] = 1;
                    bestscore = min(bestscore, min_max(tablica, depth + 1, !ishuman));
                    tablica[i][j] = 0;
                }
            }
        }
        return bestscore;
    }
}
void choice(Board tablica, int pomoc[2])
{
    cout << "void choice(Board tablica,int pomoc[2])" << endl;
    int bestscore = -100000000;
    int a = 0, b = 0;
    pomoc[0] = -1;
    pomoc[1] = -1;
    for (int i = 0; i < tablica.getsize(); i++)
    {
        for (int j = 0; j < tablica.getsize(); j++)
        {
            if (tablica[i][j] == 0)
            {
                tablica[i][j] = -1;
                int choosen = min_max(tablica, 0, false);
                tablica[i][j] = 0;
                // cout << choosen << endl;
                if (choosen > bestscore)
                {
                    bestscore = choosen;
                    a = i;
                    b = j;
                    cout << "wylazlam najlepszy znaleziony to: " << a << " " << b <<"   dla"<< choosen<<  endl;
                }
                else
                    cout << "nie ma najlepszego, wygrywa:   " << choosen << endl;
            }
        }
    }
    pomoc[0] = a;
    pomoc[1] = b;
}

#endif
