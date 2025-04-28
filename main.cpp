#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sys/time.h>
#include "algorytmy.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Za malo argumentow!" << endl;
        return 1;
    }

    int n = atoi(argv[2]);
    string algorytm = argv[1];

    int *tab = new int[n];

    ifstream plik("dane.txt");

    if (!plik)
    {
        cout << "Nie mozna otworzyc pliku" << endl;
        delete[] tab;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        int liczba;
        if (plik >> liczba)
        {
            tab[i] = liczba;
        }
        else
        {
            cout << "Blad podczas wczytywania danych!" << endl;
            delete[] tab;
            return 1;
        }
    }

    plik.close();

    timeval start, end;
    gettimeofday(&start, NULL);

    if (algorytm == "bubble_sort")
    {
        bubble_sort(tab, n);
    }
    else if (algorytm == "insertion_sort")
    {
        insertion_sort(tab, n);
    }
    else if (algorytm == "selection_sort")
    {
        selection_sort(tab, n);
    }
    else if (algorytm == "quick_sort")
    {
        quick_sort(tab, 0, n - 1);
    }
    else if (algorytm == "shell_sort")
    {
        shell_sort(tab, n);
    }
    else if (algorytm == "heap_sort")
    {
        heap_sort(tab, n);
    }
    else
    {
        cout << "Nieznany algorytm sortowania!" << endl;
        delete[] tab;
        return 1;
    }

    gettimeofday(&end, NULL);

    double czas_trwania = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    cout << czas_trwania << endl;

    delete[] tab;
    return 0;
}
