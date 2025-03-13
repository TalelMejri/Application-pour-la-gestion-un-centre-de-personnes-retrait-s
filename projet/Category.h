#ifndef CATEGORY_H_INCLUDED
#define CATEGORY_H_INCLUDED

#include <iostream>
#include <vector>
#include "Medicament.h"

using namespace std;

class Category {
private:
    int id;
    string nom;
    string description;
    vector<Medicament> medicaments;

public:
    Category();
    Category(int, string, string);
   // ~Category();

    void ajouterMedicament(Medicament);
    void afficherCategory();

    int getId() { return id; }
    string getNom() { return nom; }
    string getDescription() { return description; }
    vector<Medicament> getMedicaments() { return medicaments; }

    void setId(int idVal) { id = idVal; }
    void setNom(string nomVal) { nom = nomVal; }
    void setDescription(string descVal) { description = descVal; }
};

#endif // CATEGORY_H_INCLUDED
