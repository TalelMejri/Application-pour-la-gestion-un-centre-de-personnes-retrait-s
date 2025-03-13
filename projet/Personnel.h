#ifndef PERSONNEL_H_INCLUDED
#define PERSONNEL_H_INCLUDED

#include "Personne.h"

class Personnel : public Personne {
protected:
    string poste;
    double salaire;

public:
    Personnel();
    Personnel(int, string, string, string, string, string, string, DATE, string, double);
    virtual ~Personnel();

    virtual void afficherPersonne() ;
    virtual void modifier() ;

    string getPoste() { return poste; }
    double getSalaire() { return salaire; }

    void setPoste(string p) { poste = p; }
    void setSalaire(double s) { salaire = s; }
};

#endif // PERSONNEL_H_INCLUDED
