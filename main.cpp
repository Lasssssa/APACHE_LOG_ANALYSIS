#include "LogManager.h"
#include "Log.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    bool hourBool = false;
    // bool graphBool = false;
    bool excludeFileBool = false;

    // string graph;
    string hour;
    string logFile;

<<<<<<< HEAD
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
=======
    for(int i = 0; i < argc; i++)
    {
        string param = argv[i];
        if (param == "-g")
        {
            graphBool = true;
            graph = argv[i+1];
        }
        if(param == "-e")
        {
            excludeFileBool = true;
        }
        if(param == "-t")
        {
            hourBool = true;
            hour = argv[i+1];
        }
        if(i == argc-1)
        {
            logFile = argv[i];
        }
    }

>>>>>>> ba45b5d38637b33a84478b5ca0976f8f1a41e433
    Stats stats;
    LogManager logManager(logFile);
    logManager.FillLog(stats, excludeFileBool, hourBool, hour);

    stats.PrintTop10();

    if(graphBool)
    {
        stats.CreateGraph(graph);
        system(("dot -Tpng -o out.png " + graph).c_str());
    }
    else
    {
        cout << "Pas de graphique demandé" << endl;
    }


    return 0;
}