#include "Batiment.h"
#include <iostream>
#include "EtageAlzheimer.h"
#include "EtageCardio.h"
#include "EtageNeurologie.h"
#include <fstream>

using namespace std;

Batiment::Batiment() : nom(""), adresse("") {}

Batiment::Batiment(string nomVal, string adresseVal) : nom(nomVal), adresse(adresseVal) {}

Batiment::~Batiment() {
    for (size_t i = 0; i < etages.size(); ++i) {
        delete etages[i];
    }
    for (size_t i = 0; i < personnes.size(); ++i) {
        delete personnes[i];
    }
}

Batiment::Batiment(const Batiment& other) : nom(other.nom), adresse(other.adresse) {
        personnes=(other.personnes);
        Etage* p;
        for (unsigned int i = 0; i < other.etages.size(); i++) {
            if (typeid(*other.etages[i]) == typeid(EtageAlzheimer)) {
                const EtageAlzheimer* etAZ = dynamic_cast<const EtageAlzheimer*>(other.etages[i]);
                if (etAZ) p = static_cast<Etage*>(new EtageAlzheimer(*etAZ));
            } else if (typeid(*other.etages[i]) == typeid(EtageCardio)) {
                 const EtageCardio* etCAR = dynamic_cast<const EtageCardio*>(other.etages[i]);
                if (etCAR) p = static_cast<Etage*>(new EtageCardio(*etCAR));
            } else if(typeid(*other.etages[i]) == typeid(EtageNeurologie)){
                 const EtageNeurologie* etNeu = dynamic_cast<const EtageNeurologie*>(other.etages[i]);
                if (etNeu) p = static_cast<Etage*>(new EtageNeurologie(*etNeu));
            }
            etages.push_back(p);
        }
}

Batiment& Batiment::operator=(const Batiment& other) {
    if (this != &other) {
        for (size_t i = 0; i < etages.size(); ++i) {
            delete etages[i];
        }
        for (size_t i = 0; i < personnes.size(); ++i) {
            delete personnes[i];
        }

        nom = other.nom;
        adresse = other.adresse;

        etages.clear();
        personnes.clear();
        personnes=(other.personnes);
        Etage* p;
        for (unsigned int i = 0; i < other.etages.size(); i++) {
            if (typeid(*other.etages[i]) == typeid(EtageAlzheimer)) {
                const EtageAlzheimer* etAZ = dynamic_cast<const EtageAlzheimer*>(other.etages[i]);
                if (etAZ) p = static_cast<Etage*>(new EtageAlzheimer(*etAZ));
            } else if (typeid(*other.etages[i]) == typeid(EtageCardio)) {
                 const EtageCardio* etCAR = dynamic_cast<const EtageCardio*>(other.etages[i]);
                if (etCAR) p = static_cast<Etage*>(new EtageCardio(*etCAR));
            } else if(typeid(*other.etages[i]) == typeid(EtageNeurologie)){
                 const EtageNeurologie* etNeu = dynamic_cast<const EtageNeurologie*>(other.etages[i]);
                if (etNeu) p = static_cast<Etage*>(new EtageNeurologie(*etNeu));
            }
            etages.push_back(p);
        }

    }
    return *this;
}

void Batiment::ajouterEtage(Etage* etage) {
    etages.push_back(etage);
}

void Batiment::ajouterPersonne(Personne* personne) {
    personnes.push_back(personne);
}

void Batiment::afficherBatiment() {
    cout << "Batiment: " << nom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Etages: " << endl;
    for (auto etage : etages) {
        etage->afficherEtage();
    }
    cout << "Personnes: " << endl;
    for (auto personne : personnes) {
        personne->afficherPersonne();
    }
}

void Batiment::supprimerEtage(int id) {
    for (size_t i = 0; i < etages.size(); ++i) {
        if (etages[i]->getId() == id) {
            delete etages[i];
            etages.erase(etages.begin() + i);
            break;
        }
    }
}

void Batiment::supprimerPersonne(int id) {
    for (size_t i = 0; i < personnes.size(); ++i) {
        if (personnes[i]->getId() == id) {
            delete personnes[i];
            personnes.erase(personnes.begin() + i);
            break;
        }
    }
}


ostream& operator <<(ostream& os, const Batiment& batiment) {
    os << "Batiment: " << batiment.nom << endl;
    os << "Adresse: " << batiment.adresse << endl;
    os << "Etages: " << endl;
    for (auto etage : batiment.etages) {
        os << *etage;
    }
    os << "Personnes: " << endl;
    for (auto personne : batiment.personnes) {
        os << *personne;
    }
    return os;
}

ostream& operator <<(ostream& os, const Batiment* batiment) {
    os << "Batiment: " << batiment->nom << endl;
    os << "Adresse: " << batiment->adresse << endl;
    os << "Etages: " << endl;
    for (auto etage : batiment->etages) {
        os << *etage;
    }
    os << "Personnes: " << endl;
    for (auto personne : batiment->personnes) {
        os << *personne;
    }
    return os;
}

istream& operator >>(istream& in, Batiment& batiment) {
    cout << "Entrez le nom du batiment: ";
    in >> batiment.nom;
    cout << "Entrez l'adresse du batiment: ";
    in >> batiment.adresse;
    return in;
}

istream& operator >>(istream& in, Batiment* batiment) {
    cout << "Entrez le nom du batiment: ";
    in >> batiment->nom;
    cout << "Entrez l'adresse du batiment: ";
    in >> batiment->adresse;
    return in;
}

void Batiment::enregistrerEtages() {
        ofstream of("BD\\Etage.txt", ios::app);
        for (auto e : etages) {
            if (dynamic_cast<EtageAlzheimer*>(e)) {
                of << "EtageAlzheimer" << " ";
                of << *e;
            }
        }
}

void Batiment::afficherEtage() {
    if (etages.empty()) {
        cout << "Aucun étage enregistré dans le bâtiment." << endl;
    } else {
        cout << "===== Liste des étages du bâtiment =====" << endl;
        for (auto etage : etages) {
            if (etage != nullptr)
                etage->afficherEtage();
        }
        cout << "========================================" << endl;
    }
}



Etage* chargerEtageDepuisFichier(ifstream& in) {
    string type;
    in >> type;

    if (type == "EtageAlzheimer") {
        EtageAlzheimer* etage = new EtageAlzheimer();
        in >> etage;
        return etage;
    }

    return nullptr;
}

 void Batiment::chargerEtages() {
        ifstream in("BD\\Etage.txt");
        while (!in.eof()) {
            Etage* e = chargerEtageDepuisFichier(in);
            if (e != nullptr)
                etages.push_back(e);
        }
        in.close();
}
