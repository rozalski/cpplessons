#ifndef ADDTASKSXMLCLASS_H_INCLUDED
#define ADDTASKSXMLCLASS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class AddTasksXML
{


public:
//struct oneTask{
//    char inputPath[255];
//    char outputPath[255];
//    int lid;
//};

    std::vector<std::string> getTasks();
    void setTask();




};


#endif // ADDTASKSXMLCLASS_H_INCLUDED

