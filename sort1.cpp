#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void fill(int mas[], int size, int minrand, int maxrand)
{
    for (int i = 0; i < size; i++)
    {
        mas[i] = minrand + rand() % (maxrand - minrand + 1);
    }
}


void show(int mas[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mas[i] << " ";
    }
    cout << "\n";
}

void sort_select(int mas[], int size)
{
    int x, count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int k = i;
        for (int j = i+1 ; j < size; j++)
        {
            if (mas[j] < mas[k])
            {
                k = j;
            }
        }
        if (k > i)
        {
            x = mas[k];
            mas[k] = mas[i];
            mas[i] = x;
            count++;
        }
        show(mas, size);
    }
    cout << count << "\n";
}

void sort_bubble(int mas[], int size)
{
    int x, count=0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (mas[j + 1] < mas[j])
            {
                x = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = x;
                count++;
            }
        }
        show(mas, size);
    }
    cout << count << "\n";
}

void sort_insert(int mas[], int size)
{
    int x, count=0;
    for (int i = 1; i < size; i++)
    {
        for (int j = i; (j >= 0) && (mas[j] < mas[j - 1]); j--)
        {
            x = mas[j];
            mas[j] = mas[j - 1];
            mas[j - 1] = x;
            count++;
        }
        show(mas, size);
    }
    cout << count << "\n";
}

int main()
{
    setlocale(0, "");
    srand(100);
    const int size = 20;
    int mas[size] = { 8, 7, 3, 4, 2, 9, 1, 8 };
    fill(mas, size, 0, 40);
    show(mas, size);
    //cout << endl;
    cout << "Этапы сортировки\n";
    sort_insert(mas, size);
}
