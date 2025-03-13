#ifndef CHAMBRE_H_INCLUDED
#define CHAMBRE_H_INCLUDED

#include <iostream>

class Chambre {
protected:
    int id;
    string type;

public:
    Chambre();
    Chambre(int, string);
    virtual ~Chambre() {}

    virtual void afficherChambre() = 0;

    int getId() { return id; }
    string getType() { return type; }

    void setId(int idVal) { id = idVal; }
    void setType(string typeVal) { type = typeVal; }
};

#endif // CHAMBRE_H_INCLUDED
