#ifndef CHAMBRE_H_INCLUDED
#define CHAMBRE_H_INCLUDED

#include <iostream>
using namespace std;

class Chambre {
protected:
    int id;
    int floorNumber;

public:
    Chambre();
    Chambre(int, int);
    virtual ~Chambre() {}
    Chambre(const Chambre&);
    Chambre& operator=(const Chambre&);

    friend ostream& operator<<(ostream&, const Chambre&);
    friend istream& operator>>(istream&, Chambre&);

    virtual void afficherChambre() const = 0;

    int getId() const { return id; }
    int getFloorNumber() const { return floorNumber; }

    void setId(int idVal) { id = idVal; }
    void setFloorNumber(int floor) { floorNumber = floor; }
};

#endif // CHAMBRE_H_INCLUDED
