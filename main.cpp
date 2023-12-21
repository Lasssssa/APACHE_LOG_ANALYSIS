#include "LogManager.h"
#include "Utils.h"
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // Création des variables pour les paramètres de la ligne de commande
    bool hourBool, graphBool, excludeFileBool, configBool;
    // Initialisation des variables à false
    hourBool = false;
    graphBool = false;
    excludeFileBool = false;

    // Initialisation des variables à 0
    std::string graph, logFile, config;
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
        if(param == "-c")
        {
            configBool = true;
            config = argv[i+1];
        }
    }
    Utils utilsConfig;
    if(!configBool){
        cout << "Pas de fichier de configuration précisé : utilisation du fichier par défaut" << endl;
        config = "config.txt";
    }
    std::string server = utilsConfig.getServeurFromConfigFile(config);
    vector<std::string> ignoredFile = utilsConfig.getIgnoredFileFromConfigFile(config);

    LogManager logManager(logFile, server, ignoredFile, graphBool, hourBool, stoi(hour), excludeFileBool);
    logManager.TreatLog();

    logManager.GetStats().PrintTop10();

    if(graphBool){
        logManager.GetStats().CreateGraph(graph);
        string out = utilsConfig.ChangeExtensionDotInPng(graph);
        system(("dot -Tpng -o "+ out + " " + graph).c_str());
    }else{
        cout << "Pas de graphique demandé" << endl;
    }

    return 0;
}