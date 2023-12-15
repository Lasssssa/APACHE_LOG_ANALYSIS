//----------------Interface de la classe <Reader> (fichier Reader.h)----------------//

#if !defined READER_H
#define READER_H

//------------------------------------------------------------------- Interfaces utilisées
#include "Log.h"
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------- Types
//-------------------------------------------------------------------//
// Rôle de la classe <Reader>
// Description :
//------------------------------------------------------------------//

class Reader : public ifstream
{
//-----------------------------------------------------------------PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques


//-----------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------------------Constructeurs - Destructeur

    Reader (const string file, string serveur);
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Reader ( );
    // Mode d'emploi :
    // Contrat :

    Log ReadLog();
    // Mode d'emploi : Lit une ligne de log et la parse pour en faire un objet Log
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//------------------------------------------------------------------Méthodes protégées

    void parse_ip_dash_date(const std::string& line, std::string& ip, std::string& firstDash, std::string& secondDash, std::string& inBrackets);
    // Mode d'emploi : Parse une ligne de log pour en extraire l'ip, la date et l'heure
    // Contrat :

    void parse_request(const std::string& line, std::string& request, std::string& target);
    // Mode d'emploi : Parse une ligne de log pour en extraire la requête et la cible
    // Contrat :

    void parse_status_quantity(const std::string& line, std::string& status, std::string& quantity);
    // Mode d'emploi : Parse une ligne de log pour en extraire le status et la quantité
    // Contrat :

    void parse_date(std::string& date, std::string& jour, std::string& mois, std::string& annee, std::string& heure, std::string& minute, std::string& seconde);
    // Mode d'emploi : Parse une date pour en extraire le jour, le mois, l'année, l'heure, la minute et la seconde
    // Contrat :

//------------------------------------------------------------------Attributs protégés
    string server;

};

#endif // !defined CLASSE_H