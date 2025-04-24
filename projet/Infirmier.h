#ifndef INFIRMIER_H_INCLUDED
#define INFIRMIER_H_INCLUDED
#include "Personnel.h"
#include <map >
#include <vector >
using namespace std;
class Infirmier :virtual  public Personnel {
protected:
    int experience;
    map <string , pair <string , string > > horaires;
    vector <string > jours;
    string chambre;

public:
    Infirmier();
    Infirmier(int, string, string, string, string, string, string, DatePerso,string, double, int);
  ~Infirmier();
    void saisirHoraires();
    void afficherHoraires();
    friend ostream& operator <<(ostream&, const Infirmier&);
    friend istream& operator >>(istream&, Infirmier&);
    friend ostream& operator <<(ostream&, const Infirmier*);
    friend istream& operator >>(istream&, Infirmier*);
    Infirmier& operator=(const Infirmier&);
    Infirmier(const Infirmier&);
    void ecrirerInfirmierDansFichier();

    void afficherPersonne() ;
    void modifier() ;

    int getExperience() const { return experience; }
    void setExperience(int exp) { experience = exp; }
};

#endif // INFIRMIER_H_INCLUDED
