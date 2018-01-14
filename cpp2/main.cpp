#include <iostream>
#include <cmath>

using namespace std;
float dist (float v, float a)
{
    float d = v * v * sin(2 * a * M_PI / 180) / 9.81;
    return d;
}
int main()
{
    float a, v;
    cout << "Введите скорость : ";
    cin >> v;
    cout << "Введите угол : ";
    cin >> a;
    float res = dist(v, a);
    cout << "Расстояние : " << res << endl;
}
