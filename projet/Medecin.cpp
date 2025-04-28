#include "Medecin.h"
#include <fstream>
#include "Personnel.h"

Medecin::Medecin()
    : Personnel(), specialite(""), categories() {}

Medecin::Medecin(int idVal, string nomVal, string prenomVal,  string CinVal,string emailVal,
                      string Password,  string telVal, DatePerso dateNaissanceVal,string posteVal,double salaireVal ,string specialiteVal)
    : Personnel(idVal, nomVal, prenomVal, CinVal,emailVal,Password, telVal, dateNaissanceVal,poste,salaireVal), specialite(specialiteVal), categories() {}

Medecin::Medecin(const Medecin& other)
    : Personnel(other),specialite(other.specialite), categories(other.categories) {}

Medecin& Medecin::operator=(const Medecin& other) {
    if (this != &other) {
        Personnel::operator=(other);
        specialite = other.specialite;
        categories = other.categories;
    }
    return *this;
}

void Medecin::afficherPersonne() {
    Personnel::afficherPersonne();
    cout << "Specialite: " << specialite << endl;
    afficherCategories();
}

void Medecin::modifier() {
    Personnel::modifier();
    cout << "Modifier specialite : ";
    cin >> specialite;
}

Medecin::~Medecin() {}

void Medecin::ajouterCategory(Category category) {
    categories.push_back(category);
}

void Medecin::afficherCategories() {
    cout << "Categories du medecin :" << endl;

    if (categories.empty()) {
        cout << "Aucune catégorie." << endl;
        return;
    }

    for (size_t i = 0; i < categories.size(); ++i) {
        cout << "Category " << i + 1 << " :" << endl;
        categories[i].afficherCategory();
    }
}

void Medecin::SupprimerCategory(int pos) {
    if (pos < 0 || pos >= static_cast<int>(categories.size())) {
        cout << "Position invalide." << endl;
        return;
    }

    categories.erase(categories.begin() + pos);
    cout << "Catégorie à la position " << pos << " supprimée." << endl;
}

void Medecin::ModifierCategory(int pos) {
    if (pos < 0 || pos >= static_cast<int>(categories.size())) {
        cout << "Position invalide." << endl;
        return;
    }

    cout << "Modification de la catégorie à la position " << pos << ":" << endl;
    categories[pos].modifier();
}

ostream& operator<<(ostream& os, const Medecin& m) {
    os << static_cast<const Personnel&>(m);
    os << " "<< m.specialite << endl;

   /* for (const Category& c : m.categories) {
        os << c;
    } */

    return os;
}

istream& operator>>(istream& is, Medecin& m) {
    is >> static_cast<Personnel&>(m);
    bool isConsole = (&is == &cin);
    if (isConsole)
    cout << "Entrer specialite: ";
    is >> m.specialite;

    /*char choix = 'o';
    while (choix == 'o' || choix == 'O') {
        Category c;
        cout << "Ajouter une catégorie ? (o/n): ";
        is >> choix;
        if (choix == 'o' || choix == 'O') {
            is >> c;
            m.ajouterCategory(c);
        }
    }*/

    return is;
}

ostream& operator<<(ostream& os, const Medecin* m) {
    return os << *m;
}

istream& operator>>(istream& is, Medecin* m) {
    is >> *static_cast<Personnel*>(m);
    cout << "Entrer spécialité: ";
    is >> m->specialite;

    /*char choix = 'o';
    while (choix == 'o' || choix == 'O') {
        Category c;
        cout << "Ajouter une catégorie ? (o/n): ";
        is >> choix;
        if (choix == 'o' || choix == 'O') {
            is >> c;
            m->ajouterCategory(c);
        }
    }*/

    return is;
}

void Medecin::ecrirerMedecinDansFichier(){
    try{
            ofstream of("BD\\Medecin.txt", ios::app);
            of<<this;
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}
