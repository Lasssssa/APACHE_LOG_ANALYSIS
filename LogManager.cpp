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
LogManager::LogManager(const string file, string serveur, vector<std::string> ignoredFile, bool exportDot, bool HourBool, int Hour, bool excludeFile) : reader(file,serveur), stats(), exportDot(exportDot), HourBool(HourBool), Hour(Hour), excludeFile(excludeFile)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogManager>" << endl;
#endif
    this->ignoredFile = ignoredFile;
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
    bool uploadLog = true;
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
            //On récupère l'extension du fichier cible et on la compare avec les extensions à ignorer qui sont dans le tableau ignoredFile
            string extension = log.target.substr(log.target.find_last_of(".") + 1);
            for(long unsigned int i = 0; i < ignoredFile.size(); i++){
                if(extension == ignoredFile[i]) {
                    //Si l'extension est dans le tableau, on passe au log suivant
                    uploadLog = false;
                    continue;
                }
            }
        }

        //On vérifie que le log est bien dans la plage horaire si l'option HourBool est activée
        if(HourBool){
            //Ajoute 1h à l'heure hour
            int hourInt = Hour;
            int heureInt = stoi(log.hour);
            if (heureInt >= hourInt && heureInt < hourInt + 1) {
                //On ajoute le log à la liste des logs
                if(uploadLog){
                    stats << log;
                }
            }
        }
        else{
            //On ajoute le log à la liste des logs
            if(uploadLog){
                stats << log;
            }
        }
        uploadLog = true;
    }
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées