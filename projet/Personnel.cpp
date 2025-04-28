#include "Personnel.h"
#include <iostream>
using namespace std;

Personnel::Personnel() : Personne() {
    poste = "";
    salaire = 0.0;
}

Personnel::Personnel(int id, string nom, string prenom, string cinn, string email, string password, string tlf, DatePerso date_naissance, string poste, double salaire)
    : Personne(id, nom, prenom, cinn, email, password, tlf, date_naissance) {
    this->poste = poste;
    this->salaire = salaire;
}

Personnel::~Personnel() {
}

Personnel::Personnel(const Personnel & a): Personne(a){
        poste = a.poste;
        salaire = a.salaire;
}

Personnel& Personnel::operator=(const Personnel& p) {
    if (this != &p) {

        Personne::operator=(p);
        poste = p.poste;
        salaire = p.salaire;
    }
    return *this;
}

bool Personnel::operator>(const Personnel& autre) const {
    return this->salaire > autre.salaire;
}

void Personnel::afficherPersonne() {
    Personne::afficherPersonne();
    cout << "Poste: " << poste << endl;
    cout << "Salaire: " << salaire << " TND" << endl;
}

void Personnel::modifier() {
    cout << "Modifier les informations du personnel:" << endl;
    Personne::modifier();
    cout << "Nouveau poste: ";
    cin>>poste;
    cout << "Nouveau salaire: ";
    cin >> salaire;
}

istream& operator>>(istream& in, Personnel& p) {
   /* Personne*q =&p;
    in>>*q;*/
    in >> static_cast <Personne&>(p);
    bool isConsole = (&in == &cin);
    if (isConsole)
    cout << "Poste: ";
    in >> p.poste;
    if (isConsole)
    cout << "Salaire: ";
    in >> p.salaire;
    return in;
}


istream& operator>>(istream& in, Personnel* p) {
   /* Personne*q =&p;
    in>>*q;*/
    in >> static_cast <Personne*>(p);
    cout << "Poste: ";
    in >> p->poste;
    cout << "Salaire: ";
    in >> p->salaire;
    return in;
}

ostream& operator<<(ostream& out, const Personnel& p) {
   /* Personne*q =&p;
    out<<*q; */
    out << static_cast <const Personne&>(p);
    out << " " << p.poste ;
    out << " " << p.salaire;
    return out;
}


ostream& operator<<(ostream& out, const Personnel* p) {
   /* Personne*q =&p;
    out<<*q; */
    out << static_cast <const Personne*>(p);
    out << " " << p->poste ;
    out << " " << p->salaire << endl;
    return out;
}
