//----------------Interface de la classe <LogManager> (fichier LogManager.h)----------------//

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <fstream>
#include "Stats.h"
#include "Reader.h"

using namespace std;

//-------------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------//
// Rôle de la classe <LogMananger>
// Description :
//------------------------------------------------------------------------//

class LogManager : public ifstream 
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques

    void TreatLog();
    // Mode d'emploi :
    // Contrat :

    Stats GetStats() { return stats; }
//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur

    LogManager(const string file, string serveur, bool exportDot = false, bool HourBool = false, int Hour = 0, bool excludeFile = false);

    virtual ~LogManager();
    // Mode d'emploi :
    // Contrat :

    


//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées

//------------------------------------------------

//-------------------------------------------------------------Attributs protégés
    Reader reader;
    Stats stats;
    bool exportDot;
    bool HourBool;
    int Hour;
    bool excludeFile;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H
