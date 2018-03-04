/*Сортировка пузырьком
Определите, сколько обменов сделает алгоритм пузырьковой сортировки по возрастанию для данного массива.

Формат входных данных:
На первой строке дано целое число n (1 ≤ n ≤ 1000) – количество элементов в массиве.
На второй строке – сам массив. Гарантируется, что все элементы массива – различные целые числа,
не превышающие по модулю 10^9.

Формат выходных данных:
Выведите одно число – количество обменов пузырьковой сортировки.*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1000;

void input(int *a, int size) {
    for(int i = 0; i < size; ++i) {
        cin >> a[i]; // ввод массива
    }
}

void bubbleSort(int *array, int size) {
    int swap_counter = 0;
    for(int i = 1; i < size; ++i) {
        for(int j = 1; j <= size - i; ++j) {
            if(array[j - 1] > array[j]) {
                swap(array[j - 1], array[j]);
                swap_counter++;
            }
        }
    }
    cout << swap_counter;
}

int main() {
    int mainArray[MAX_SIZE], size;
    cin >> size;
    input(mainArray, size);
    bubbleSort(mainArray, size);
    return 0;
}
