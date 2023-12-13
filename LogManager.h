//----------------Interface de la classe <LogManager> (fichier LogManager.h)----------------//

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <fstream>
#include "Stats.h"

using namespace std;

//-------------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------//
// Rôle de la classe <LogMananger>
// Description :
//------------------------------------------------------------------------//

class LogManager : public ifstream 
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques

    void FillLog(Stats & stats, bool excludeFile = false, bool heurebool = false, string heure = "");
    // Mode d'emploi :
    // Contrat :

//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur

    LogManager();

    LogManager(const char* file);
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~LogManager();
    // Mode d'emploi :
    // Contrat :

    


//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées

    inline void parse_ip_dash_date(const std::string& line, std::string& ip, std::string& firstDash, std::string& secondDash, std::string& inBrackets);

    inline void parse_request(const std::string& line, std::string& request, std::string& target);
    
    inline void parse_status_quantity(const std::string& line, std::string& status, std::string& quantity);

    inline void parse_date(std::string& date, std::string& jour, std::string& mois, std::string& annee, std::string& heure, std::string& minute, std::string& seconde);

//------------------------------------------------

//-------------------------------------------------------------Attributs protégés
    ifstream LogFile;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H
