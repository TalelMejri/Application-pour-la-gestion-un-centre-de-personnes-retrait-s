#ifndef MEDECININFIRMIER_H_INCLUDED
#define MEDECININFIRMIER_H_INCLUDED

#include "Medecin.h"
#include "Infirmier.h"

class MedecinInfirmier : public Medecin, public Infirmier {
    int nbrOperation;
    string grade;
public:
    MedecinInfirmier();
    MedecinInfirmier(int, string, string, string, string, string, string, DatePerso,string, double, string, int, string);
    ~MedecinInfirmier();
    MedecinInfirmier(const MedecinInfirmier&);

    MedecinInfirmier& operator=(const MedecinInfirmier&);
    int getExperience() const;
    bool operator<(const MedecinInfirmier&);
    void ecrirerMedecinInfDansFichier();

    friend ostream& operator<<(ostream&, const MedecinInfirmier&);
    friend istream& operator>>(istream&, MedecinInfirmier&);
    friend ostream& operator<<(ostream&, const MedecinInfirmier*);
    friend istream& operator>>(istream&, MedecinInfirmier*);

    void afficherPersonne();
    void modifier();

    string getGrade() const { return grade; }
    void setGrade(const string& g) { grade = g; }

    int GetNbrOperation() const { return nbrOperation; }
    void SetNbrOperation(const int& g) { nbrOperation = g; }
};


#endif // MEDECININFIRMIER_H_INCLUDED
