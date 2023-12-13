#include "LogManager.h"
#include "Log.h"
#include <iostream>
#include <fstream>

using namespace std;

string ChangeExtensionDotInPng(string name)
{
    string newName = "";
    for(int i = 0; i < name.size(); i++)
    {
        if(name[i] == '.')
        {
            newName += ".png";
            return newName;
        }
        else
        {
            newName += name[i];
        }
    }
    return newName;
}

int main(int argc, char const *argv[])
{
    bool hourBool = false;
    bool graphBool = false;
    bool excludeFileBool = false;

    string graph;
    string hour;
    string logFile;

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

    Stats stats;
    LogManager logManager(logFile);
    logManager.FillLog(stats, excludeFileBool, hourBool, hour);

    stats.PrintTop10();

    if(graphBool)
    {
        stats.CreateGraph(graph);
        string out = ChangeExtensionDotInPng(graph);
        system(("dot -Tpng -o "+ out + " " + graph).c_str());
    }
    else
    {
        cout << "Pas de graphique demandé" << endl;
    }


    return 0;
}