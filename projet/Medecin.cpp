
#include "env.h"
Medecin::Medecin()
    : Personnel(), specialite(""), categories() {
        LireInfirmierFromFichier();
        loadReclamations();
    }

Medecin::Medecin(int idVal, string nomVal, string prenomVal,  string CinVal,string emailVal,
                      string Password,  string telVal, DatePerso dateNaissanceVal,string posteVal,double salaireVal ,string specialiteVal)
    : Personnel(idVal, nomVal, prenomVal, CinVal,emailVal,Password, telVal, dateNaissanceVal,poste,salaireVal), specialite(specialiteVal), categories() {
        loadReclamations();
        LireInfirmierFromFichier();
    }

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

void Medecin::ajouterDossierMedicalResident() {
    vector<Resident> residents;
     try{
            ifstream of("BD\\Resident.txt");
            Resident r;
           while (of >> r) {
                residents.push_back(r);
            }
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }

    if (residents.empty()) {
        cout << "Aucun resident disponible.\n";
        return;
    }

    cout << "\nListe des residents:\n";
    for (size_t i = 0; i < residents.size(); ++i) {
        cout << i+1 << ". ";
        residents[i].afficherPersonne();
        cout << "-----------------\n";
    }

    int choix;
    cout << "Selectionnez un resident: ";
    cin >> choix;

    if (choix < 1 || choix > static_cast<int>(residents.size())) {
        cout << "Choix invalide!\n";
        return;
    }

    DossierMedical* nouveauDossier = new DossierMedical();
    residents[choix-1].setDossierMedical(nouveauDossier);

    cout << "Dossier medical ajoute avec succes!\n";
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
        cout << "Aucune cat�gorie." << endl;
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
    cout << "Cat�gorie � la position " << pos << " supprim�e." << endl;
}

void Medecin::sauvegarderInfDansFichier() {
    try {
        ofstream of("BD\\Infirmier.txt", ios::trunc);
        if (!of) {
            cerr << "Erreur lors de l'ouverture du fichier pour l'�criture.\n";
            return;
        }

      for (int i=0;i<infirmiersAssignes.size();i++) {
            of << infirmiersAssignes[i] << endl ;
      }

        of.close();
        cout << "Infirmier mis a jour dans le fichier avec succe.\n";
    } catch (exception& e) {
        cerr << "Erreur lors de la sauvegarde des residents : " << e.what() << endl;
    }
}

void Medecin::ModifierCategory(int pos) {
    if (pos < 0 || pos >= static_cast<int>(categories.size())) {
        cout << "Position invalide." << endl;
        return;
    }

    cout << "Modification de la cat�gorie � la position " << pos << ":" << endl;
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
    return is;
}

ostream& operator<<(ostream& os, const Medecin* m) {
    return os << *m;
}

void Medecin::assignerInfirmier(Infirmier* inf) {
        infirmiersAssignes.push_back(inf);
        cout << "Infirmier assign� avec succes!\n";
}

void Medecin::afficherInfirmiersAssignes() const {
    if (infirmiersAssignes.empty()) {
        cout << "Aucun infirmier assign�.\n";
        return;
    }

    cout << "Liste des infirmiers assign�s (" << infirmiersAssignes.size() << "):\n";
    for (size_t i = 0; i < infirmiersAssignes.size(); ++i) {
        cout << i+1 << ". ";
        infirmiersAssignes[i]->afficherPersonne();
        cout << "-----------------\n";
    }
}

void Medecin::modifierInfirmierAssignes() {
    afficherInfirmiersAssignes();
    if (infirmiersAssignes.empty()) return;

    int choix;
    cout << "Entrez le num�ro de l'infirmier � modifier: ";
    cin >> choix;

    if (choix < 1 || choix > static_cast<int>(infirmiersAssignes.size())) {
        cout << "Num�ro invalide!\n";
        return;
    }

    infirmiersAssignes[choix-1]->modifier();
    sauvegarderInfDansFichier();
    cout << "Infirmier modifi� avec succ�s!\n";
}

void Medecin::supprimerInfirmierAssignes() {
    afficherInfirmiersAssignes();
    if (infirmiersAssignes.empty()) return;

    int choix;
    cout << "Entrez le num�ro de l'infirmier � supprimer: ";
    cin >> choix;

    if (choix < 1 || choix > static_cast<int>(infirmiersAssignes.size())) {
        cout << "Num�ro invalide!\n";
        return;
    }

    infirmiersAssignes.erase(infirmiersAssignes.begin() + choix - 1);
    sauvegarderInfDansFichier();
    cout << "Infirmier supprim� avec succ�s!\n";
}


void Medecin::LireInfirmierFromFichier(){
      try{
            ifstream of("BD\\Infirmier.txt");
            Infirmier r;
           while (of >> r) {
                infirmiersAssignes.push_back(new Infirmier(r));
            }
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}

void Medecin::loadReclamations() {
    ifstream file("BD/reclamations.txt");
    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier reclamations.txt" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            reclamations.push(line);
        }
    }
    file.close();
}

void Medecin::AfficherReclamations() {
    if (reclamations.empty()) {
        cout << "Aucune reclamation disponible." << endl;
        return;
    }

    stack<string> temp = reclamations;
    int count = 1;

    cout << "Liste des reclamations:" << endl;
    cout << "-----------------------" << endl;

    while (!temp.empty()) {
        cout << count++ << ". " << temp.top() << endl;
        temp.pop();
    }
    cout << "-----------------------" << endl;
}

istream& operator>>(istream& is, Medecin* m) {
    is >> *static_cast<Personnel*>(m);
    cout << "Entrer sp�cialit�: ";
    is >> m->specialite;
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
