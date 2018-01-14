#include <iostream>
#include <stdlib.h>
using namespace std;
/*
Заполняем массив случайными значениями
Затем выбираем только нечетные числа
*/
int main()
{
    int mass[20];
    for(int i=0; i<20; i++)
    {
        mass[i] = rand();
    }
    for(int i = 0; i<20; i++)
    {
        if(mass[i]%2 != 0)
        {
            cout << mass[i] << endl;
        }

    }
    return 0;
}
