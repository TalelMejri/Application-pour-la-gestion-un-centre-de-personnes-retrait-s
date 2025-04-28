#include "Resident.h"
#include <iostream>
#include <fstream>
using namespace std;

Resident::Resident() : Personne(), solde(0), dossierMedical(NULL) {}

Resident::Resident(int idVal, string nomVal, string prenomVal, string emailVal, string adresseVal,
                   string telVal, string sexeVal, DatePerso dateNaissanceVal, float soldeInit)
    : Personne(idVal, nomVal, prenomVal, emailVal, adresseVal, telVal, sexeVal, dateNaissanceVal) {
    solde = soldeInit;
    dossierMedical = new DossierMedical();
}

Resident::Resident(const Resident& other) : Personne(other) {
    solde = other.solde;
    if (other.dossierMedical)
        dossierMedical = new DossierMedical(*other.dossierMedical);
    else
        dossierMedical = new DossierMedical();
}

Resident& Resident::operator=(const Resident& other) {
    if (this != &other) {
        Personne::operator=(other);
        solde = other.solde;

        if (dossierMedical) {
            delete dossierMedical;
        }

        dossierMedical = other.dossierMedical ? new DossierMedical(*other.dossierMedical) : new DossierMedical();
    }
    return *this;
}

Resident::~Resident() {
    delete dossierMedical;
}

void Resident::saisirResident() {
    Personne::saisir_personne();
    solde = 0;
    dossierMedical = new DossierMedical();
}

void Resident::afficherPersonne() {
    Personne::afficherPersonne();
    cout << "Solde: " << solde << " dinars" << endl;
    if (dossierMedical != NULL) {
        cout << "Dossier Medical:" << endl;
        dossierMedical->afficherDossierMedical();
    } else {
        cout << "Aucun dossier medical." << endl;
    }
}

void Resident::modifier() {
    float soldeVal;
    cout << "Nouveau solde : ";
    cin >> soldeVal;
    solde = soldeVal;
    cout << "Solde modifie: " << solde << " dinars" << endl;
}

void Resident::modifierSolde(float nouveauSolde) {
    solde = nouveauSolde;
}

ostream& operator<<(ostream& os, const Resident& r) {
    os << static_cast<const Personne&>(r);
    os << r.solde << " ";
    os << "0" << endl;
  /*  if (r.dossierMedical)
        os<<r.dossierMedical;
    else
        os << "0" << endl;*/
    return os;
}

ostream& operator<<(ostream& os, const Resident* r) {
     os << static_cast<const Personne*>(r);
    os << r->solde ;
    if (r->dossierMedical)
        os<<r->dossierMedical;
    else
        os << "0" << endl;
    return os;
}

istream& operator>>(istream& is, Resident& r) {
    is >> static_cast <Personne&>(r);
     r.solde = 0;
    //is >> r.solde;
    string  test;
    if(test=="0"){
        r.dossierMedical = nullptr;
    }else{
        //is>>r.dossierMedical;
    }
    return is;
}

istream& operator>>(istream& is, Resident* r) {
    is >> static_cast <Personne*>(r);
     r->solde = 0;
    //is >> r->solde;
    return is;
}

void Resident::ecrirerResidentDansFichier(){
    try{
            ofstream of("BD\\Resident.txt", ios::app);
            of<<this;
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}
