//-------------------Réalisation de la classe <Stats> (fichier Stats.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "Stats.h"
#include <algorithm>
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

void Stats::AddLog(Log log) {
    string target = log.GetTarget();
    string referer = log.GetReferer();
    if (mapTarget.find(target) == mapTarget.end()) {
        ReferentData referentData;
        referentData.nbHitsTotal = 1;
        referentData.mapReferer.insert(pair<string, int>(referer, 1));
        mapTarget.insert(pair<string, ReferentData>(target, referentData));
    }else {
        mapTarget[target].nbHitsTotal++;
        if (mapTarget[target].mapReferer.find(referer) == mapTarget[target].mapReferer.end()) {
            mapTarget[target].mapReferer.insert(pair<string, int>(referer, 1));
        } else {
            mapTarget[target].mapReferer[referer]++;
        }
    }
}

void Stats::PrintTop10() {
    vector<pair<string, int>> top10;
    for (auto it = mapTarget.begin(); it != mapTarget.end(); it++) {
        top10.push_back(pair<string, int>(it->first, it->second.nbHitsTotal));
    }

    // Tri du vecteur top10 en fonction du nombre de hits (second élément de la paire)
    std::sort(top10.begin(), top10.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second > b.second; // Trie par ordre décroissant du nombre de hits
    });

    // Affichage des 10 premiers éléments triés
    int limit = std::min(10, static_cast<int>(top10.size()));
    for (int i = 0; i < limit; i++) {
        cout << top10[i].first << " (" << top10[i].second << " hits)" << endl;
    }
}


//Exporte le graph au format .dot avec tout les trajets
void Stats::CreateGraph() {
ofstream graphFile;
    graphFile.open("graph.dot");
    graphFile << "digraph {" << endl;
    for (auto it = mapTarget.begin(); it != mapTarget.end(); it++) {
        for (auto it2 = it->second.mapReferer.begin(); it2 != it->second.mapReferer.end(); it2++) {
            graphFile << "\"" << it2->first << "\" -> \"" << it->first << "\" [label=\"" << it2->second << "\"];" << endl;
        }
    }
    graphFile << "}" << endl;
    graphFile.close();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées