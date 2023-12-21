//-------------------Réalisation de la classe <Utils> (fichier Utils.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Utils::Utils ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Utils>" << endl;
#endif

} //----- Fin de Utils

Utils::~Utils ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Utils>" << endl;
#endif
}

//----------------------------------------------------- Méthodes publiques

std::string Utils::ChangeExtensionDotInPng(std::string name)
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

std::string Utils::getServeurFromConfigFile(std::string configFile)
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
                serveur = line.substr(pos + 7);
            }
        }
    }
    //On retire le dernier caractère de la chaine de caractère qui est un espace
    serveur = serveur.substr(0, serveur.length()-1);
    return serveur;
}

std::vector<std::string> Utils::getIgnoredFileFromConfigFile(std::string configFile)
// Algorithme :
// Parcours du fichier de configuration
// Si on trouve la ligne ignoredFile: on récupère le nom des fichiers à ignorer
{
    std::vector<std::string> ignoredFilesArray;
    std::ifstream file(configFile);
    std::string line;
    if(!file)
    {
        std::cout << "Erreur lors de l'ouverture du fichier de configuration" << std::endl;
        return std::vector<std::string>();
    }
    while(std::getline(file, line))
    {
        if(line[0] != '#')
        {
            size_t pos = line.find("ignoreFiles:");
            if (pos != std::string::npos) {
                std::string ignoredFiles = line.substr(pos + 12);
                std::string delimiter = ",";
                size_t pos = 0;
                std::string token;
                while ((pos = ignoredFiles.find(delimiter)) != std::string::npos) {
                    token = ignoredFiles.substr(0, pos);
                    ignoredFilesArray.push_back(token);
                    ignoredFiles.erase(0, pos + delimiter.length());
                }
                ignoredFilesArray.push_back(ignoredFiles);
            }
        }
    }
    return ignoredFilesArray;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées