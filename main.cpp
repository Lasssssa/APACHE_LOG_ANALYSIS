#include "LogManager.h"
#include "FonctionsAnnexe.h"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    bool hourBool = false;
    bool graphBool = false;
    bool excludeFileBool = false;

    std::string graph, logFile;
    std::string hour = "0";

    if(argc < 2)
    {
        cout << "Pas assez d'arguments" << endl;
        cout << "Usage : ./prog [-g graph.dot] [-t hour] [-e] logFile" << endl;
        return 1;
    }

    for(int i = 0; i < argc; i++)
    {
        std::string param = argv[i];
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

    std::string server = getServeurFromConfigFile("config.txt");
    LogManager logManager(logFile, server, graphBool, hourBool, stoi(hour), excludeFileBool);
    logManager.TreatLog();

    logManager.GetStats().PrintTop10();
    if(graphBool){
        logManager.GetStats().CreateGraph(graph);
        string out = ChangeExtensionDotInPng(graph);
        system(("dot -Tpng -o "+ out + " " + graph).c_str());
    }else{
        cout << "Pas de graphique demandé" << endl;
    }


    return 0;
}