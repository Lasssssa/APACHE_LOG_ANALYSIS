//----------------Interface de la classe <ReferentData> (fichier ReferentData.h)----------------//

#if !defined REFERENTDATA_H
#define REFERENTDATA_H

//------------------------------------------------------------------- Interfaces utilisées
#include "Log.h"
#include <unordered_map>
//------------------------------------------------------------------- Constantes

//------------------------------------------------------------------- Types
//-------------------------------------------------------------------//
// Rôle de la classe <LogMananger>
// Description :
//------------------------------------------------------------------//

class ReferentData
{
//-----------------------------------------------------------------PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques


//-----------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------------------Constructeurs - Destructeur
    ReferentData ( );
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~ReferentData ( );
    // Mode d'emploi :
    // Contrat :

    friend class Stats;

//------------------------------------------------------------------ PRIVE
protected:
//------------------------------------------------------------------Méthodes protégées

//------------------------------------------------------------------Attributs protégés
    int nbHitsTotal;
    unordered_map<string, int> mapReferer;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H