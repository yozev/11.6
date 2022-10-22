/*Что нужно сделать

Пользователь вводит в консоль 15 дробных чисел. Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему. По возможности используйте минимум дополнительной памяти и проходов по массиву.
Пример

Ввод: 1.2 2.3 1.11 3.4 5.5 5.4 5.3 5.1 1.5 1.25 5.41 5.31 5.11 1.51 1.251 
Вывод: 5.5 5.41 5.4 5.31 5.3 5.11 5.1 3.4 2.3 1.51 1.5 1.251 1.25 1.2 1.11*/
#include <iostream>

/*void swap_float(float a, float b)
{
    float c;
    c = a;
    a = b;
    b = c;
}*/

void heapify(float arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[largest])
        largest = l;
    if (r < n && arr[r] < arr[largest])
        largest = r;
    if (largest != i)
    {
        //swap_float(arr[i], arr[largest]);
        float temp;
        temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(float arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        //swap_float(arr[0], arr[i]);
        float temp;
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    float arr[15];
    int n = 15;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    heapSort(arr, n);
    //swap_float(arr[1], arr[0]);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "  ";
    }
}
