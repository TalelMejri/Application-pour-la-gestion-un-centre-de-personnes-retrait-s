
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

void Medecin::ajouterDossierMedicalResident(vector<Resident> residents) {
    if (residents.empty()) {
        cout << "Aucun resident disponible.\n";
        return;
    }

    cout << "\nListe des residents:\n";
    for (size_t i = 0; i < residents.size(); ++i) {
        cout << i+1 << ". ID: " << residents[i].getId()
             << " - " << residents[i].getNom()
             << " " << residents[i].getPrenom() << endl;
    }

    int choix;
    cout << "Selectionnez un resident (numero): ";
    cin >> choix;

    if (choix < 1 || choix > static_cast<int>(residents.size())) {
        cout << "Choix invalide!\n";
        return;
    }

    Resident& resident = residents[choix-1];
    int idResident = resident.getId();

    DossierMedical* nouveauDossier = new DossierMedical();
    cout << "\nCreation du dossier medical pour le resident ID: " << idResident << endl;
    cout << "Combien de medicaments souhaitez-vous ajouter? ";
    int nbMedicaments;
    cin >> nbMedicaments;

    for (int i = 0; i < nbMedicaments; i++) {
        Medicament* med = new Medicament();
        cout << "\nMedicament " << i+1 << ":\n";
        cin >> *med;
        nouveauDossier->ajouterMedicament(med);
    }

    resident.setDossierMedical(nouveauDossier);

    sauvegarderDossierMedical(resident);
}

void Medecin::sauvegarderDossierMedical( Resident resident) {
    if (!resident.getDossierMedical()) {
        cout << "Aucun dossier medical a sauvegarder.\n";
        return;
    }

    string filename = "BD/DossierMedical_" + to_string(resident.getId()) + ".txt";

    try {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Impossible douvrir le fichier");
        }

        file << "=== Dossier Medical du Resident ID: " << resident.getId() << " ===\n";
        file << "Nom: " << resident.getNom() << " " << resident.getPrenom() << "\n\n";

        file << "Medicaments:\n";
        file << "------------\n";

        for (Medicament* med : resident.getDossierMedical()->getMedicaments()) {
            file << "ID Medicament: " << med->getId() << "\n";
            file << "Nom: " << med->getNom() << "\n";
            file << "Quantite: " << med->getQuantite() << "\n";
            file << "Date expiration: "
                 << med->getDateLimit().jour << "/"
                 << med->getDateLimit().mois << "/"
                 << med->getDateLimit().annee << "\n";
            file << "------------\n";
        }

        file.close();
        cout << "Dossier medical sauvegarde dans " << filename << endl;
    } catch (const exception& e) {
        cerr << "Erreur lors de la sauvegarde: " << e.what() << endl;
    }
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
        cout << "Aucune categorie." << endl;
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
    cout << "Categorie à la position " << pos << " supprimee." << endl;
}

void Medecin::sauvegarderInfDansFichier() {
    try {
        ofstream of("BD\\Infirmier.txt", ios::trunc);
        if (!of) {
            cerr << "Erreur lors de louverture du fichier pour lecriture.\n";
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

    cout << "Modification de la categorie à la position " << pos << ":" << endl;
    categories[pos].modifier();
}

ostream& operator<<(ostream& os, const Medecin& m) {
    os << static_cast<const Personnel&>(m);
    os << " "<< m.specialite << endl;
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
        cout << "Infirmier assigne avec succes!\n";
}

void Medecin::afficherInfirmiersAssignes() const {
    if (infirmiersAssignes.empty()) {
        cout << "Aucun infirmier assigne.\n";
        return;
    }

    cout << "Liste des infirmiers assignes (" << infirmiersAssignes.size() << "):\n";
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
    cout << "Entrez le numero de linfirmier a modifier: ";
    cin >> choix;

    if (choix < 1 || choix > static_cast<int>(infirmiersAssignes.size())) {
        cout << "Numéro invalide!\n";
        return;
    }

    infirmiersAssignes[choix-1]->modifier();
    sauvegarderInfDansFichier();
    cout << "Infirmier modifie avec succes!\n";
}

void Medecin::supprimerInfirmierAssignes() {
    afficherInfirmiersAssignes();
    if (infirmiersAssignes.empty()) return;

    int choix;
    cout << "Entrez le numero de linfirmier a supprimer: ";
    cin >> choix;

    if (choix < 1 || choix > static_cast<int>(infirmiersAssignes.size())) {
        cout << "Numero invalide!\n";
        return;
    }

    infirmiersAssignes.erase(infirmiersAssignes.begin() + choix - 1);
    sauvegarderInfDansFichier();
    cout << "Infirmier supprime avec succes\n";
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
    ifstream file("BD\\reclamations.txt");
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
    cout << "Entrer specialite: ";
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
