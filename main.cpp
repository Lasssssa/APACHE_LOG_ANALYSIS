#include "LogManager.h"
#include "Log.h"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    bool hourBool = false;
    bool graphBool = false;
    bool excludeFileBool = false;

    for(int i = 0; i < argc; i++)
    {
        if (argv[i] == "-g")
        {
            graphBool = true;
            string graph = argv[i+1];
        }
        if(argv[i] == "-e")
        {
            excludeFileBool = true;
        }
        if(argv[i] == "-t")
        {
            hourBool = true;
            string hour = argv[i+1];
        }
        if(i == argc-1)
        {
            string logFile = argv[i];
        }
    }
    Stats stats;
    LogManager logManager(logFile, excludeFileBool, hourBool, hour);

    stats.printTop10();


    return 0;
}