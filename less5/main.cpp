#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int mass[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
           mass[i][j] = rand() % 100 + 1;
        }
    }
    system("clear"); // очищаем консоль
    cout << "Получен масссив : " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
