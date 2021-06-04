
#include "../inc/board.hh"
#include "../inc/boardcopy.hh"

using namespace std;

int main()
{
    int choose = 1;
    cout << "wybierz rodzaj gry: \n 1 - player vs player \n 2 - player vs AI \n 3 - AI vs AI " << endl;
    cin >> choose;

    int size = 0,
        row = 0;

    int x = 0,
        y = 0;

    int wygrana = 0;
    int tmp[2];
    bool wybor = true;

    cout << "wybierz wielkosc planszy" << endl;
    cin >> size;
    cin >> row;
    Plansza plansza = Plansza(size);
    plansza.getsize() = size;
    plansza.getrow() = row;

    switch (choose)
    {
    case 1:
        system("clear");
        cout << "wykonaj ruch" << endl;
        plansza.wyswietl();
        while (isfull(plansza) && wybor)
        {
            cin >> x;
            cin >> y;
            while (x >= size || y >= size || plansza[x][y] != empty)
            {
                cout << "wybierz inne liczby " << endl;
                cin >> x;
                cin >> y;
            }
            plansza[x][y] = ai;
            system("clear");
            cout << "twoj ruch" << endl;
            plansza.wyswietl();
            wygrana = czy_wygrana(plansza);
            if (wygrana == 0 || !isfull(plansza))
            {
                cin >> x;
                cin >> y;
                while (x >= size || y >= size || plansza[x][y] != empty)
                {
                    cout << "wybierz inne liczby " << endl;
                    cin >> x;
                    cin >> y;
                }
                plansza[x][y] = player;
                system("clear");
                cout << "twoj ruch" << endl;
                plansza.wyswietl();
            }
            else
                wybor = false;
            wygrana = czy_wygrana(plansza);
            if (wygrana != 0)
                wybor = false;
        }
        plansza.czyja_wygrana(wygrana);
        return 0;

    case 2:
        system("clear");
        cout << "wykonaj ruch" << endl;
        plansza.wyswietl();
        while (isfull(plansza) && wybor)
        {
            cin >> x;
            cin >> y;
            while (x >= size || y >= size || plansza[x][y] != empty)
            {
                cout << "wybierz inne liczby " << endl;
                cin >> x;
                cin >> y;
            }
            plansza[x][y] = ai;
            system("clear");
            cout << "twoj ruch" << endl;
            plansza.wyswietl();
            wygrana = czy_wygrana(plansza);
            if (wygrana == 0 || !isfull(plansza))
            {
                choice(plansza, tmp, false, player, -100000000);
                plansza[tmp[0]][tmp[1]] = player;
                system("clear");
                cout << "twoj ruch" << endl;
                plansza.wyswietl();
            }
            else
                wybor = false;
            wygrana = czy_wygrana(plansza);
            if (wygrana != 0)
                wybor = false;
        }
        plansza.czyja_wygrana(wygrana);
        return 0;

    case 3:
        system("clear");
        plansza.wyswietl();
        while (isfull(plansza) && wybor)
        {
            choice(plansza, tmp, true, ai, 100000000);
            plansza[tmp[0]][tmp[1]] = ai;

            system("clear");
            plansza.wyswietl();

            system("sleep .5");
            wygrana = czy_wygrana(plansza);
            if (wygrana == 0 || !isfull(plansza))
            {
                choice(plansza, tmp, false, player, -100000000);
                plansza[tmp[0]][tmp[1]] = player;
                system("clear");
                plansza.wyswietl();
            }
            else
                wybor = false;
            wygrana = czy_wygrana(plansza);
            if (wygrana != 0)
                wybor = false;
            system("sleep .5");
        }
        plansza.czyja_wygrana(wygrana);
        return 0;

    default:
        break;
    }
}
