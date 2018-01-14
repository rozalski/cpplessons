#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 10
int main()
{
    int mass[MAX][MAX];
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            mass[i][j] = rand() % 99 + 1;
        }
    }
    system("clear"); // очищаем консоль
    cout << "Получен масссив : " << endl;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(mass[i][j]<10)
                cout << mass[i][j] << "    ";
            else
                cout << mass[i][j] << "   ";
        }
        cout << endl << endl;
    }
    cout << "Сортировка массива...." << endl;
    bool sorted=false;
    int temp;
    while(!sorted)
    {
        sorted=true;
        int i=0, j=0;
        for(int inext=0; inext<MAX; inext++)
            for(int jnext=(inext?0:1); jnext<MAX; jnext++)
            {
                if(mass[i][j]>mass[inext][jnext])
                {
                    temp=mass[i][j];
                    mass[i][j]=mass[inext][jnext];
                    mass[inext][jnext]=temp;
                    sorted=false;
                }
                i=inext;
                j=jnext;
            }

    }

    cout << "Получен масссив : " << endl;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(mass[i][j]<10)
                cout << mass[i][j] << "    ";
            else
                cout << mass[i][j] << "   ";
        }
        cout << endl << endl;
    }

    return 0;
}
