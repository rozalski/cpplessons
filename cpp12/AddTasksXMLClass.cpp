#include "AddTasksXMLClass.h"


void AddTasksXML::setTask()
{
//    std::ofstream foutTasks;
//    foutTasks.open("tasks.tsk", std::ios::app);
//    //тут мы будем добавлять новые задания
//    foutTasks.close();
}
std::vector<std::string> AddTasksXML::getTasks()
{
    std::fstream finTasks;
    std::string taskBuf;                // создаем буфер, куда будет считываться информация
    std::vector<std::string> result; // создаем символьный вектор для хранения параметров

//    std::vector<this->oneTask> t;

    finTasks.open("tasks.tsk", std::ios::in);   // открываем файл для чтения
    if (finTasks)                              // если файл открылся
    {
        while (getline(finTasks, taskBuf, ';'))         //  Пока мы получили строку - тело цикла исполняется ||  когда файл закончился (все строки считались) - цикл false
        {
            result.push_back(taskBuf);
        }
    }
    return result;
}



