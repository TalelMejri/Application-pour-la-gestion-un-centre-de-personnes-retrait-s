#include "Responsable.h"
#include "Infirmier.h"
#include "Medecin.h"
#include <iostream>
#include "Resident.h"
#include <fstream>
using namespace std;

Responsable::Responsable() : Personne() {
    LireResidentFromFichier();
}

Responsable::Responsable(int id, string nom, string prenom, string cinn, string email, string password, string tlf, DatePerso date_naissance)
    : Personne(id, nom, prenom, cinn, email, password, tlf, date_naissance) {
            LireResidentFromFichier();
    }

Responsable::~Responsable() {
    for (int i = 0; i < employes.size(); i++) {
        delete employes[i];
    }
    employes.clear();
    residents.clear();
}

Responsable::Responsable(const Responsable& A) : Personne(A) {
    Personnel* p;
    for (unsigned int i = 0; i < A.employes.size(); i++) {
        if (typeid(*A.employes[i]) == typeid(Infirmier)) {
            const Infirmier* inf = dynamic_cast<const Infirmier*>(A.employes[i]);
            if (inf) p = static_cast<Personnel*>(new Infirmier(*inf));
        } else if (typeid(*A.employes[i]) == typeid(Medecin)) {
            const Medecin* med = dynamic_cast<const Medecin*>(A.employes[i]);
            if (med) p = static_cast<Personnel*>(new Medecin(*med));
        } else {
            p = new Personnel(*A.employes[i]);
        }
        employes.push_back(p);
    }
    batiment = A.batiment;
    residents = A.residents;
}

Responsable& Responsable::operator=(const Responsable& A) {
    if (this != &A) {
        Personne::operator=(A);

        for (unsigned int i = 0; i < employes.size(); i++) {
            delete employes[i];
        }
        employes.clear();

        Personnel* p;
        for (unsigned int i = 0; i < A.employes.size(); i++) {
            if (typeid(*A.employes[i]) == typeid(Infirmier)) {
                const Infirmier* inf = dynamic_cast<const Infirmier*>(A.employes[i]);
                if (inf) p = static_cast<Personnel*>(new Infirmier(*inf));
            } else if (typeid(*A.employes[i]) == typeid(Medecin)) {
                const Medecin* med = dynamic_cast<const Medecin*>(A.employes[i]);
                if (med) p = static_cast<Personnel*>(new Medecin(*med));
            } else {
                p = new Personnel(*A.employes[i]);
            }
            employes.push_back(p);
        }

        batiment = A.batiment;
        residents = A.residents;
    }
    return *this;
}


ostream& operator<<(ostream& os, const Responsable& r) {
    os << static_cast <const Personne&>(r);
    for (auto emp : r.employes) {
        os << *emp <<" ";
    }

    for (const auto& res : r.residents) {
        os << res<< " ";
    }

   // os <<  r.batiment;

    return os;
}

istream& operator>>(istream& is, Responsable& r) {
    is>> static_cast <Personne&>(r);
    return is;
}

ostream& operator<<(ostream& os, const Responsable* r) {
   os << static_cast <const Personne*>(r);
    for (auto emp : r->employes) {
        os << *emp <<" ";
    }

    for (const auto& res : r->residents) {
        os << res<< " ";
    }

   // os <<  r.batiment;

    return os;
}

istream& operator>>(istream& is, Responsable* r) {
    if (r != nullptr) {
        is >> *r;
    }
    return is;
}

void Responsable::ajouterEmploye(Personnel* employe) {
    employes.push_back(employe);
    cout << "Employ� ajout� avec succ�s.\n";
}

void Responsable::supprimerEmploye(int id) {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i]->getId() == id) {
            delete employes[i];
            employes.erase(employes.begin() + i);
            cout << "Employ� supprim� avec succ�s.\n";
            return;
        }
    }
    cout << "Aucun employ� avec cet ID.\n";
}


void Responsable::afficherEmployes() {
    if (employes.empty()) {
        cout << "Aucun employ� enregistr�.\n";
        return;
    }
    cout << "Liste des employ�s :\n";
    for (Personnel* p : employes) {
        cout << *p << endl;
    }
}

void Responsable::modifier(int id) {
    for (Personnel* p : employes) {
        if (p->getId() == id) {
            cout << "Modification de l'employ� avec ID " << id << " :\n";
            p->modifier();
            return;
        }
    }
    cout << "Aucun employ� trouv� avec cet ID.\n";
}

int Responsable::rechercherEmploye(int id) {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i]->getId() == id)
            return i;
    }
    return -1;
}

void Responsable::LireResidentFromFichier(){
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
}

void Responsable::AfficherResident() {
        if (residents.empty()) {
            cout << "Aucun r�sident enregistr�.\n";
            return;
        }
        for (int i=0;i<residents.size();i++) {
            cout <<residents[i]<< endl;
        }
}

int Responsable::RechercherResident(int id) {
        for (int i = 0; i < residents.size(); ++i) {
            if (residents[i].getId() == id) {
                return i;
            }
        }
        return -1;
}

void Responsable::ModifierResident(int id) {
        int index = RechercherResident(id);
        if (index == -1) {
            cout << "R�sident non trouv�.\n";
            return;
        }
        residents[index].modifier();
        cout << "R�sident modifi� avec succ�s.\n";
}

 void Responsable::SupprimerResident(int id) {
        int index = RechercherResident(id);
        if (index == -1) {
            cout << "R�sident non trouv�.\n";
            return;
        }
        residents.erase(residents.begin() + index);
        cout << "R�sident supprim� avec succ�s.\n";
}

void Responsable::afficherPersonne() {
    cout << *this;
}

 void Responsable::modifier(){
    Personne::modifier();
 }

