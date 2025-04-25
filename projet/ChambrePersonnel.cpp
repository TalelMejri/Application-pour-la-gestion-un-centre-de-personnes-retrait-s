#include "ChambrePersonnel.h"
#include <iostream>
using namespace std;

ChambrePersonnel::ChambrePersonnel() : Chambre(), estequipee(false) {}

ChambrePersonnel::ChambrePersonnel(int id, int floor, bool estEquipee)
    : Chambre(id, floor), estequipee(estEquipee) {}

ChambrePersonnel::~ChambrePersonnel() {}

ChambrePersonnel::ChambrePersonnel(const ChambrePersonnel& other)
    : Chambre(other), estequipee(other.estequipee) {}

ChambrePersonnel& ChambrePersonnel::operator=(const ChambrePersonnel& other) {
    if (this != &other) {
        Chambre::operator=(other);
        estequipee = other.estequipee;
    }
    return *this;
}

ostream& operator<<(ostream& out, const ChambrePersonnel& ch) {
    out << static_cast<const Chambre&>(ch);
    out << ", Equipped: " << (ch.estequipee ? "Yes" : "No");
    return out;
}

istream& operator>>(istream& in, ChambrePersonnel& ch) {
    in >> static_cast<Chambre&>(ch);
    cout << "Is it equipped (0 or 1)? ";
    in >> ch.estequipee;
    return in;
}

ostream& operator<<(ostream& out, const ChambrePersonnel* ch) {
    if (ch) {
        out << *ch;
    }
    return out;
}

istream& operator>>(istream& in, ChambrePersonnel* ch) {
    if (ch) {
        in >> *ch;
    }
    return in;
}

void ChambrePersonnel::afficherChambre() const {
    cout << "Chambre Personnel - ";
    afficherChambre();
    cout << ", Equipped: " << (estequipee ? "Yes" : "No") << endl;
}
