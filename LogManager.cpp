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

LogManager::LogManager ( const string file )
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



void LogManager::FillLog ( Stats & stats, bool excludeFile, bool heurebool, string hour)
// Algorithme :
//
{

std::string ligne;
        while (std::getline(LogFile, ligne)) {
            std::istringstream iss(ligne);
            std::string mot;
            string *tab_compo[6];

            std::string ip, userLogname, authenticatedUser, date, request, target, status, quantity, url, userAgent;
            std::string jour, mois, annee, heure, minute, seconde;

            int compt = 0;
            while (std::getline(iss, mot, '"')) {
                if (!mot.empty()) {
                    if (compt == 0) {
                        parse_ip_dash_date(mot, ip, userLogname, authenticatedUser, date);
                        parse_date(date, jour, mois, annee, heure, minute, seconde);
                    }
                    if (compt == 1) {
                        parse_request(mot, request, target);
                    }
                    if (compt == 2) {
                        parse_status_quantity(mot, status, quantity);
                    }
                    if (compt == 3) {
                        url = mot;
                    }
                    if (compt == 5) {
                        userAgent = mot;
                    }
                    tab_compo[compt] = new string(mot);
                    compt++;
                }
            }
            //cout << request << endl;
            Log log(ip, userLogname, authenticatedUser, heure, request, target, status, quantity, url, userAgent);
            stats.AddLog(log);
        }

}



//----------------------------------------------------- Méthodes publiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

void LogManager::parse_ip_dash_date(const std::string& line, std::string& ip, std::string& firstDash, std::string& secondDash, std::string& inBrackets) {
    std::istringstream iss(line);
    
    // Lecture des valeurs séparées par des espaces
    iss >> ip >> firstDash >> secondDash;

    // Lecture de la partie entre crochets en considérant le reste de la ligne
    std::getline(iss, inBrackets, ']');
    // Supprimer l'espace après '['
    inBrackets.erase(0, 2);
}

void LogManager::parse_status_quantity(const std::string& line, std::string& status, std::string& quantity) {
    std::istringstream iss(line);
    
    // Lecture des valeurs séparées par des espaces
    iss >> status >> quantity;
}

void LogManager::parse_request(const std::string& line, std::string& request, std::string& target) {
    std::istringstream iss(line);
    
    // Lecture des valeurs séparées par des espaces
    iss >> request >> target;
}

void LogManager::parse_date(std::string& date, std::string& jour, std::string& mois, std::string& annee, std::string& heure, std::string& minute, std::string& seconde) {
    std::istringstream iss(date);
    string decompose_date, decompose_heure;
    int compt = 0;
    while (std::getline(iss, decompose_date, '/')) {
        if (compt == 0) {
            jour = decompose_date;
        }
        if (compt == 1) {
            mois = decompose_date;
        }
        if (compt == 2) {
            std::istringstream iss2(decompose_date);
            int compt2 = 0;
            while (std::getline(iss2, decompose_heure, ':')) {
                if (compt2 == 0) {
                    annee = decompose_heure;
                }
                if (compt2 == 1) {
                    heure = decompose_heure;
                }
                if (compt2 == 2) {
                    minute = decompose_heure;
                }
                if (compt2 == 3) {
                    std::istringstream iss3(decompose_heure);
                    iss3 >> seconde;
                }
                compt2++;
            }
        }
        compt++;
    }
}