#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
// шаблонная функция. В ней использовать можно любые типы
template <typename Tfunc1, typename Tfunc2>
void swapfunc(Tfunc1 item1, Tfunc2 item2)
{
    cout << "Передали в шаблонну функцию: " << endl;
    cout << "item1: " << item1 << endl;
    cout << "item2: " << item2 << endl;
    Tfunc1 temp = item1;
    item1 = item2;
    item2 = temp;
    cout << "Поменяли местами: " << endl;
    cout << "item1: " << item1 << endl;
    cout << "item2: " << item2 << endl;

}

int main()
{

// работа с шаблонной функцией
    cout << "Передаем в функцию 2 чара" << endl;
    char a = 's', b = 'w';
    swapfunc(a,b);
    cout << "Передаем в функцию 2 инта" << endl;
    int x = 5, y = 7;
    swapfunc(x,y);


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
    for(int i=0; i<=1000; i++)
    {
        vec_int.push_back(i);
    }
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

    for(int i=0; i<=10000; i++)
    {
        vec_int.push_back(i);
    }
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;

    for(int i=0; i<=100000; i++)
    {
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
    cout << vec_int.capacity() << " зарезервировано под вектор... ничего не поменялось"<< endl;
    cout << "Запихиваем в вектор 3 значения" << endl;
    for(int i=0; i<=2; i++)
    {
        vec_int.push_back(i);
    }

    cout << "Значения хранящиеся в векторе: "<<endl;
    for(int i =0; i<vec_int.size(); i++)
    {
        cout << vec_int[i] << " ";

    }

    cout << endl << "Теперь вставим значения после 2 элемента вектора. Вставим 3 элемента со значением 0" << endl;
    vec_int.insert(vec_int.begin()+2, 3, 0); // первое это итератор на начала вектора +2, затем сколько вставить и значения
    cout << vec_int.size() << " размер вектора"<< endl;
    cout << vec_int.capacity() << " зарезервировано под вектор"<< endl;
    cout << "Значения хранящиеся в векторе: "<<endl;
    for(int i =0; i<vec_int.size(); i++)
    {
        cout << vec_int[i] << " ";

    }



    return 0;
}



