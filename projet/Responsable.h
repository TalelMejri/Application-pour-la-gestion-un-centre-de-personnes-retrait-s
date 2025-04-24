#ifndef RESPONSABLE_H_INCLUDED
#define RESPONSABLE_H_INCLUDED

#include "Resident.h"
#include "Personnel.h"
#include "Batiment.h"
#include <vector>

class Responsable : public Personne {
private:
    vector<Personnel*> employes;
    vector<Resident> residents;
    Batiment batiment;

public:
    Responsable();
    Responsable(int, string, string, string, string, string, string, DatePerso);
    ~Responsable();

    friend ostream& operator<<(ostream&, const Responsable&);
    friend istream& operator>>(istream&, Responsable&);
    friend ostream& operator<<(ostream&, const Responsable*);
    friend istream& operator>>(istream&, Responsable*);
    Responsable(const Responsable &);
    Responsable& operator=(const Responsable&);
    void afficherPersonne();
    void modifier();
    void ajouterEmploye(Personnel* employe);
    void supprimerEmploye(int id);
    void afficherEmployes();
    void modifier(int id);
    int rechercherEmploye(int);
    void LireResidentFromFichier();

    void SupprimerResident(int id);
    void AfficherResident();
    void ModifierResident(int id);
    int RechercherResident(int);

};

#endif // RESPONSABLE_H_INCLUDED
