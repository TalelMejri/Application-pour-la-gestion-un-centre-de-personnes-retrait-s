#include "Category.h"
#include <iostream>
using namespace std;

Category::Category() : id(0), nom(""), description("") {}

Category::Category(int idVal, string nomVal, string descVal)
    : id(idVal), nom(nomVal), description(descVal) {}

Category::~Category() {
}

void Category::ajouterMedicament(Medicament medicament) {
    medicaments.push_back(medicament);
}

void Category::afficherCategory() {
    cout << "Category ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Description: " << description << endl;
    cout << "Medicaments in this category: " << endl;
    for (size_t i = 0; i < medicaments.size(); ++i) {
        medicaments[i].afficherMedicament();
    }
}
