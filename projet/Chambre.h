#ifndef CHAMBRE_H_INCLUDED
#define CHAMBRE_H_INCLUDED

#include <iostream>

class Chambre {
protected:
    int id;
    int floorNumber;

public:
    Chambre();
    Chambre(int, int);
    virtual ~Chambre() {}

    virtual void afficherChambre() = 0;

    int getId() { return id; }
    int getfloorNumber() { return floorNumber; }

    void setId(int idVal) { id = idVal; }
    void setfloorNumber(int floor){floorNumber=floor;}
};

#endif // CHAMBRE_H_INCLUDED
