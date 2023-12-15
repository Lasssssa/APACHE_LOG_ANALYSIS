//-------------------Réalisation de la classe <LogManager> (fichier LogManager.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "LogManager.h"
#include "Log.h"
#include "Stats.h"
#include "Reader.h"
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
LogManager::LogManager(const string file, string serveur, bool exportDot, bool HourBool, int Hour, bool excludeFile) : reader(file,serveur), stats(), exportDot(exportDot), HourBool(HourBool), Hour(Hour), excludeFile(excludeFile)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogManager>" << endl;
#endif
}

LogManager::~LogManager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogManager>" << endl;
#endif
}

//----------------------------------------------------- Méthodes publiques
void LogManager::TreatLog()
{
    //On lit le fichier log et on traite les logs un par un
    while(reader.good()){
        //On récupère le log courant dans la variable log grâce à la méthode ReadLog de la classe Reader
        Log log = reader.ReadLog();

        //On vérifie que le log n'est pas vide
        if(log.target == ""){
            continue;
        }

        //On vérifie que le log ne contient pas de .css, .js, .png, .jpg, .ico, .gif, .svg si l'option excludeFile est activée
        if(excludeFile){
            if(log.target.find(".css") != string::npos || log.target.find(".js") != string::npos || log.target.find(".png") != string::npos || log.target.find(".jpg") != std::string::npos || log.target.find(".ico") != string::npos || log.target.find(".gif") != string::npos || log.target.find(".svg") != string::npos){
                continue;
            }
        }

        //On vérifie que le log est bien dans la plage horaire si l'option HourBool est activée
        if(HourBool){
            //Ajoute 1h à l'heure hour
            int hourInt = Hour;
            int heureInt = stoi(log.hour);
            if (heureInt >= hourInt && heureInt < hourInt + 1) {
                //On ajoute le log à la liste des logs
                stats << log;
            }
        }
        else{
            //On ajoute le log à la liste des logs
            stats << log;
        }
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées