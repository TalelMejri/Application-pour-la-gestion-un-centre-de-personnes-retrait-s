#ifndef RESPONSABLE_H_INCLUDED
#define RESPONSABLE_H_INCLUDED

#include "Personne.h"
#include "Personnel.h"
#include <vector>

class Responsable : public Personne {
private:
    vector<Personnel*> employes;

public:
    Responsable();
    Responsable(int, string, string, string, string, string, string, DATE);
    ~Responsable();

    void ajouterEmploye(Personnel* employe);
    void supprimerEmploye(int id);
    void afficherEmployes();
    void modifier(int id);
    int rechercherEmploye(int);

};

#endif // RESPONSABLE_H_INCLUDED
