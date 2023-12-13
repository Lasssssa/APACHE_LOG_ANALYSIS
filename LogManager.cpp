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
                stats.AddLog(log);
            }
        }
        else{
            stats.AddLog(log);
        }
    }
}

//void LogManager::FillLog ( Stats & stats, bool excludeFile, bool heurebool, string hour)
//// Algorithme :
////
//{
//    string serveur = "http://intranet-if.insa-lyon.fr";
//    std::string ligne;
//        while (std::getline(LogFile, ligne)) {
//            std::istringstream iss(ligne);
//            std::string mot;
//            bool skip = false;
//            std::string ip, userLogname, authenticatedUser, date, request, target, status, quantity, url, userAgent;
//            std::string jour, mois, annee, heure, minute, seconde;
//
//            int compt = 0;
//            while (std::getline(iss, mot, '"')) {
//                if (!mot.empty()) {
//                    if (compt == 0) {
//                        parse_ip_dash_date(mot, ip, userLogname, authenticatedUser, date);
//                        parse_date(date, jour, mois, annee, heure, minute, seconde);
//                    }
//                    if (compt == 1) {
//                        parse_request(mot, request, target);
//                        if (excludeFile) {
//                            if (target.find(".css") != string::npos || target.find(".js") != string::npos ||
//                                target.find(".png") != string::npos || target.find(".jpg") != std::string::npos ||
//                                target.find(".ico") != std::string::npos || target.find(".gif") != std::string::npos ||
//                                target.find(".svg") != std::string::npos) {
//                                skip = true;
//                            }
//
//                        }
//                    }
//                    if (compt == 2) {
//                        parse_status_quantity(mot, status, quantity);
//                    }
//                    if (compt == 3) {
//                        //On souhaite retirer le serveur de l'url : http://intranet-if.insa-lyon.fr
//                        if(mot.find(serveur) != string::npos){
//                            url = mot.substr(serveur.length(), mot.length());
//                        }
//                        else{
//                            url = mot;
//                        }
//                    }
//                    if (compt == 5) {
//                        userAgent = mot;
//                    }
//                    compt++;
//                }
//            }
//            if (heurebool) {
//                //Ajoute 1h à l'heure hour
//                int hourInt = stoi(hour);
//                int heureInt = stoi(heure);
//                if (heureInt >= hourInt && heureInt < hourInt + 1 && !skip) {
//                    Log log(ip, userLogname, authenticatedUser, heure, request, target, status, quantity, url,
//                            userAgent);
//                    stats.AddLog(log);
//                }
//            } else if(!skip){
//                Log log(ip, userLogname, authenticatedUser, heure, request, target, status, quantity, url, userAgent);
//                stats.AddLog(log);
//            }
//
//        }
//*
//        }



//----------------------------------------------------- Méthodes publiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées