#ifndef MEDECIN_H_INCLUDED
#define MEDECIN_H_INCLUDED

#include "Personnel.h"
#include "Category.h"
using namespace std;

class Medecin : virtual public Personnel {
protected:
    string specialite;
    vector<Category> categories;

public:
    Medecin();
    Medecin(int, string, string, string, string, string, string, DatePerso, string,double, string);
  ~Medecin();
    friend ostream& operator <<(ostream&, const Medecin&);
    friend istream& operator >>(istream&, Medecin&);
    friend ostream& operator <<(ostream&, const Medecin*);
    friend istream& operator >>(istream&, Medecin*);
    Medecin& operator=(const Medecin&);
    Medecin(const Medecin&);
    void ecrirerMedecinDansFichier();
    void afficherPersonne() ;
    void modifier() ;

    void ajouterCategory(Category);
    void ModifierCategory(int);
    void SupprimerCategory(int);
    void afficherCategories();


    string getSpecialite() { return specialite; }
    vector<Category> getCategories() { return categories; }

    void setSpecialite(string specialiteVal) { specialite = specialiteVal; }
};

#endif // MEDECIN_H_INCLUDED
