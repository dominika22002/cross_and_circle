
#include "../inc/board.hh"
#include "../inc/boardcopy.hh"

using namespace std;

int main()
{
    cout << "int main()" << endl;
    int size = 3;
    int wielkosc = 3;
    int x = 0, y = 0, liczba = 0, pom = 0, wygrana = 0;
    bool wybor = true;
    int tmp[2];
    cin >> size;
    cin >> wielkosc;
    Board plansza = Board(size);
    // plansza.zapis_z_pliku("pli.txt");
    plansza.getsize() = size;
    plansza.getrow() = wielkosc;
    plansza.wyswietl();

    cout << "zacznij gre, wpisz wspolrzedne dla X" << endl;
    while (!plansza.isfull() && wybor)
    {
        cin >> x;
        cin >> y;
        if (plansza[x][y] != empty)
        {
            cout << "wybierz inne liczby " << endl;
        }
        else
        {
            liczba = x * size + y;
            // choice(plansza, tmp, true,ai,100000000);
            // cout << tmp[0] << endl;
            // plansza[tmp[0]][tmp[1]] = ai;
            plansza[x][y] = ai;
            // system("clear");
            plansza.wyswietl();
            wygrana = czy_wygrana(plansza);
            // system("clear");
            if (wygrana == 0 || isMovesLeft(plansza))
            {
                choice(plansza, tmp, false, player,-100000000);
                pom = tmp[0] * size + tmp[1];
                plansza[tmp[0]][tmp[1]] = player;
                plansza.wyswietl();
            }
            else
                wybor = false;
        }
        wygrana = czy_wygrana(plansza);
        if (wygrana != 0)
        {
            wybor = false;
        }
    }
    plansza.czyja_wygrana(wygrana);
    return 0;
}
