#include <iostream>

/*
including stl
*/
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void display(char* str)
{

    cout << str << endl;

}
void intdisplay(int* num){

        cout << num << endl;
}


int main()
{

    vector<char*> charArray;
    vector<int*> intArray;

    charArray.push_back((char*)"str1");
    charArray.push_back((char*)"str2");
    charArray.push_back((char*)"str3");
    charArray.push_back((char*)"str4");


    vector<char*>::iterator iterStart = charArray.begin();
    vector<char*>::iterator iterEnd = charArray.end();

    for_each(iterStart, iterEnd, display);


    intArray.push_back((int*)1);
    intArray.push_back((int*)2);
    intArray.push_back((int*)3);
    vector<int*>::iterator intIterStart = intArray.begin();
    vector<int*>::iterator intIterEnd = intArray.end();

    for_each(intIterStart, intIterEnd, intdisplay);



    return 0;
}
