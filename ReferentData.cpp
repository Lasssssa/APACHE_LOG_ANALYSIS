//-------------------Réalisation de la classe <ReferentData> (fichier ReferentData.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "ReferentData.h"
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ReferentData::ReferentData ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ReferentData>" << endl;
#endif
}

ReferentData::~ReferentData ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ReferentData>" << endl;
#endif
}

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées