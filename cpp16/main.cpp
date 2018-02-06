#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> vec_int;

    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;
    cout << vec_int.max_size() << " максимальный размер вектора"<< endl;
    if(vec_int.empty())
    {
        vec_int.push_back(12);

    }
    cout << vec_int[0] << " введенное в вектор значение" << endl;
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;
    vec_int.push_back(10);
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;
    vec_int.push_back(7);
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;
    cout << "Значения хранящиеся в векторе: "<<endl;
    for(int i =0; i<vec_int.size(); i++)
    {
        cout << vec_int[i] << " ";

    }
    cout << endl;
    for(int i=0; i<=1000; i++){
        vec_int.push_back(i);
    }
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

        for(int i=0; i<=10000; i++){
        vec_int.push_back(i);
    }
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

    for(int i=0; i<=100000; i++){
        vec_int.push_back(i);
    }
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

    cout << "Делаем ресайз вектора... "<<endl;
    vec_int.resize(3);
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

    cout << "Делаем clear() вектора... "<<endl;
    vec_int.clear();
     cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

    cout << "Делаем swap() вектора... "<<endl;
    vec_int.swap(vec_int);
     cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;


    return 0;
}
