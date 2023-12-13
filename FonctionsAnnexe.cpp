// Description: Fonctions annexes pour le projet

#include "FonctionsAnnexe.h"

std::string ChangeExtensionDotInPng(std::string name)
{
    std::string newName = "";
    for(std::string::size_type i = 0; i < name.size(); i++)
    {
        if(name[i] == '.')
        {
            newName += ".png";
            return newName;
        }
        else
        {
            newName += name[i];
        }
    }
    return newName;
}
