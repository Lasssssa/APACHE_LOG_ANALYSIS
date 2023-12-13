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

void Log::SetIp(string ipParam)
// Algorithme :
//
{
    ip = ipParam;
} //----- Fin de SetIp

void Log::SetUserLogName(string userLogNameParam)
// Algorithme :
//
{
    userLogName = userLogNameParam;
} //----- Fin de SetUserLogName

void Log::SetAuthenticatedUser(string authenticatedUserParam)
// Algorithme :
//
{
    authenticatedUser = authenticatedUserParam;
} //----- Fin de SetAuthenticatedUser

void Log::SetHour(string hourParam)
// Algorithme :
//
{
    hour = hourParam;
} //----- Fin de SetHour

void Log::SetRequest(string requestParam)
// Algorithme :
//
{
    request = requestParam;
} //----- Fin de SetRequest

void Log::SetTarget(string targetParam)
// Algorithme :
//
{
    target = targetParam;
} //----- Fin de SetTarget

void Log::SetStatus(string statusParam)
// Algorithme :
//
{
    status = statusParam;
} //----- Fin de SetStatus

void Log::SetDataTransferred(string dataTransferredParam)
// Algorithme :
//
{
    dataTransferred = dataTransferredParam;
} //----- Fin de SetDataTransferred

void Log::SetReferer(string refererParam)
// Algorithme :
//
{
    referer = refererParam;
} //----- Fin de SetReferer

void Log::SetUserAgent(string userAgentParam)
// Algorithme :
//
{
    userAgent = userAgentParam;
} //----- Fin de SetUserAgent

string Log::GetIp()
// Algorithme :
//
{
    return ip;
} //----- Fin de GetIp

string Log::GetUserLogName()
// Algorithme :
//
{
    return userLogName;
} //----- Fin de GetUserLogName

string Log::GetAuthenticatedUser()
// Algorithme :
//
{
    return authenticatedUser;
} //----- Fin de GetAuthenticatedUser

string Log::GetHour()
// Algorithme :
//
{
    return hour;
} //----- Fin de GetHour

string Log::GetRequest()
// Algorithme :
//
{
    return request;
} //----- Fin de GetRequest

string Log::GetTarget()
// Algorithme :
//
{
    return target;
} //----- Fin de GetTarget

string Log::GetStatus()
// Algorithme :
//
{
    return status;
} //----- Fin de GetStatus

string Log::GetDataTransferred()
// Algorithme :
//
{
    return dataTransferred;
} //----- Fin de GetDataTransferred

string Log::GetReferer()
// Algorithme :
//
{
    return referer;
} //----- Fin de GetReferer

string Log::GetUserAgent()
// Algorithme :
//
{
    return userAgent;
} //----- Fin de GetUserAgent

void Log::print()
// Algorithme :
//
{
    string test;
    cout << "ip : " << ip << endl;
    cout << "userLogName : " << userLogName << endl;
    cout << "authenticatedUser : " << authenticatedUser << endl;
    cout << "hour : " << hour << endl;
    cout << "request : " << request << endl;
    cout << "target : " << target << endl;
    cout << "status : " << status << endl;
    cout << "dataTransferred : " << dataTransferred << endl;
    cout << "referer : " << referer << endl;
    cout << "userAgent : " << userAgent << endl;
    cout << "------------------------" << endl;
} //----- Fin de print

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées