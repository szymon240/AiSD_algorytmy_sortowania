#include "Sorts.h"

void insertion_sort_main(int* A, int array_size)
{
    int j;
    int key;
    for (int i = 1; i < array_size; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

}

void selection_sort_main(int* A, int array_size)
{
    int max;
    int temp;
   for (int j = array_size - 1; j >= 1; j--)
    {
        max = j;
        for (int i = j - 1; i >= 0; i--)
        {
            if (A[i] > A[max])
                max = i;
        }
        temp = A[j];
        A[j] = A[max];
        A[max] = temp;

    }
}

void merge_sort_main(int* a, int array_size)
{
    int* b = new int[array_size];
    merge_sort(a, 0, array_size - 1, b);
}

void merge_sort(int* a, int left, int right, int* b)
{
    int middle = (left + right) / 2;
    if ((middle - left) > 0)
    {
        merge_sort(a, left, middle, b);
    }
    if ((right - middle) > 0)
    {
        merge_sort(a, middle + 1, right, b);
    }
    int i = left;
    int j = middle + 1;
    for (int k = left; k <= right; k++)
    {
        if (((i <= middle) && (j > right)) || (((i <= middle) && (j <= right)) && a[i] <= a[j]))
        {
            b[k] = a[i];
            i = i + 1;
        }
        else
        {
            b[k] = a[j];
            j = j + 1;
        }
    }
    for (int k = left; k <= right; k++)
        a[k] = b[k];
}

void heap_sort_main(int* a, int array_size)
{
    build_heap(a, array_size);
    int heapsize = array_size - 1;
    int temp = heapsize;
    for (int i = temp; i >= 1; i--)
    {
        switch_elements(&a[0], &a[i]);
        heapsize--;
        heapify(a, 0, heapsize);
    }
}

void build_heap(int* a, int array_size)
{
    int heapsize = array_size - 1;
    for (int i = heapsize / 2; i >= 0; i--)
    {
        heapify(a, i, array_size);
    }
}

void heapify(int* a, int i, int heapsize)
{
    int largest;
    int left = 2 * i + 1;
    int right = (2 * i) + 2;
    if (left <= heapsize && a[left] > a[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }
    if (right <= heapsize && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        switch_elements(&a[i], &a[largest]);
        heapify(a, largest, heapsize);
    }
}

void switch_elements(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort_main(int* a, int array_size)
{
    quicksort(a, 0, array_size - 1);
}

void quicksort(int* a, int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(a, p, r);
        quicksort(a, p, q);
        quicksort(a, q + 1, r);
    }
}

int partition(int* a, int p, int r)
{
    int x = a[(p + r) / 2];
    int i = p - 1;
    int j = r + 1;
    while (true)
    {
        do
            j = j - 1;
        while (a[j] > x);

        do
            i++;
        while (a[i] < x);

        if (i < j)
        {
            switch_elements(&a[i], &a[j]);
        }
        else
        {
            return j;
        }
    }
}
