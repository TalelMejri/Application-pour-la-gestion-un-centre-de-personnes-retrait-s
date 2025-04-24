#include "Category.h"
#include <iostream>
using namespace std;

Category::Category() : id(0), nom(""), description("") {}

Category::Category(int idVal, string nomVal, string descVal)
    : id(idVal), nom(nomVal), description(descVal) {}

Category::~Category() {
    for (auto med : medicaments) {
        delete med;
    }
    medicaments.clear();
}

Category::Category(const Category& other) {
    id = other.id;
    nom = other.nom;
    description = other.description;
    for (auto med : other.medicaments) {
        medicaments.push_back(new Medicament(*med));
    }
}

Category& Category::operator=(const Category& other) {
    if (this != &other) {
        for (auto med : medicaments) delete med;
        medicaments.clear();

        id = other.id;
        nom = other.nom;
        description = other.description;
        for (auto med : other.medicaments) {
            medicaments.push_back(new Medicament(*med));
        }
    }
    return *this;
}

void Category::ajouterMedicament(Medicament* medicament) {
    medicaments.push_back(medicament);
}

void Category::ModifierMedicament(int idMed) {
    for (auto med : medicaments) {
        if (med->getId() == idMed) {
            cout << "Modification du medicament avec ID " << idMed << " :\n";
            cin >> *med;
            return;
        }
    }
    cout << "Medicament avec ID " << idMed << " non trouvé.\n";
}

void Category::SupprimerMedicament(int idMed) {
    for (auto it = medicaments.begin(); it != medicaments.end(); ++it) {
        if ((*it)->getId() == idMed) {
            delete *it;
            medicaments.erase(it);
            cout << "Medicament supprimé avec succès.\n";
            return;
        }
    }
    cout << "Medicament avec ID " << idMed << " non trouvé.\n";
}

void Category::afficherCategory() {
    cout << "Category ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Description: " << description << endl;
    cout << "Medicaments in this category: " << endl;
    for (size_t i = 0; i < medicaments.size(); ++i) {
        medicaments[i]->afficherMedicament();
    }
}

ostream& operator<<(ostream& os, const Category& category) {
    os << "Category ID: " << category.id << endl;
    os << "Nom: " << category.nom << endl;
    os << "Description: " << category.description << endl;
    os << "Medicaments in this category: " << endl;
    for (size_t i = 0; i < category.medicaments.size(); ++i) {
        os << *(category.medicaments[i]) << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const Category* category) {
    os << "Category ID: " << category->id << endl;
    os << "Nom: " << category->nom << endl;
    os << "Description: " << category->description << endl;
    os << "Medicaments in this category: " << endl;
    for (size_t i = 0; i < category->medicaments.size(); ++i) {
        os << *(category->medicaments[i]) << endl;
    }
    return os;
}

istream& operator>>(istream& is, Category& category) {
    cout << "Enter Category ID: ";
    is >> category.id;
    cout << "Enter Nom: ";
    is >> category.nom;
    cout << "Enter Description: ";
    is >> category.description;

    int numMedicaments;
    cout << "Enter the number of Medicaments: ";
    is >> numMedicaments;
    for (int i = 0; i < numMedicaments; ++i) {
        Medicament* medicament = new Medicament();
        is >> *medicament;
        category.ajouterMedicament(medicament);
    }

    return is;
}

istream& operator>>(istream& is, Category* category) {
    cout << "Enter Category ID: ";
    is >> category->id;
    cout << "Enter Nom: ";
    is >> category->nom;
    cout << "Enter Description: ";
    is >> category->description;

    int numMedicaments;
    cout << "Enter the number of Medicaments: ";
    is >> numMedicaments;
    for (int i = 0; i < numMedicaments; ++i) {
        Medicament* medicament = new Medicament();
        is >> *medicament;
        category->ajouterMedicament(medicament);
    }

    return is;
}

void Category::affichrMedicaments() {
    for (auto med : medicaments) {
        med->afficherMedicament();
    }
}

void Category::modifier() {
    cout << "Nom actuel : " << nom << endl;
    cout << "Entrez le nouveau nom : ";
    cin >> nom;

    cout << "Description actuelle : " << description << endl;
    cout << "Entrez la nouvelle description : ";
    cin >> description;
}
