//----------------Fichier .h de Fonction Annexe (fichier FonctionsAnnexe.h)----------------//

#ifndef FONCTIONS_ANNEXE_H
#define FONCTIONS_ANNEXE_H

#include <string>

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
#endif // !defined CLASSE_H
