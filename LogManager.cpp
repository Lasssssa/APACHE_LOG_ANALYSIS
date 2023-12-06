//-------------------Réalisation de la classe <LogManager> (fichier LogManager.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "LogManager.h"
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées