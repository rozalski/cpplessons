/*
Динамическое создание массива
с испльзованием указателя
*/

#include <iostream>

using namespace std;

int main()
{
    int count_mas;
    cout << "Введите количество элементов массива: ";
    cin >> count_mas;
    cout << "Введите значения массива: "<< endl;
    int* arr = new int[count_mas]; // выделение памяти под массив
    for(int i = 0; i< count_mas; i++)
    {
        cin >> arr[i];
    }
    cout << "Вы ввели следующие значения массива: " << endl;
    for(int i = 0; i< count_mas; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
    delete [] arr; // освобождение памяти

    return 0;
}
