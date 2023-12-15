#include "LogManager.h"
#include "FonctionsAnnexe.h"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // Création des variables pour les paramètres de la ligne de commande
    bool hourBool, graphBool, excludeFileBool;
    // Initialisation des variables à false
    hourBool = false;
    graphBool = false;
    excludeFileBool = false;

    // Initialisation des variables à 0
    std::string graph, logFile;
    std::string hour = "0";

    // Vérification du nombre d'arguments passé en paramètre du programme
    if(argc < 2)
    {
        cout << "Pas assez d'arguments" << endl;
        cout << "Usage : ./prog [-g name.dot] [-t hour] [-e] logFile" << endl;
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
    vector<std::string> ignoredFile = getIgnoredFileFromConfigFile("config.txt");
    LogManager logManager(logFile, server, ignoredFile, graphBool, hourBool, stoi(hour), excludeFileBool);
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