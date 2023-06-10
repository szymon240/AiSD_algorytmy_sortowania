#include "Arrays.h"

void generate_random_array(int* a, int array_size)
{
    srand(time(NULL));
    for (int i = 0; i < array_size; i++)
    {
        a[i] = (rand() % 100) + 1;
    }
}

void generate_increasing_array(int* a, int array_size)
{
    srand(time(NULL));
    a[0] = (rand() % 10) + 1;
    for (int i = 1; i < array_size; i++)
    {
        a[i] = (rand() % 10) + 1 + a[i - 1];
    }
}

void generate_decreasing_array(int* a, int array_size)
{
    srand(time(NULL));
    a[array_size - 1] = (rand() % 10) + 1;
    for (int i = array_size - 2; i >= 0; i--)
    {
        a[i] = (rand() % 10) + 1 + a[i + 1];
    }
}

void generate_constant_array(int* a, int array_size)
{
    srand(time(NULL));
    int valueforconst = (rand() % 10) + 1;
    for (int i = 0; i < array_size; i++)
    {
        a[i] = valueforconst;
    }
}

void generate_vshaped_array(int* a, int array_size)
{
    srand(time(NULL));
    int half = array_size / 2 - 1;
    if (array_size % 2 == 1)
        half++;
    a[0] = (rand() % 10) + 1;
    for (int i = 1; i <= half; i++)
    {
        a[i] = (rand() % 10) + 1 + a[i - 1];
    }
    for (int i = half + 1; i < array_size; i++)
    {
        a[i] = a[i - 1] - ((rand() % 10) + 1);
        while (a[i] == 0)
        {
            a[i] = a[i - 1] - ((rand() % 10) + 1);
        }
    }
}

void generate_ashaped_array(int* a, int array_size)
{
    srand(time(NULL));
    int half = array_size / 2 - 1;
    if (array_size % 2 == 1)
        half++;
    a[half] = (rand() % 10) + 1;
    for (int i = half - 1; i >= 0; i--)
    {
        a[i] = (rand() % 10) + 1 + a[i + 1];
    }
    for (int i = half + 1; i < array_size; i++)
    {
        a[i] = (rand() % 10) + 1 + a[i - 1];
    }
    for (int i = 0; i < array_size; i++)
        std::cout << a[i] << " ";
}
