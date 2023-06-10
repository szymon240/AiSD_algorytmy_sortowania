#pragma once
#include <iostream>

void insertion_sort_main(int* A, int array_size);

void selection_sort_main(int* A, int array_size);

void merge_sort_main(int* a, int array_size);

void merge_sort(int* a, int left, int right, int* b);

void heap_sort_main(int* a, int array_size);

void build_heap(int* a, int array_size);

void heapify(int* a, int i, int heapsize);

void switch_elements(int* a, int* b);

void quick_sort_main(int* a, int array_size);

void quicksort(int* a, int p, int r);

int partition(int* a, int p, int r);