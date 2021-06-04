#ifndef plansza_HH
#define plansza_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <iomanip>
#include <fstream>
#include <string>
#include "boardcopy.hh"

using namespace std;
class Plansza
{
    vector<vector<char> > plansza;
    int size;
    int row;

public:
    vector<char> operator[](int Ind) const { return plansza[Ind]; }
    vector<char> &operator[](int Ind) { return plansza[Ind]; }
    int getsize() const { return size; }
    int &getsize() { return size; }
    int getrow() const { return row; }
    int &getrow() { return row; }
    Plansza(int wiel)
    {
        cout << "plansza(int wiel)" << endl;
        size = wiel;
        for (int i = 0; i < size; i++)
        {
            vector<char> vector_pom;
            for (int j = 0; j < size; j++)
            {
                vector_pom.push_back(empty);
            }
            plansza.push_back(vector_pom);
        }
    }

    void zapis_z_pliku(string plik)
    {
        ifstream in(plik);
        in >> size;
        in >> row;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                in >> plansza[i][j];
            }
        }
        in.close();
    }

    void wyswietl()
    {
        // cout << "void wyswietl()" << endl;
        // system("clear");
        cout << "\t ";
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t ";
        }
        for (int i = 0; i < size; i++)
        {
            cout << "\n"
                 << i << "\t";
            for (int j = 0; j < size; j++)
            {
                if (plansza[i][j] == empty)
                {
                    cout << "[ ]\t";
                }
                if (plansza[i][j] == 'X')
                {
                    cout << "[X]\t";
                }
                if (plansza[i][j] == 'O')
                {
                    cout << "[O]\t";
                }
            }
        }
        cout << endl;
    }

    bool zajete(int x, int y)
    {
        if (x >= size || y >= size || plansza[x][y] != empty)
        {
            cout << "wybierz inne liczby " << endl;
            return true;
        }
        else
            return false;
    }

    void czyja_wygrana(int wygrana)
    {

        // cout << "void czyja_wygrana(int wygrana)" << endl;
        if (wygrana == -10)
        {
            cout << "Wygrywaja krzyzyki!\n";
        }
        if (wygrana == 10)
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

    void random(int pomoc[2])
    {
        cout << "void random(int pomoc[2])" << endl;
        bool wybor = true;
        int a = 0, b = 0;
        while (wybor)
        {
            //  cout << size << endl;
            a = rand() % size;
            b = rand() % size;
            if (plansza[a][b] == empty)
            {
                wybor = false;
            }
        }
        pomoc[0] = a;
        pomoc[1] = b;
    }
};

int czy_wygrana(Plansza plansza)
{

    char a, c, d;
    int b = 0;
    for (int i = 0; i < plansza.getsize(); i++)
    {
        for (int k = 0; k <= plansza.getsize() - plansza.getrow(); k++)
        {
            a = plansza[i][k];
            if (a == player || a == ai)
            {
                b = 0;
                for (int j = k; j < plansza.getrow() + k; j++)
                {
                    if (plansza[i][j] == a)
                        b++;
                    if (b == plansza.getrow())
                    {
                        if (a == ai)
                            return -10; //wygrana O

                        if (a == player)
                            return +10; //wygrana X
                    }
                }
            }
        }
    }

    for (int i = 0; i < plansza.getsize(); i++)
    {
        for (int k = 0; k <= plansza.getsize() - plansza.getrow(); k++)
        {
            c = plansza[k][i];
            if (c == player || c == ai)
            {
                b = 0;
                for (int j = k; j < plansza.getrow() + k; j++)
                {
                    if (plansza[j][i] == c)
                        b++;
                    if (b >= plansza.getrow())
                    {
                        if (c == ai)
                            return -10; //wygrana O

                        if (c == player)
                            return +10; //wygrana X
                    }
                }
            }
        }
    }
    for (int i = 0; i <= plansza.getsize() - plansza.getrow(); i++)
    {
        for (int k = 0; k <= plansza.getsize() - plansza.getrow(); k++)
        {
            d = plansza[i][k];
            if (d == player || d == ai)
            {
                b = 0;
                for (int j = 0; j < plansza.getrow(); j++)
                {
                    if (plansza[j + i][j + k] == d)
                        b++;
                    if (b >= plansza.getrow())
                    {
                        if (d == ai)
                            return -10; //wygrana O

                        if (d == player)
                            return +10; //wygrana X
                    }
                }
            }
        }
    }
    for (int i = 0; i <= plansza.getsize() - plansza.getsize(); i++)
    {
        for (int k = plansza.getsize() - 1; k >= plansza.getrow() - 1; k--)
        {
            d = plansza[i][k];
            if (d == player || d == ai)
            {
                b = 0;
                for (int j = k; j > k - plansza.getrow(); j--)
                {
                    if (plansza[plansza.getsize() - 1 - j][j] == d)
                        b++;
                    if (b >= plansza.getrow())
                    {
                        if (d == ai)
                            return -10; //wygrana O

                        if (d == player)
                            return +10; //wygrana X
                    }
                }
            }
        }
    }
    return 0;
}

bool isfull(Plansza plansza)
{
    // cout << "bool isMovesLeft(plansza plansza)" << endl;
    for (int i = 0; i < plansza.getsize(); i++)
    {
        for (int j = 0; j < plansza.getsize(); j++)
        {
            if (plansza[i][j] == empty)
            {
                return true;
            }
        }
    }
    return false;
}
int min_max(Plansza plansza, int depth, bool ishuman, int height)
{
    // plansza.wyswietl();
    int result = 0;
    int score = czy_wygrana(plansza);

    if (score == 10 || score == -10)
        return score;

    if (isfull(plansza) == false || height <= depth)
        return 0;

    if (ishuman)
    {
        int wynik = -1000000;
        for (int i = 0; i < plansza.getsize(); i++)
        {
            for (int j = 0; j < plansza.getsize(); j++)
            {
                if (plansza[i][j] == empty)
                {
                    plansza[i][j] = player;
                    result = min_max(plansza, depth + 1, !ishuman, height);
                    wynik = max(wynik, result);
                    if (plansza.getsize() != 3)
                        height = min(height, depth);
                    plansza[i][j] = empty;
                }
            }
        }
        return wynik;
    }
    else
    {
        int wynik = 1000000;
        for (int i = 0; i < plansza.getsize(); i++)
        {
            for (int j = 0; j < plansza.getsize(); j++)
            {
                if (plansza[i][j] == empty)
                {
                    plansza[i][j] = ai;
                    result = min_max(plansza, depth + 1, !ishuman, height);
                    wynik = min(wynik, result);
                    if (plansza.getsize() != 3)
                        height = min(height, depth);
                    plansza[i][j] = empty;
                }
            }
        }
        return wynik;
    }
}

void choice(Plansza plansza, int pomoc[2], bool ifai, char who, int bestscor)
{
    unsigned long int czas;
    clock_t start, stop;
    // cout << "void choice(plansza plansza, int pomoc[2])" << endl;
    int wynik = bestscor;
    int height = 10000;
    int depth = 0;
    int choosen = 0;
    int a = 0, b = 0, c = 0;
    pomoc[0] = -1;
    pomoc[1] = -1;
    for (int i = 0; i < plansza.getsize(); i++)
    {
        for (int j = 0; j < plansza.getsize(); j++)
        {
            if (plansza[i][j] == empty)
            {
                plansza[i][j] = who;
                c = height;
                int choosen = min_max(plansza, depth, ifai, height);
                plansza[i][j] = empty;
                if (bestscor < 0)
                {
                    if (choosen > wynik)
                    {
                        wynik = choosen;
                        a = i;
                        b = j;
                    }
                }
                else
                {
                    if (choosen < wynik)
                    {
                        wynik = choosen;
                        a = i;
                        b = j;
                    }
                }
            }
        }
    }
    pomoc[0] = a;
    pomoc[1] = b;
}

#endif
