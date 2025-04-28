#include "MedecinInfirmier.h"
#include <iostream>
#include <fstream>

using namespace std;

MedecinInfirmier::MedecinInfirmier() : Medecin(), Infirmier() {
    nbrOperation = 0;
    grade = "";
}

MedecinInfirmier::MedecinInfirmier(int id, string nom, string prenom, string cin, string email, string password,
                                   string tel, DatePerso date,string poste, double salaire,
                                   string specialite, int experience, string grade)
    : Personnel(id, nom, prenom, cin, email, password, tel, date,poste, salaire),
      Medecin(id, nom, prenom, cin, email, password, tel, date, specialite, salaire, ""),
      Infirmier(id, nom, prenom, cin, email, password, tel, date, "", salaire, experience) {
    this->grade = grade;
    this->nbrOperation = 0;
}

MedecinInfirmier::~MedecinInfirmier() {}

MedecinInfirmier::MedecinInfirmier(const MedecinInfirmier& other)
    : Medecin(other), Infirmier(other) {
    this->nbrOperation = other.nbrOperation;
    this->grade = other.grade;
}

MedecinInfirmier& MedecinInfirmier::operator=(const MedecinInfirmier& other) {
    if (this != &other) {
        Medecin::operator=(other);
        Infirmier::operator=(other);
        nbrOperation = other.nbrOperation;
        grade = other.grade;
    }
    return *this;
}

int MedecinInfirmier::getExperience() const {
    return Infirmier::getExperience();
}

bool MedecinInfirmier::operator<(const MedecinInfirmier& other) {
    return getExperience() < other.getExperience();
}

void MedecinInfirmier::afficherPersonne() {
    cout << "===== MedecinInfirmier =====" << endl;
    Personnel::afficherPersonne();
    cout << "Specialite: " << getSpecialite() << endl;
    cout << "Experience: " << getExperience() << " ans" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Nombre d'operations: " << nbrOperation << endl;
}

void MedecinInfirmier::modifier() {
    string g;
    int n;
    cout << "Nouveau grade : ";
    cin >> g;
    cout << "Nouveau nombre d'operations : ";
    cin >> n;
    setGrade(g);
    SetNbrOperation(n);
}

ostream& operator<<(ostream& out, const MedecinInfirmier& mi) {
    out << static_cast<const Personnel&>(mi);
    out << getSpecialite() << " ";
    out << getExperience() << " ";
    out << "  " << mi.grade;
    out << " " << mi.nbrOperation;
    return out;
}

ostream& operator<<(ostream& out, const MedecinInfirmier* mi) {
    return out << *mi;
}

istream& operator>>(istream& in, MedecinInfirmier& mi) {
    string g;
    int nbOp;
    in >> static_cast<Personnel&>(mi);
    bool isConsole = (&in == &cin);
    if (isConsole)
    cout << "Entrer le grade: ";
    in >> g;
    if (isConsole)
    cout << "Entrer le nombre d'operations: ";
    in >> nbOp;
    return in;
}

istream& operator>>(istream& in, MedecinInfirmier* mi) {
    return in >> *mi;
}

void MedecinInfirmier::ecrirerMedecinInfDansFichier() {
    try{
            ofstream of("BD\\MedecinInfirmier.txt", ios::app);
            of<<this;
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}

