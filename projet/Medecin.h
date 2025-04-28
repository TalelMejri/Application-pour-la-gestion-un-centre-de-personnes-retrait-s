#ifndef MEDECIN_H_INCLUDED
#define MEDECIN_H_INCLUDED


#include "Category.h"
#include "Infirmier.h"
#include "stack"
#include "Resident.h"

using namespace std;

class Medecin : virtual public Personnel {
protected:
    string specialite;
    vector<Infirmier*> infirmiersAssignes;
    vector<Category> categories;
    stack<string> reclamations;
public:
    Medecin();
    Medecin(int, string, string, string, string, string, string, DatePerso, string,double, string);
  ~Medecin();
    vector<Infirmier*>  getinfirmiersAssignes(){return infirmiersAssignes;}
    friend ostream& operator <<(ostream&, const Medecin&);
    void loadReclamations();
    void AfficherReclamations();
    friend istream& operator >>(istream&, Medecin&);
    friend ostream& operator <<(ostream&, const Medecin*);
    friend istream& operator >>(istream&, Medecin*);
    Medecin& operator=(const Medecin&);
    Medecin(const Medecin&);
    void ecrirerMedecinDansFichier();
    void afficherPersonne() ;
    void modifier() ;
    void sauvegarderDossierMedical( Resident resident);
    void LireInfirmierFromFichier();
    void assignerInfirmier(Infirmier* inf);
    void afficherInfirmiersAssignes() const;
    void modifierInfirmierAssignes();
    void supprimerInfirmierAssignes();
    void ajouterCategory(Category);
    void ModifierCategory(int);
    void SupprimerCategory(int);
    void afficherCategories();
    void sauvegarderInfDansFichier();
    void ajouterDossierMedicalResident(vector<Resident>);
    string getSpecialite() const { return specialite; }
    vector<Category> getCategories() { return categories; }

    void setSpecialite(string specialiteVal) { specialite = specialiteVal; }
};

#endif // MEDECIN_H_INCLUDED
