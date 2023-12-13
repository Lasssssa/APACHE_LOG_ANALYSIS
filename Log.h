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
//-----------------------------------------------------------------Méthodes publiques

    friend class LogManager;
    string GetIp();
    // Mode d'emploi :
    // Contrat :

    string GetUserLogName();
    // Mode d'emploi :
    // Contrat :

    string GetAuthenticatedUser();
    // Mode d'emploi :
    // Contrat :

    string GetHour();
    // Mode d'emploi :
    // Contrat :

    string GetRequest();
    // Mode d'emploi :
    // Contrat :

    string GetTarget();
    // Mode d'emploi :
    // Contrat :

    string GetStatus();
    // Mode d'emploi :
    // Contrat :

    string GetDataTransferred();
    // Mode d'emploi :
    // Contrat :

    string GetReferer();
    // Mode d'emploi :
    // Contrat :

    string GetUserAgent();
    // Mode d'emploi :
    // Contrat :

    void SetIp(string ipParam);
    // Mode d'emploi :
    // Contrat :

    void SetUserLogName(string userLogNameParam);
    // Mode d'emploi :
    // Contrat :

    void SetAuthenticatedUser(string authenticatedUserParam);
    // Mode d'emploi :
    // Contrat :

    void SetHour(string hourParam);
    // Mode d'emploi :
    // Contrat :

    void SetRequest(string requestParam);
    // Mode d'emploi :
    // Contrat :

    void SetTarget(string targetParam);
    // Mode d'emploi :
    // Contrat :

    void SetStatus(string statusParam);
    // Mode d'emploi :
    // Contrat :

    void SetDataTransferred(string dataTransferredParam);
    // Mode d'emploi :
    // Contrat :

    void SetReferer(string refererParam);
    // Mode d'emploi :
    // Contrat :

    void SetUserAgent(string userAgentParam);
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