//-------------------Réalisation de la classe <LogManager> (fichier LogManager.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "LogManager.h"
#include "Log.h"
#include "Stats.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
LogManager::LogManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogManager>" << endl;
#endif
} //----- Fin de LogManager

LogManager::LogManager ( const char * file )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogManager>" << endl;
#endif
LogFile.open(file);

if (LogFile.good())
{
    cout << "Le fichier de log a bien été chargé." << endl;
}
else
{
    cout << "Le fichier de log n'a pas pu être chargé." << endl;
}
}

LogManager::~LogManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogManager>" << endl;
#endif
LogFile.close();
}



void LogManager::FillLog ( Stats & stats )
// Algorithme :
//
{

FormatLog();
//stats.AddLog(log);

}

void LogManager::FormatLog()
{
    std::string ligne;
    while (std::getline(LogFile, ligne))
    {
        // Utiliser std::istringstream pour séparer les espaces
        std::istringstream iss(ligne); // Use std::istringstream instead of istringstream
        std::string mot;

        // Parcourir les mots dans la ligne
        while (iss >> mot)
        {
            // Faire quelque chose avec le mot, par exemple l'afficher
            std::cout << "Mot : " << mot << std::endl;
        }
    }
}




//----------------------------------------------------- Méthodes publiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées