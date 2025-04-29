#include "Infirmier.h"
#include <iostream>
#include <fstream>
using namespace std;

Infirmier::Infirmier() : Personnel() {
     experience=0;
}

Infirmier::Infirmier(int idVal, string nomVal, string prenomVal,  string CinVal,string emailVal,
                      string Password,  string telVal, DatePerso dateNaissanceVal, string posteVal,double salaireVal ,int experienceVal)
    : Personnel(idVal, nomVal, prenomVal, CinVal,emailVal, Password,telVal, dateNaissanceVal, posteVal, salaireVal),
      experience(experienceVal) {
}

Infirmier::~Infirmier() {}

void Infirmier::afficherPersonne() {
    Personnel::afficherPersonne();
    cout << "Experience: " << experience << " ans" << endl;
    afficherHoraires();
}

void Infirmier::modifier() {
    Personnel::modifier();
    cout << "Modifier l'experience de linfirmier (en annees): ";
    cin >> experience;
    cout << "Experience mise a jour: " << experience << " ans" << endl;
}

void Infirmier::saisirHoraires() {
    map<string, pair<string, string>> nouveauxHoraires;
    string jour;

    cout << "Saisir les jours pour lesquels vous souhaitez definir les horaires (tapez 'fin' pour terminer) : " << endl;
    while (true) {
        cout << "Saisir un jour (ou 'fin') : ";
        cin >> jour;
        if (jour == "fin") break;

        string heureDebut, heureFin;
        cout << "Heure de debut pour " << jour << " : ";
        cin >> heureDebut;
        cout << "Heure de fin pour " << jour << " : ";
        cin >> heureFin;

        nouveauxHoraires[jour] = make_pair(heureDebut, heureFin);
    }

    horaires = nouveauxHoraires;
}

void Infirmier::afficherHoraires()  {
    cout << "Horaires par jour de la semaine :" << endl;

    for (const auto& jour : jours) {
        auto it = horaires.find(jour);
        if (it != horaires.end()) {
            cout << jour << ": " << it->second.first << " - " << it->second.second << endl;
        } else {
            cout << jour << ": Horaires non specifies" << endl;
        }
    }
}

ostream& operator<<(ostream& out, const Infirmier& inf) {
    out << static_cast<const Personnel&>(inf);
    out << " "<<inf.experience <<" ";
    for (const auto& jour : inf.jours) {
        auto it = inf.horaires.find(jour);
        if (it != inf.horaires.end()) {
            out << jour << " " << it->second.first << "  " << it->second.second <<" ";
        } else {
            out << jour << " ";
        }
    }
    out<<endl;
    return out;
}

istream& operator>>(istream& in, Infirmier& inf) {
    in >> static_cast<Personnel&>(inf);
    bool isConsole = (&in == &cin);
    if(isConsole){
        cout << "Entrer lexperience (en annees) : ";
    }
    in >> inf.experience;
        if(isConsole){
            inf.saisirHoraires();
        }
    return in;
}

ostream& operator<<(ostream& out, const Infirmier* inf) {
    return out<< *inf<<endl;
}

istream& operator>>(istream& in, Infirmier* inf) {
    return in >> *inf;
}

Infirmier& Infirmier::operator=(const Infirmier& other) {
    if (this != &other) {
        Personnel::operator=(other);
        this->experience = other.experience;
        this->horaires = other.horaires;
        this->jours = other.jours;
    }
    return *this;
}

Infirmier::Infirmier(const Infirmier& other) : Personnel(other) {
    this->experience = other.experience;
    this->horaires = other.horaires;
    this->jours = other.jours;
}

void Infirmier::ecrirerInfirmierDansFichier(){
    try{
            ofstream of("BD\\Infirmier.txt", ios::app);
            of<<this;
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}
