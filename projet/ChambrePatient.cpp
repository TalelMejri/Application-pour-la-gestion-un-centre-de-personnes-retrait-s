#include "ChambrePatient.h"

ChambrePatient::ChambrePatient() : Chambre(), IsVisited(false) {}

ChambrePatient::ChambrePatient(int id, int floor, bool visited)
    : Chambre(id, floor), IsVisited(visited) {}

ChambrePatient::~ChambrePatient() {}

ChambrePatient::ChambrePatient(const ChambrePatient& other)
    : Chambre(other), IsVisited(other.IsVisited) {}

ChambrePatient& ChambrePatient::operator=(const ChambrePatient& other) {
    if (this != &other) {
        Chambre::operator=(other);
        IsVisited = other.IsVisited;
    }
    return *this;
}

ostream& operator<<(ostream& out, const ChambrePatient& ChP) {
    out << static_cast<const Chambre&>(ChP);
    out << ", Visited: " << (ChP.IsVisited ? "Yes" : "No");
    return out;
}

istream& operator>>(istream& in, ChambrePatient& ChP) {
    in >> static_cast<Chambre&>(ChP);
    cout << "Is visited (0 or 1)? ";
    in >> ChP.IsVisited;
    return in;
}

void ChambrePatient::afficherChambre() const {
    afficherChambre();
    cout << ", Visited: " << (IsVisited ? "Yes" : "No") << endl;
}
