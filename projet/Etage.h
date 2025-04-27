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
    Etage& operator=(const Etage&);
    Etage(const Etage&);
    friend ostream& operator <<(ostream&, const Etage&);
    friend istream& operator >>(istream&, Etage&);
    friend ostream& operator <<(ostream&, const Etage*);
    friend istream& operator >>(istream&, Etage*);

    void ajouterChambre(Chambre* chambre);
    void ModifierChambre(int id);
    void SupprimerChambre(int id);
    void AfficherChambre();
    virtual void afficherEtage() = 0;
    Etage* chargerEtageDepuisFichier(ifstream& );

    int getId() { return id; }
    string getType() { return type; }
    vector<Chambre*> getChambres() { return chambres; }

    void setId(int idVal) { id = idVal; }
    void setType(string typeVal) { type = typeVal; }
};

#endif // ETAGE_H_INCLUDED
