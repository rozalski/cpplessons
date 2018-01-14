#include <iostream>

using namespace std;

int main()
{
int num;
    cout << "Введите число : ";
    cin >> num;
    for (int i =2; i < 10; i++){
        cout << num << " * " << i << " = " << num * i << endl;
    }
    return 0;
}
