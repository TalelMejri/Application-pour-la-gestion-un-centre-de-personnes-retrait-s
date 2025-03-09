#ifndef BATIMENT_H_INCLUDED
#define BATIMENT_H_INCLUDED

#include <vector>
#include "Personne.h"
#include "Etage.h"

class Batiment {
private:
    string nom;
    string adresse;
    vector<Etage*> etages;
    vector<Personne*> personnes;

public:
    Batiment();
    Batiment(string, string);
    ~Batiment();

    void ajouterEtage(Etage* etage);
    void ajouterPersonne(Personne* personne);
    void afficherBatiment();
    void supprimerEtage(int id);
    void supprimerPersonne(int id);

    string getNom() { return nom; }
    string getAdresse() { return adresse; }
    vector<Etage*> getEtages() { return etages; }
    vector<Personne*> getPersonnes() { return personnes; }

    void setNom(string nomVal) { nom = nomVal; }
    void setAdresse(string adresseVal) { adresse = adresseVal; }
};

#endif // BATIMENT_H_INCLUDED
