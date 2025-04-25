#include "ChambreMultiple.h"
#include <iostream>
using namespace std;

ChambreMultiple::ChambreMultiple()
    : ChambrePatient(), ChambrePersonnel(), isOccupiedByPatient(false) {}

ChambreMultiple::ChambreMultiple(int id, int floor, bool isVisited, bool estEquipee, bool occupied)
    : Chambre(id, floor), ChambrePatient(id, floor, isVisited), ChambrePersonnel(id, floor, estEquipee),
      isOccupiedByPatient(occupied) {}

ChambreMultiple::ChambreMultiple(const ChambreMultiple& other)
    : Chambre(other), ChambrePatient(other), ChambrePersonnel(other),
      isOccupiedByPatient(other.isOccupiedByPatient) {}

ChambreMultiple::~ChambreMultiple() {}

ChambreMultiple& ChambreMultiple::operator=(const ChambreMultiple& other) {
    if (this != &other) {
        Chambre::operator=(other);
        ChambrePatient::operator=(other);
        ChambrePersonnel::operator=(other);
        isOccupiedByPatient = other.isOccupiedByPatient;
    }
    return *this;
}

ostream& operator<<(ostream& out, const ChambreMultiple& ch) {
    out << static_cast<const Chambre&>(ch);
    out << ", Visited: " << (ch.getIsVisited() ? "Yes" : "No");
    out << ", Equipped: " << (ch.getEquiped() ? "Yes" : "No");
    out << ", Occupied by patient: " << (ch.isOccupiedByPatient ? "Yes" : "No");
    return out;
}

istream& operator>>(istream& in, ChambreMultiple& ch) {
    int visited, equipped, occupied;
    in >> static_cast<Chambre&>(ch);
    cout << "Is visited (0 or 1)? ";
    in >> visited;
    cout << "Is equipped (0 or 1)? ";
    in >> equipped;
    cout << "Is occupied by patient (0 or 1)? ";
    in >> occupied;
    ch.toggleIsVisited();
    if (equipped) ch.toggleEquiped();
    ch.isOccupiedByPatient = occupied;
    return in;
}

ostream& operator<<(ostream& out, const ChambreMultiple* ch) {
    if (ch) out << *ch;
    return out;
}

istream& operator>>(istream& in, ChambreMultiple* ch) {
    if (ch) in >> *ch;
    return in;
}

void ChambreMultiple::occuperChambre() {
    isOccupiedByPatient = true;
}

void ChambreMultiple::libererChambre() {
    isOccupiedByPatient = false;
}

void ChambreMultiple::afficherChambre() const {
    cout << "Chambre Multiple - ";
    afficherChambre();
    cout << ", Visited: " << (getIsVisited() ? "Yes" : "No");
    cout << ", Equipped: " << (getEquiped() ? "Yes" : "No");
    cout << ", Occupied by patient: " << (isOccupiedByPatient ? "Yes" : "No") << endl;
}
