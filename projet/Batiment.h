#ifndef BATIMENT_H_INCLUDED
#define BATIMENT_H_INCLUDED
#include <map>
#include <list>
#include <vector>
#include "Personne.h"
#include "Etage.h"

class Batiment {
private:
    string nom;
    string adresse;
    map<string, list<Etage*>> etages;
    vector<Personne*> personnes;

public:
    Batiment();
    Batiment(string, string);
    ~Batiment();

    friend ostream& operator <<(ostream&, const Batiment&);
    friend istream& operator >>(istream&, Batiment&);
    friend ostream& operator <<(ostream&, const Batiment*);
    friend istream& operator >>(istream&, Batiment*);

    Batiment& operator=(const Batiment&);
    Batiment(const Batiment&);

    void ajouterEtage(const string& type, Etage* etage);
    void ajouterPersonne(Personne* personne);
    void afficherBatiment();
    void afficherEtage();
    void supprimerEtage(const string& type, int id);
    void supprimerPersonne(int id);
    void enregistrerEtages();
    void sauvegarderEtageDansFichier();
    void chargerEtages() ;
    string getNom() { return nom; }
    string getAdresse() { return adresse; }
    map<string, list<Etage*>> getEtages() { return etages; }
    vector<Personne*> getPersonnes() { return personnes; }
    void setNom(string nomVal) { nom = nomVal; }
    void setAdresse(string adresseVal) { adresse = adresseVal; }
};

#endif // BATIMENT_H_INCLUDED
