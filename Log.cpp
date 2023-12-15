//-------------------Réalisation de la classe <Log> (fichier Log.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "Log.h"
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Log::Log (string ipParam, string userLogNameParam, string authenticatedUserParam, string hourParam, string requestParam, string targetParam, string statusParam, string dataTransferredParam, string refererParam, string userAgentParam)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif
    ip = ipParam;
    userLogName = userLogNameParam;
    authenticatedUser = authenticatedUserParam;
    hour = hourParam;
    request = requestParam;
    target = targetParam;
    status = statusParam;
    dataTransferred = dataTransferredParam;
    referer = refererParam;
    userAgent = userAgentParam;
} //----- Fin de Log

Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
}

//----------------------------------------------------- Méthodes publiques

string Log::GetTarget() {
    return target;
}

string Log::GetReferer() {
    return referer;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées