//----------------Interface de la classe <LogManager> (fichier LogManager.h)----------------//

#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <fstream>
#include "Stats.h"

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

    void FillLog(Stats & stats);
    // Mode d'emploi :
    // Contrat :

//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur

    LogManager();

    LogManager(const char* file);
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~LogManager();
    // Mode d'emploi :
    // Contrat :

    


//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées

    void FormatLog (  );


//-------------------------------------------------------------Attributs protégés
    ifstream LogFile;

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H
