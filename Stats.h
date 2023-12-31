//----------------Interface de la classe <Stats> (fichier Stats.h)----------------//

#if !defined STATS_H
#define STATS_H

//-------------------------------------------------------- Interfaces utilisées
using namespace std;
#include <unordered_map>
#include <string>
#include "Log.h"
#include "ReferentData.h"
#include <iostream>
#include <fstream>
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------//
// Rôle de la classe <Stats>
// Description :
//------------------------------------------------------------------------//

class Stats
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques

    void PrintTop10();

    void CreateGraph(string name);


//---------------------------------------------------------------Surcharge d'opérateurs
    Stats& operator<<(Log log);

//-----------------------------------------------------Constructeurs - Destructeur
    Stats ( );
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Stats ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées
    unordered_map<string, ReferentData> mapTarget;

//-------------------------------------------------------------Attributs protégés




};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H