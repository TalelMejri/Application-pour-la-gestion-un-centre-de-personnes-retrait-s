#include "Chambre.h"

Chambre::Chambre() : id(0), floorNumber(0) {}

Chambre::Chambre(int idVal, int floor) : id(idVal), floorNumber(floor) {}

Chambre::Chambre(const Chambre& other) {
    id = other.id;
    floorNumber = other.floorNumber;
}

Chambre& Chambre::operator=(const Chambre& ch) {
    if (this != &ch) {
        id = ch.id;
        floorNumber = ch.floorNumber;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Chambre& chambre) {
    os << "ID: " << chambre.id << ", Floor: " << chambre.floorNumber;
    return os;
}

istream& operator>>(istream& is, Chambre& chambre) {
    cout << "Enter ID: ";
    is >> chambre.id;
    cout << "Enter floor number: ";
    is >> chambre.floorNumber;
    return is;
}
