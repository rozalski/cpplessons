#include <iostream>
#include "AddTasksXMLClass.h"
using namespace std;

void display(string str)
{
    cout<<str<<endl;

}

int main()
{
    vector<string> readingTasks;
    AddTasksXML* tsk = new AddTasksXML;
    tsk->setTask();
    readingTasks = tsk->getTasks();
    for(int i=3; i<readingTasks.size();i++){

        display(readingTasks[i]);
    }

    delete tsk;

    return 0;
}
