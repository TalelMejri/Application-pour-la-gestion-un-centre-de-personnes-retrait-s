#ifndef INFIRMIER_H_INCLUDED
#define INFIRMIER_H_INCLUDED

#include "Personnel.h"

class Infirmier : public Personnel {
private:
    int experience;

public:
    Infirmier();
    Infirmier(int, string, string, string, string, string, string, DATE, double, int);
    ~Infirmier();

    void afficherPersonne() ;
    void modifier() ;

    int getExperience() { return experience; }
    void setExperience(int exp) { experience = exp; }
};

#endif // INFIRMIER_H_INCLUDED
