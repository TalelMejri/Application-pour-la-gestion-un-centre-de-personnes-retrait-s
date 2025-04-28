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


bool MedecinInfirmier::operator<( MedecinInfirmier& other) {
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
    out << " " << mi.getSpecialite() << " ";
    out << " " << mi.getExperience() << " ";
    out << "  " << mi.grade;
    out << " " << mi.nbrOperation<<endl;
    return out;
}

ostream& operator<<(ostream& out, const MedecinInfirmier* mi) {
    return out << *mi;
}

istream& operator>>(istream& in, MedecinInfirmier& mi) {
    in >> static_cast<Personnel&>(mi);

    string specialite, grade;
    int experience, nbrOperation;

    bool isFile = (&in != &cin);  // Check if reading from a file or console

    if (isFile) {
        in >> specialite >> experience >> grade >> nbrOperation;

        mi.setSpecialite(specialite);  // Set the specialite in Medecin
        mi.setExperience(experience);  // Set the experience in Infirmier
        mi.setGrade(grade);            // Set the grade in MedecinInfirmier
        mi.SetNbrOperation(nbrOperation); // Set the nbrOperation in MedecinInfirmier
    }

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

