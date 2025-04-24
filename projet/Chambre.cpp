#include "Chambre.h"
#include <iostream>
using namespace std;

Chambre::Chambre(int idVal,int floor) {
    id=idVal;
    floorNumber=floor;
}

friend ostream& operator <<(ostream& os , const Chambre& chambre);{
    os<<" "<<chambre.id;
    os<<" "<<chambre.floorNumber;
}

friend ostream& operator <<(ostream& os , const Chambre* chambre);{
    os<<" "<<chambre->id;
    os<<" "<<chambre->floorNumber;
}

 istream& operator >>(istream& is , const Chambre& chambre);{
    cout<<"  ";
    is>>chambre.id;
    cout<<" ";
    is>>chambre.floorNumber;
}

friend istream& operator >>(istream& is , const Chambre* chambre);{
    cout<<" ";
    is>>chambre->id;
    cout<<" ";
    is>>chambre->floorNumber;
}

Chambre& Chambre::operator=(const Chambre& ch) {
    if (this != &ch) {
        this->id = ch.id;
        this->nom = ch.nom;
    }
    return *this;
}
