#include "Batiment.h"
#include <iostream>
#include "EtageAlzheimer.h"
#include "EtageCardio.h"
#include "EtageNeurologie.h"
#include <map>
#include <fstream>

using namespace std;

Batiment::Batiment() : nom(""), adresse("") {}

Batiment::Batiment(string nomVal, string adresseVal) : nom(nomVal), adresse(adresseVal) {}

Batiment::~Batiment() {
    for (auto& pair : etages) {
        for (Etage* etage : pair.second) {
            delete etage;
        }
    }
    for (size_t i = 0; i < personnes.size(); ++i) {
        delete personnes[i];
    }
}

Batiment::Batiment(const Batiment& other) : nom(other.nom), adresse(other.adresse) {
    personnes = other.personnes;

    for (const auto& pair : other.etages) {
        const string& type = pair.first;
        list<Etage*> newList;

        for (Etage* original : pair.second) {
            Etage* copy = nullptr;

            if (typeid(*original) == typeid(EtageAlzheimer)) {
                copy = new EtageAlzheimer(*dynamic_cast<EtageAlzheimer*>(original));
            }
            else if (typeid(*original) == typeid(EtageCardio)) {
                copy = new EtageCardio(*dynamic_cast<EtageCardio*>(original));
            }
            else if (typeid(*original) == typeid(EtageNeurologie)) {
                copy = new EtageNeurologie(*dynamic_cast<EtageNeurologie*>(original));
            }

            if (copy) {
                newList.push_back(copy);
            }
        }

        etages[type] = newList;
    }
}

Batiment& Batiment::operator=(const Batiment& other) {
    if (this != &other) {
        for (auto& pair : etages) {
            for (Etage* etage : pair.second) {
                delete etage;
            }
        }
        for (size_t i = 0; i < personnes.size(); ++i) {
            delete personnes[i];
        }

        nom = other.nom;
        adresse = other.adresse;
        personnes = other.personnes;
        etages.clear();

        for (const auto& pair : other.etages) {
            const string& type = pair.first;
            list<Etage*> newList;

            for (Etage* original : pair.second) {
                Etage* copy = nullptr;

                if (typeid(*original) == typeid(EtageAlzheimer)) {
                    copy = new EtageAlzheimer(*dynamic_cast<EtageAlzheimer*>(original));
                }
                else if (typeid(*original) == typeid(EtageCardio)) {
                    copy = new EtageCardio(*dynamic_cast<EtageCardio*>(original));
                }
                else if (typeid(*original) == typeid(EtageNeurologie)) {
                    copy = new EtageNeurologie(*dynamic_cast<EtageNeurologie*>(original));
                }

                if (copy) {
                    newList.push_back(copy);
                }
            }

            etages[type] = newList;
        }
    }
    return *this;
}

void Batiment::ajouterEtage(const string& type, Etage* etage) {
    etages[type].push_back(etage);
}

void Batiment::ajouterPersonne(Personne* personne) {
    personnes.push_back(personne);
}

void Batiment::afficherBatiment() {
    cout << "Batiment: " << nom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Etages: " << endl;
    for (const auto& pair : etages) {
        cout << "Type: " << pair.first << " (" << pair.second.size() << " etages)" << endl;
        for (Etage* etage : pair.second) {
            etage->afficherEtage();
        }
    }
    cout << "Personnes: " << endl;
    for (auto personne : personnes) {
        personne->afficherPersonne();
    }
}

void Batiment::supprimerEtage(const string& type, int id) {
    auto it = etages.find(type);
    if (it != etages.end()) {
        list<Etage*>& etageList = it->second;
        for (auto listIt = etageList.begin(); listIt != etageList.end(); ++listIt) {
            if ((*listIt)->getId() == id) {
                delete *listIt;
                etageList.erase(listIt);
                sauvegarderEtageDansFichier();
                break;
            }
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
    for (const auto& pair : batiment.etages) {
        os << "Type: " << pair.first << " (" << pair.second.size() << " etages)" << endl;
        for (Etage* etage : pair.second) {
            os << *etage;
        }
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
    for (const auto& pair : batiment->etages) {
        os << "Type: " << pair.first << " (" << pair.second.size() << " etages)" << endl;
        for (Etage* etage : pair.second) {
            os << *etage;
        }
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
    for (const auto& pair : etages) {
        const string& type = pair.first;
        for (Etage* e : pair.second) {
            of << type << " ";
            if (EtageAlzheimer* alz = dynamic_cast<EtageAlzheimer*>(e)) {
                of << *alz << endl;
            } else if (EtageNeurologie* neuro = dynamic_cast<EtageNeurologie*>(e)) {
                of << *neuro << endl;
            } else if (EtageCardio* cardio = dynamic_cast<EtageCardio*>(e)) {
                of << *cardio << endl;
            } else {
                of << *e << endl;
            }
        }
    }
}

void Batiment::afficherEtage() {
    if (etages.empty()) {
        cout << "Aucun etage enregistre dans le batiment." << endl;
    } else {
        cout << "===== Liste des etages du batiment =====" << endl;
        for (const auto& pair : etages) {
            cout << "Type: " << pair.first << " (" << pair.second.size() << " etages)" << endl;
            for (Etage* etage : pair.second) {
                etage->afficherEtage();
            }
        }
        cout << "========================================" << endl;
    }
}

void Batiment::chargerEtages() {
    ifstream in("BD\\Etage.txt");
    if (!in.is_open()) {
        cerr << "Erreur lors de louverture du fichier." << endl;
        return;
    }

    string type;
    while (in >> type) {
        if (type == "Alzheimer") {
            EtageAlzheimer* e = new EtageAlzheimer();
            in >> e;
            etages[type].push_back(e);
        }
         else if (type == "Cardio") {
            EtageCardio* e = new EtageCardio();
            in >> e;
            etages[type].push_back(e);
        }else if(type=="Neurologie"){
            EtageNeurologie* e = new EtageNeurologie();
            in >> e;
            etages[type].push_back(e);
        }
    }

    in.close();
}

void Batiment::sauvegarderEtageDansFichier() {
    try {
        ofstream of("BD\\Etage.txt", ios::trunc);
        if (!of) {
            cerr << "Erreur lors de louverture du fichier pour lecriture.\n";
            return;
        }

        for (const auto& pair : etages) {
            const string& type = pair.first;
            for (Etage* e : pair.second) {
                of << type << " ";
                if (EtageAlzheimer* alz = dynamic_cast<EtageAlzheimer*>(e)) {
                    of << *alz << endl;
                } else if (EtageNeurologie* neuro = dynamic_cast<EtageNeurologie*>(e)) {
                    of << *neuro << endl;
                } else if (EtageCardio* cardio = dynamic_cast<EtageCardio*>(e)) {
                    of << *cardio << endl;
                } else {
                    of << *e << endl;
                }
            }
        }

        of.close();
        cout << "Etages mis a jour dans le fichier avec succes.\n";
    } catch (exception& e) {
        cerr << "Erreur lors de la sauvegarde des etages : " << e.what() << endl;
    }
}
