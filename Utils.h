//----------------Interface de la classe <Utils> (fichier Utils.h)----------------//

#if !defined UTILS_H
#define UTILS_H

//-------------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------//
// Rôle de la classe <Utils>
// Description :
//------------------------------------------------------------------------//

#include <string>
#include <vector>

class Utils
{
//----------------------------------------------------------------- PUBLIC
public:
//-----------------------------------------------------------------Méthodes publiques

    std::string ChangeExtensionDotInPng(std::string name);
    //Mode d'emploi :
    //Fonction qui permet de changer l'extension d'un fichier .dot en .png
    //Contrat :
    //Aucun

    std::string getServeurFromConfigFile(std::string configFile);
    //Mode d'emploi :
    //Fonction qui permet de récupérer le nom du serveur dans le fichier de configuration
    //Contrat :
    //Aucun

    std::vector<std::string> getIgnoredFileFromConfigFile(std::string configFile);
    //Mode d'emploi :
    //Fonction qui permet de récupérer les fichiers à ignorer dans le fichier de configuration
    //Contrat :
    //Aucun

//---------------------------------------------------------------Surcharge d'opérateurs

//-----------------------------------------------------Constructeurs - Destructeur
    Utils ( );
    // Mode d'emploi (Constructeur par défaut) :
    // Contrat :

    virtual ~Utils ( );
    // Mode d'emploi :
    // Contrat :

//------------------------------------------------------------------ PRIVE
protected:
//-----------------------------------------------------------Méthodes protégées

//-------------------------------------------------------------Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Classe>



#endif // !defined CLASSE_H