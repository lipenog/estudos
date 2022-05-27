#include <stdio.h>
#include <iostream>

using namespace std;

void read(int *ptr)
{
    int aux;
    do {
        cin >> aux;
        *ptr = aux;
        ptr++;            
    } while (aux != -1);
}

void print(int *ptr)
{
    while (*ptr != -1)
    {
        cout << *ptr << " ";
        ptr++;
    }
}

int getlen(int *ptr) 
{
    int i = 0;
    while (*ptr != -1)
    {
        i++;
        ptr++;
    }
    return i;
}

void Bubble_sort(int *ptr) 
{
    int n, aux;
    n = getlen(ptr);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++)
        {
            if (ptr[j] > ptr[j+1]) 
            {
                aux = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = aux;
            }
        }
    }

}

int main (void) 
{
    int a[10];
    read(a);
    cout << "Before: " << endl;
    print(a);
    Bubble_sort(a);
    cout << endl <<"After: " << endl;
    print(a);
    return 0;
}
