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

using namespace std;

int main(int argc, char const *argv[])
{
    bool hourBool = false;
    bool graphBool = false;
    bool excludeFileBool = false;

    string graph;
    string hour = "0";
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

    string serveur = "http://intranet-if.insa-lyon.fr";
    LogManager logManager(logFile, serveur, graphBool, hourBool, stoi(hour), excludeFileBool);
    logManager.TreatLog();

    logManager.GetStats().PrintTop10();

    if(graphBool)
    {
        logManager.GetStats().CreateGraph(graph);
        string out = ChangeExtensionDotInPng(graph);
        system(("dot -Tpng -o "+ out + " " + graph).c_str());
    }
    else
    {
        cout << "Pas de graphique demandé" << endl;
    }


    return 0;
}