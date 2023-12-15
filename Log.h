//----------------Interface de la classe <Log> (fichier Log.h)----------------//

#if !defined LOG_H
#define LOG_H

//-------------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------//
// Rôle de la classe <Log>
// Description :
//------------------------------------------------------------------------//

class Log
{
//----------------------------------------------------------------- PUBLIC
public:
    friend class LogManager;
//-----------------------------------------------------------------Méthodes publiques

    string GetTarget();
    // Mode d'emploi :
    // Contrat :

    string GetReferer();
    // Mode d'emploi :
    // Contrat :

//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur

    Log(string ipParam, string userLogNameParam, string authenticatedUserParam, string hourParam, string requestParam, string targetParam, string statusParam, string dataTransferredParam, string refererParam, string userAgentParam);
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Log ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées

//-------------------------------------------------------------Attributs protégés
    string ip;
    string userLogName;
    string authenticatedUser;
    string hour;
    string request;
    string target;
    string status;
    string dataTransferred;
    string referer;
    string userAgent;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H