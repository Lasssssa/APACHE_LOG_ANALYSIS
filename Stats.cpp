//-------------------Réalisation de la classe <Stats> (fichier Stats.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "Stats.h"
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Stats::Stats ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats>" << endl;
#endif
    
} //----- Fin de Stats

Stats::~Stats ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stats>" << endl;
#endif
}

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées