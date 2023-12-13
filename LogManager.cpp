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
    while(reader.good()){
        Log log = reader.ReadLog();
        if(excludeFile){
            if(log.target.find(".css") != string::npos || log.target.find(".js") != string::npos || log.target.find(".png") != string::npos || log.target.find(".jpg") != std::string::npos || log.target.find(".ico") != string::npos || log.target.find(".gif") != string::npos || log.target.find(".svg") != string::npos){
                continue;
            }
        }
        if(HourBool){
            //Ajoute 1h à l'heure hour
            int hourInt = Hour;
            int heureInt = stoi(log.hour);
            if (heureInt >= hourInt && heureInt < hourInt + 1) {
                stats << log;
            }
        }
        else{
            stats << log;
        }
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées