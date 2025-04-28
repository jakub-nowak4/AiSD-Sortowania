#pragma once

void swap(int &x, int &y);
void print_array(int *tab, int size);
void heapfiy(int *tab, int size, int i);
void build_heap(int *tab, int size);

// Algorytmy sortujące

void bubble_sort(int *tab, int size);
void insertion_sort(int *tab, int size);
void selection_sort(int *tab, int size);
void quick_sort(int *tab, int low, int high);
void shell_sort(int *tab, int size);
void heap_sort(int *tab, int size);