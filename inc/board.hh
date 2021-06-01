#ifndef BOARD_HH
#define BOARD_HH

#include "library.hh"
#include "mgraph.hh"

using namespace std;

class Board
{
    MGraph circle;
    MGraph cross;
    vector<vector<int> > board;
    int size;
    int wielkosc;

public:
    vector<int> operator[](int Ind) const { return board[Ind]; }
    vector<int> &operator[](int Ind) { return board[Ind]; }
    int getsize() const { return size; }
    int &getsize() { return size; }
    int getwielkosc() const { return wielkosc; }
    int &getwielkosc() { return wielkosc; }
    void choice();
    Board()
    {
        cout << "Board()" << endl;
        size = 0;
        circle.create(size);
        cross.create(size);
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
        circle.getsize() = size;
        cross.getsize() = size;
        circle.create(size);
        cross.create(size);
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
    void wyswietl()
    {
        for (int i = 0; i < size; i++)
        {
            cout << " " << i << "\t";
        }
        cout << "\n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == 0)
                {
                    cout << "[ ]\t";
                }
                if (board[i][j] == 1)
                {
                    cout << "[X]\t";
                }
                if (board[i][j] == 2)
                {
                    cout << "[O]\t";
                }
            }
            cout << "\n";
        }
    }
    int czy_wygrana()
    {
        int a = 0, b = 0, c = 0,d=0;
        for (int i = 0; i < size; i++)
        {
            for (int k = 0; k <= size - wielkosc; k++)
            {
                a = board[i][k];
                c = board[k][i];
                if (a == 1 || a == 2)
                {
                    b = 0;
                    for (int j = k; j < wielkosc + k; j++)
                    {
                        if (board[i][j] == a)
                            b++;
                        if (b == wielkosc)
                        {
                            if (a == 1)
                                return 1;

                            if (a == 2)
                                return 2;
                        }
                    }
                }
                if (c == 1 || c == 2)
                {
                    b = 0;
                    for (int j = k; j < wielkosc + k; j++)
                    {
                        if (board[j][i] == c)
                            b++;
                        if (b >= wielkosc)
                        {
                            if (c == 1)
                                return 1;

                            if (c == 2)
                                return 2;
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= size - wielkosc; i++)
        {
            for (int k = 0; k <= size - wielkosc; k++)
            {
                d = board[i][k];
                if (d == 1 || d == 2)
                {
                    b = 0;
                    for (int j=0; j < wielkosc; j++)
                    {
                        // cout << "i = " << i+j << "  j = " << j+k << "   board[i][j] = " << board[i+j][j+k] <<endl;
                        if (board[j+i][j+k] == d)
                            b++;
                        if (b >= wielkosc)
                        {
                            if (d == 1)
                                return 1;

                            if (d == 2)
                                return 2;
                        }
                    }
                }
            }
        }
        for (int i = 0; i <= size - wielkosc; i++)
        {
            for (int k = size - 1; k >= wielkosc-1; k--)
            {
                d = board[i][k];
                if (d == 1 || d == 2)
                {
                    b = 0;
                    for (int j = k; j > k-wielkosc; j--)
                    {
                        if (board[size-1-j][j] == d)
                            b++;
                        if (b >= wielkosc)
                        {
                            if (d == 1)
                                return 1;

                            if (d == 2)
                                return 2;
                        }
                    }
                }
            }
        }
        return 0;
    }

    void czyja_wygrana(int wygrana)
    {
        if (wygrana == 1)
        {
            cout << "Wygrywaja krzyzyki!!!!\n";
        }
        if (wygrana == 2)
        {
            cout << "Wygrywaja kolka!!!!\n";
        }
        if (wygrana == 0)
        {
            cout << "remis!\n";
        }
    }
    bool full()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    void play()
    {
        cout << "zacznij gre, wpisz wspolrzedne dla X" << endl;
        int x = 0, xx = 0, y = 0, yy = 0, liczba = 0, pom = 0, wygrana = 0;
        bool wybor = true;
        int tmp[2];
        while (full() && wybor)
        {
            cin >> x;
            cin >> y;
            if (board[x][y] != 0)
            {
                cout << "wybierz inne liczby " << endl;
            }
            else
            {
                liczba = x * size + y;
                cross.add_element(liczba);
                circle.remove_element(liczba);
                board[x][y] = 1;
                wyswietl();
                wygrana = czy_wygrana();
                if (wygrana == 1 || wygrana == 2)
                {
                    wybor = false;
                }
                if (full())
                {
                    circle.random(board, tmp);
                    pom = tmp[0] * size + tmp[1];
                    circle.add_element(pom);
                    cross.remove_element(pom);
                    board[tmp[0]][tmp[1]] = 2;
                    wyswietl();
                }
            }
            wygrana = czy_wygrana();
            if (wygrana == 1 || wygrana == 2)
            {
                wybor = false;
            }
        }
        czyja_wygrana(wygrana);
    }
};

#endif
