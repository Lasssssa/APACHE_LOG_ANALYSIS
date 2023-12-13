#include "LogManager.h"
#include "Log.h"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    bool hourBool = false;
    // bool graphBool = false;
    bool excludeFileBool = false;

    // string graph;
    string hour;
    string logFile;

    // for(int i = 0; i < argc; i++)
    // {
    //     if (argv[i] == "-g")
    //     {
    //         graphBool = true;
    //         graph = argv[i+1];
    //     }
    //     if(argv[i] == "-e")
    //     {
    //         excludeFileBool = true;
    //     }
    //     if(argv[i] == "-t")
    //     {
    //         hourBool = true;
    //         hour = argv[i+1];
    //     }
    //     if(i == argc-1)
    //     {
    //         logFile = argv[i];
    //     }
    // }
    logFile = argv[1];
    cout << logFile << endl;
    Stats stats;
    LogManager logManager(logFile);
    logManager.FillLog(stats, excludeFileBool, hourBool, hour);

    //stats.PrintTop10();

//    if(graphBool)
//    {
//        stats.CreateGraph(graph);
//    }
//    else
//    {
//        cout << "Pas de graphique demandé" << endl;
//    }


    return 0;
}