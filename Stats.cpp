//-------------------Réalisation de la classe <Stats> (fichier Stats.cpp)-------------------//

//---------------------------------------------------------------- INCLUDE
#include "Stats.h"
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

void Stats::AddLog(int log) {
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
    sort(top10.begin(), top10.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    });
    for (int i = 0; i < 10; i++) {
        cout << top10[i].first << " (" << top10[i].second << " hits)" << endl;
    }
}

void Stats::CreateGraph() {
ofstream graphFile;
    graphFile.open("graph.dot");
    graphFile << "digraph {" << endl;
    for (auto it = mapTarget.begin(); it != mapTarget.end(); it++) {
        vector<pair<string, int>> top10;
        for (auto it2 = it->second.mapReferer.begin(); it2 != it->second.mapReferer.end(); it2++) {
            top10.push_back(pair<string, int>(it2->first, it2->second));
        }
        sort(top10.begin(), top10.end(), [](pair<string, int> a, pair<string, int> b) {
            return a.second > b.second;
        });
        for (int i = 0; i < 10; i++) {
            graphFile << "\"" << top10[i].first << "\" -> \"" << it->first << "\" [label=\"" << top10[i].second << "\"];" << endl;
        }
    }
    graphFile << "}" << endl;
    graphFile.close();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées