#include "Etage.h"
#include "ChambrePatient.h"
#include "ChambrePersonnel.h"
#include "ChambreMultiple.h"

#include <iostream>
using namespace std;
int Etage::idCounter = 0;

Etage::Etage() : id(0), type("") {id = ++idCounter;}

Etage::Etage(int idVal, string typeVal) : id(idVal), type(typeVal) {
    id = idVal != -1 ? idVal : ++idCounter;
}

Etage::~Etage() {
    for (size_t i = 0; i < chambres.size(); ++i) {
        delete chambres[i];
    }
}

void Etage::ajouterChambre(Chambre* chambre) {
    chambres.push_back(chambre);
}

ostream& operator<<(ostream& os, const Etage& etage) {
    os <<etage.id << " " << etage.type;
    for (auto chambre : etage.chambres) {
        os << "\n  " << *chambre;
    }
    return os;
}

ostream& operator<<(ostream& os, const Etage* etage) {
    if (etage) os << *etage;
    return os;
}

istream& operator>>(istream& is, Etage& etage) {
    cout << " ";
    is >> etage.id;
    cout << " ";
    is >> etage.type;
    bool isConsole = (&is == &cin);
    if (isConsole) {
        int n;
   cout << "How many rooms to enter? ";
   is >> n;
   for (int i = 0; i < n; ++i) {
    int choix;
    cout << "Enter room type (1: Patient, 2: Personnel, 3: Multiple): ";
    is >> choix;
    Chambre* ch = nullptr;
    switch (choix) {
        case 1:
            ch = new ChambrePatient();
            break;
        case 2:
            ch = new ChambrePersonnel();
            break;
        case 3:
            ch = new ChambreMultiple();
            break;
        default:
            cout << "Invalid type. Skipping room.\n";
            continue;
    }
    is >> *ch;
    etage.ajouterChambre(ch);
    }
}

    return is;
}

istream& operator>>(istream& is, Etage* etage) {
    if (etage) is >> *etage;
    return is;
}

Etage::Etage(const Etage& A) {
    id = A.id;
    type = A.type;
    Chambre* p;
    for (unsigned int i = 0; i < A.chambres.size(); i++) {
        if (typeid(*A.chambres[i]) == typeid(ChambrePatient)) {
            p = new ChambrePatient(*dynamic_cast<ChambrePatient*>(A.chambres[i]));
        } else if (typeid(*A.chambres[i]) == typeid(ChambrePersonnel)) {
            p = new ChambrePersonnel(*dynamic_cast<ChambrePersonnel*>(A.chambres[i]));
        }else{
                        p = new ChambreMultiple(*dynamic_cast<ChambreMultiple*>(A.chambres[i]));
        }
        chambres.push_back(p);
    }
}

Etage& Etage::operator=(const Etage& A) {
    if (this != &A) {

        for (unsigned int i = 0; i < chambres.size(); i++) {
            delete chambres[i];
        }
        chambres.clear();

    id = A.id;
    type = A.type;
    Chambre* p;
    for (unsigned int i = 0; i < A.chambres.size(); i++) {
        if (typeid(*A.chambres[i]) == typeid(ChambrePatient)) {
            p = new ChambrePatient(*dynamic_cast<ChambrePatient*>(A.chambres[i]));
        } else if (typeid(*A.chambres[i]) == typeid(ChambrePersonnel)) {
            p = new ChambrePersonnel(*dynamic_cast<ChambrePersonnel*>(A.chambres[i]));
        }else{
                        p = new ChambreMultiple(*dynamic_cast<ChambreMultiple*>(A.chambres[i]));
        }
        chambres.push_back(p);
    }
    }
    return *this;
}


