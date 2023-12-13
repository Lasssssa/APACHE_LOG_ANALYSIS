// Description: Fonctions annexes pour le projet

#include "FonctionsAnnexe.h"
#include <iostream>
#include <fstream>
#include <string>

std::string ChangeExtensionDotInPng(std::string name)
{
    std::string newName = "";
    for(std::string::size_type i = 0; i < name.size(); i++)
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

std::string getServeurFromConfigFile(std::string configFile)
{
    std::ifstream file(configFile);
    std::string line;
    std::string serveur;
    if(!file)
    {
        std::cout << "Erreur lors de l'ouverture du fichier de configuration" << std::endl;
        return "";
    }
    while(std::getline(file, line))
    {
       if(line[0] != '#')
       {
           size_t pos = line.find("server:");
           if (pos != std::string::npos) {
               return line.substr(pos + 7);
           }
       }
    }
    return serveur;
}