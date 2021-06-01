#include "../inc/figure.hh"
#include "../inc/mgraph.hh"
#include "../inc/board.hh"
#include "../inc/dijkstry.hh"

using namespace std;

int main()
{
    // int  vertice_size;
    // cin >> vertice_size;
    // int size=0,wielkosc=1;
    cout << "int main()" << endl;
    int size = 5;
    int wielkosc = 4;
    int pom = size*size;
    int cost[pom];
    // cin >> size;
    // cin >> wielkosc;
    // Board plansza = Board(size);
    // plansza.getsize() = size;
    // plansza.getwielkosc() = wielkosc;
    // plansza.wyswietl();
    // plansza.play();
            // cin >>wiel;
            MGraph mgapf;
            mgapf.getsize() = size;
            mgapf.create(wielkosc);
            // mgapf.generate_graph(wielkosc);
            mgapf.wypisz();
            // mgapf.Dijkstra(cost);
            // for (int i = 1; i < pom; i++)
            // {
            //     cout << "dla 0 0, do wierzcholka " << i << " wynosi: " << cost[i] << endl;
            // }
            
            
    return 0;
}


