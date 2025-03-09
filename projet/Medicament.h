#ifndef MEDICAMENT_H_INCLUDED
#define MEDICAMENT_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct date {
    int jour;
    int mois;
    int annee;
} DATE;

class Medicament {
private:
    int id;
    string nom;
    int quantite;
    DATE dateLimit;

public:
    Medicament();
    Medicament(int, string, int, DATE);
    ~Medicament();

    void afficherMedicament();
    bool estPerime(DATE dateActuelle);

    int getId() { return id; }
    string getNom() { return nom; }
    int getQuantite() { return quantite; }
    DATE getDateLimit() { return dateLimit; }

    void setId(int idVal) { id = idVal; }
    void setNom(string nomVal) { nom = nomVal; }
    void setQuantite(int qteVal) { quantite = qteVal; }
    void setDateLimit(DATE dateVal) { dateLimit = dateVal; }
};

#endif // MEDICAMENT_H_INCLUDED
