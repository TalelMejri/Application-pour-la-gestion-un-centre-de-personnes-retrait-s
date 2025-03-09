#ifndef ETAGE_H_INCLUDED
#define ETAGE_H_INCLUDED

#include <vector>
#include "Chambre.h"

class Etage {
protected:
    int id;
    string type;
    vector<Chambre*> chambres;

public:
    Etage();
    Etage(int, string);
    virtual ~Etage();

    void ajouterChambre(Chambre* chambre);
    virtual void afficherEtage() = 0;

    int getId() { return id; }
    string getType() { return type; }
    vector<Chambre*> getChambres() { return chambres; }

    void setId(int idVal) { id = idVal; }
    void setType(string typeVal) { type = typeVal; }
};

#endif // ETAGE_H_INCLUDED
