// Description: Fonctions annexes pour le projet

#include "FonctionsAnnexe.h"
#include <iostream>
#include <fstream>
#include <string>

std::string ChangeExtensionDotInPng(std::string name)
// Algorithme :
// Parcours de la chaine de caractère name
// Si on trouve un point, on ajoute .png à la chaine de caractère
// Sinon on ajoute le caractère à la chaine de caractère
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
// Algorithme :
// Parcours du fichier de configuration
// Si on trouve la ligne server: on récupère le nom du serveur
// Sinon on retourne une chaine de caractère vide
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