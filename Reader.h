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

//------------------------------------------------------------------ PRIVE
protected:
//------------------------------------------------------------------Méthodes protégées

    inline void parse_ip_dash_date(const std::string& line, std::string& ip, std::string& firstDash, std::string& secondDash, std::string& inBrackets);

    inline void parse_request(const std::string& line, std::string& request, std::string& target);

    inline void parse_status_quantity(const std::string& line, std::string& status, std::string& quantity);

    inline void parse_date(std::string& date, std::string& jour, std::string& mois, std::string& annee, std::string& heure, std::string& minute, std::string& seconde);

//------------------------------------------------------------------Attributs protégés
    string server;

};

//-------------------------------- Autres définitions dépendantes de <Classe>


#endif // !defined CLASSE_H