#include <iostream>
#include <cmath>
#include "algorytmy.h"
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void print_array(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << tab[i] << " ";
    }
}

void bubble_sort(int *tab, int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        int swaps_number = 0;

        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                swap(tab[j], tab[j + 1]);
                swaps_number++;
            }
        }

        // if no more swaps than array is sorted
        if (swaps_number == 0)
        {
            return;
        }
    }
}

void insertion_sort(int *tab, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int temp = tab[i];

        while (j >= 0)
        {
            if (temp < tab[j])
            {
                tab[j + 1] = tab[j];
            }
            else
            {
                break;
            }

            j--;
        }

        tab[j + 1] = temp;
    }
}

void selection_sort(int *tab, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int k = i;
        for (int j = i; j < size; j++)
        {
            if (tab[j] < tab[k])
            {
                k = j;
            }
        }

        swap(tab[i], tab[k]);
    }
}

void quick_sort(int *tab, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = tab[low + (high - low) / 2];

    do
    {
        while (tab[i] < pivot)
        {
            i++;
        }

        while (tab[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (j > low)
        quick_sort(tab, low, j);
    if (i < high)
        quick_sort(tab, i, high);
}

void shell_sort(int *tab, int size)
{
    int gap = size / 2;

    while (gap > 0)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = tab[i];
            int j = i - gap;

            while (j >= 0)
            {

                if (temp < tab[j])
                {
                    tab[j + gap] = tab[j];
                }
                else
                {
                    break;
                }

                j -= gap;
            }

            tab[j + gap] = temp;
        }

        gap /= 2;
    }
}

void heapfiy(int *tab, int size, int i)
{

    if (i >= size)
        return;

    int root = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < size && tab[left_child] > tab[root])
    {
        root = left_child;
    }

    if (right_child < size && tab[right_child] > tab[root])
    {
        root = right_child;
    }

    if (root != i)
    {
        swap(tab[i], tab[root]);
        heapfiy(tab, size, root);
    }
}

void build_heap(int *tab, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapfiy(tab, size, i);
    }
}

void heap_sort(int *tab, int size)
{
    build_heap(tab, size);

    while (size > 1)
    {
        swap(tab[0], tab[size - 1]);
        size--;
        heapfiy(tab, size, 0);
    }
}