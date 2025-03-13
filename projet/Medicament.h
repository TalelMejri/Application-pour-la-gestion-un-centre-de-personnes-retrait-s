#ifndef MEDICAMENT_H_INCLUDED
#define MEDICAMENT_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct date_med {
    int jour;
    int mois;
    int annee;
} DATE_Med;

class Medicament {
private:
    int id;
    string nom;
    int quantite;
    DATE_Med dateLimit;

public:
    Medicament();
    Medicament(int, string, int, DATE_Med);
    ~Medicament();

    void afficherMedicament();
    bool estPerime(DATE_Med dateActuelle);

    int getId() { return id; }
    string getNom() { return nom; }
    int getQuantite() { return quantite; }
    DATE_Med getDateLimit() { return dateLimit; }

    void setId(int idVal) { id = idVal; }
    void setNom(string nomVal) { nom = nomVal; }
    void setQuantite(int qteVal) { quantite = qteVal; }
    void setDateLimit(DATE_Med dateVal) { dateLimit = dateVal; }
};

#endif // MEDICAMENT_H_INCLUDED
