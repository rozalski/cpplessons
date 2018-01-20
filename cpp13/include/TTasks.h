#ifndef TTASKS_H
#define TTASKS_H
#include <iostream>
#include <fstream>
//#include <string>
#include <cstring>
//#include <iterator>
#include <vector>
#include <cstdlib>

class TTasks
{
    public:
    struct oneTask{
        char inPath[255];
        char outPath[255];
        int lid;
    };

      void getTasks();

private:
    std::vector<std::string> split(std::string &strToSplit);
};

#endif // TTASKS_H
