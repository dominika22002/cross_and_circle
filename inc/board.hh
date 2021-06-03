#ifndef BOARD_HH
#define BOARD_HH

#include <vector>
#include <iostream>
#include <math.h>
#include <memory>
#include <iomanip>
#include <fstream>
#include <string>
#include "boardcopy.hh"

using namespace std;
class Board
{
    vector<vector<char> > board;
    int size;
    int row;

public:
    vector<char> operator[](int Ind) const { return board[Ind]; }
    vector<char> &operator[](int Ind) { return board[Ind]; }
    int getsize() const { return size; }
    int &getsize() { return size; }
    int getrow() const { return row; }
    int &getrow() { return row; }
    Board(int wiel)
    {
        cout << "Board(int wiel)" << endl;
        size = wiel;
        for (int i = 0; i < size; i++)
        {
            vector<char> vector_pom;
            for (int j = 0; j < size; j++)
            {
                vector_pom.push_back(empty);
            }
            board.push_back(vector_pom);
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
                in >> board[i][j];
            }
        }
        in.close();
    }

    bool isfull()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == empty)
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
                if (board[i][j] == empty)
                {
                    cout << "[ ]\t";
                }
                if (board[i][j] == 'X')
                {
                    cout << "[X]\t";
                }
                if (board[i][j] == 'O')
                {
                    cout << "[O]\t";
                }
            }
        }
    }

    void czyja_wygrana(int wygrana)
    {

        cout << "void czyja_wygrana(int wygrana)" << endl;
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
         cout <<"void random(int pomoc[2])" << endl;
         bool wybor = true;
         int a = 0, b = 0;
         while (wybor)
         {
            //  cout << size << endl;
             a = rand() % size;
             b = rand() % size;
             if (board[a][b] == empty)
             {
                 wybor = false;
             }
         }
         pomoc[0] = a;
         pomoc[1] = b;
     }
};

int czy_wygrana(Board board)
{
    
        char a, c, d;
        int b = 0;
        for (int i = 0; i < board.getsize(); i++)
        {
            for (int k = 0; k <= board.getsize() - board.getrow(); k++)
            {
                a = board[i][k];
                if (a == player || a == ai)
                {
                    b = 0;
                    for (int j = k; j < board.getrow() + k; j++)
                    {
                        if (board[i][j] == a)
                            b++;
                        if (b == board.getrow())
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

        for (int i = 0; i < board.getsize(); i++)
        {
            for (int k = 0; k <= board.getsize() - board.getrow(); k++)
            {
                c = board[k][i];
                if (c == player || c == ai)
                {
                    b = 0;
                    for (int j = k; j < board.getrow() + k; j++)
                    {
                        if (board[j][i] == c)
                            b++;
                        if (b >= board.getrow())
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
        for (int i = 0; i <= board.getsize() - board.getrow(); i++)
        {
            for (int k = 0; k <= board.getsize() - board.getrow(); k++)
            {
                d = board[i][k];
                if (d == player || d == ai)
                {
                    b = 0;
                    for (int j = 0; j < board.getrow(); j++)
                    {
                        if (board[j + i][j + k] == d)
                            b++;
                        if (b >= board.getrow())
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
        for (int i = 0; i <= board.getsize() - board.getsize(); i++)
        {
            for (int k = board.getsize() - 1; k >= board.getrow() - 1; k--)
            {
                d = board[i][k];
                if (d == player || d == ai)
                {
                    b = 0;
                    for (int j = k; j > k - board.getrow(); j--)
                    {
                        if (board[board.getsize() - 1 - j][j] == d)
                            b++;
                        if (b >= board.getrow())
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

bool isMovesLeft(Board board)
{
    // cout << "bool isMovesLeft(Board board)" << endl;
    for (int i = 0; i < board.getsize(); i++)
        for (int j = 0; j < board.getsize(); j++)
            if (board[i][j] == empty)
                return true;
    return false;
}
int min_max(Board board, int depth, bool ishuman)
{
    // board.wyswietl();
    int result = 0;
    int score = czy_wygrana(board);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (isMovesLeft(board) == false)
        return 0;

    if (ishuman)
    {
        int bestscore = -1000000;
        for (int i = 0; i < board.getsize(); i++)
        {
            for (int j = 0; j < board.getsize(); j++)
            {
                if (board[i][j] == empty)
                {
                    board[i][j] = player;
                    result = min_max(board, depth + 1, !ishuman);
                    bestscore = max(bestscore, result);
                    board[i][j] = empty;
                }
            }
        }
        return bestscore;
    }
    else
    {
        int bestscore = 1000000;
        for (int i = 0; i < board.getsize(); i++)
        {
            for (int j = 0; j < board.getsize(); j++)
            {
                if (board[i][j] == empty)
                {
                    board[i][j] = ai;
                    bestscore = min(bestscore, min_max(board, depth + 1, !ishuman));
                    board[i][j] = empty;
                }
            }
        }
        return bestscore;
    }
}

void choice(Board board, int pomoc[2],bool ifai,char who,int bestscor)
{
    cout << "void choice(Board board, int pomoc[2])" << endl;
    int bestscore = bestscor;
    // int bestscore = -10000000;
    int choosen = 0;
    int a = 0, b = 0;
    pomoc[0] = -1;
    pomoc[1] = -1;
    for (int i = 0; i < board.getsize(); i++)
    {
        for (int j = 0; j < board.getsize(); j++)
        {
            if (board[i][j] == empty)
            {
                board[i][j] = who;
                // board[i][j] = player;
                int choosen = min_max(board, 0, ifai);
                // cout << choosen << endl;
                board[i][j] = empty;
                if (bestscor < 0)
                {
                    if (choosen > bestscore)
                    {
                        bestscore = choosen;
                        a = i;
                        b = j;
                    }
                }
                else
                {
                    if (choosen < bestscore)
                    {
                        bestscore = choosen;
                        a = i;
                        b = j;
                    }
                }
            }
        }
    }
    pomoc[0] = a;
    pomoc[1] = b;
    // printf("The value of the best Move is : %d\n",
        //    bestscore);
}

#endif
