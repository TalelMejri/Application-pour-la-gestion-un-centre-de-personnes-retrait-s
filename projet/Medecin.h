#ifndef MEDECIN_H_INCLUDED
#define MEDECIN_H_INCLUDED

#include "Personne.h"
#include "Category.h"
#include <vector>

class Medecin : public Personne {
private:
    double salaire;
    string specialite;
    vector<Category> categories;

public:
    Medecin();
    Medecin(int, string, string, string, string, string, string, DATE, double, string);
    ~Medecin();

    void afficherPersonne() ;
    void modifier() ;

    void ajouterCategory(Category);
    void afficherCategories();

    double getSalaire() { return salaire; }
    string getSpecialite() { return specialite; }
    vector<Category> getCategories() { return categories; }

    void setSalaire(double salaireVal) { salaire = salaireVal; }
    void setSpecialite(string specialiteVal) { specialite = specialiteVal; }
};

#endif // MEDECIN_H_INCLUDED
