//----------------Interface de la classe <Stats> (fichier Stats.h)----------------//

#if !defined STATS_H
#define STATS_H

//-------------------------------------------------------- Interfaces utilisées
using namespace std;
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

    void AddLog(Log log);

    void PrintTop10();

    void CreateGraph();


//---------------------------------------------------------------Surcharge d'opérateurs

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