#include "Personne.h"
#include <stdexcept>
#include <thread>

int Personne::idCounter = 0;

Personne::Personne() {
     id = ++idCounter;
    nom = "";
    prenom = "";
    cinn = "";
    email = "";
    password = "";
    tlf = "";
    date_naissance.jour=0;
    date_naissance.mois=0;
    date_naissance.anne=0;
}

Personne::Personne(int idParam, string nom, string prenom, string cinn, string email, string password, string tlf, DatePerso date_naissance) {
   id = idParam != -1 ? idParam : ++idCounter;
    this->nom = nom;
    this->prenom = prenom;
    this->cinn = cinn;
    this->email = email;
    this->password = password;
    this->tlf = tlf;
    this->date_naissance = date_naissance;
}

Personne::Personne(const Personne& p) {
    id = p.id;
    nom = p.nom;
    prenom = p.prenom;
    cinn = p.cinn;
    email = p.email;
    password = p.password;
    tlf = p.tlf;
    date_naissance = p.date_naissance;
}

void Personne::afficherPersonne() {
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "CIN: " << cinn << endl;
    cout << "Email: " << email << endl;
    cout << "Telephone: " << tlf << endl;
    cout << "Date de naissance: " << date_naissance.jour << "/" << date_naissance.mois << "/" << date_naissance.anne << endl;
}

Personne::~Personne() {
}

void Personne::saisir_personne() {
    while (true) {
        try {
            cout << "Entrez le nom : ";
            cin >> nom;
            if (nom.empty()) throw invalid_argument("Le nom ne peut pas etre vide.");

            cout << "Entrez le prenom : ";
            cin >> prenom;
            if (prenom.empty()) throw invalid_argument("Le prenom ne peut pas etre vide.");

            cout << "Entrez le CIN : ";
            cin >> cinn;
            if (cinn.length() != 8 ) {
                throw invalid_argument("Le CIN doit contenir exactement 8 chiffres.");
            }

            cout << "Entrez l'email : ";
            cin >> email;

            cout << "Entrez le mot de passe : ";
            cin >> password;

            cout << "Entrez le telephone : ";
            cin >> tlf;

            cout << "Entrez la date de naissance (jour mois annee) : ";
            cin >> date_naissance.jour >> date_naissance.mois >> date_naissance.anne;

            break;
        }
        catch (const invalid_argument& e) {
            system("color 0C");
            cerr << "Erreur : " << e.what() << endl;
            cout << "Veuillez reessayer." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("color F0");
        }
    }
}

ostream& operator<<(ostream& out, const Personne &p)
{
    out << p.id;
    out << " " << p.nom ;
    out << "  " << p.prenom ;
    out << " " << p.cinn ;
    out << " " << p.email;
    out << " " << p.password;
    out << "  " << p.tlf;
    out << "  " << p.date_naissance.jour << "/"
        << p.date_naissance.mois << "/" << p.date_naissance.anne<< " ";
    return out;
}

ostream& operator<<(ostream& out, const Personne *p)
{
    out << p->id;
    out << " " << p->nom ;
    out << " " << p->prenom ;
    out << " " << p->cinn ;
    out << " " << p->email;
    out << " " << p->password;
    out << " " << p->tlf;
    out << " " << p->date_naissance.jour << "/"
        << p->date_naissance.mois << "/" << p->date_naissance.anne<< " ";
    return out;
}

istream& operator>>(istream& in, Personne& p)
{
    while (true) {
        try {
             bool isConsole = (&in == &cin);
            if (!isConsole)  in >> p.id;
            if (isConsole) cout << "Entrez le nom : ";
            in >> p.nom;
            if (isConsole) if (p.nom.empty()) throw invalid_argument("Le nom ne peut pas etre vide.");

            if (isConsole) cout << "Entrez le prenom : ";
            in >> p.prenom;
             if (isConsole) if (p.prenom.empty()) throw invalid_argument("Le prenom ne peut pas etre vide.");

            if (isConsole)  cout << "Entrez le CIN : ";
            in >> p.cinn;
         if (isConsole)   if (p.cinn.length() != 8 ) {
                throw invalid_argument("Le CIN doit contenir exactement 8 chiffres.");
            }

           if (isConsole)  cout << "Entrez l email : ";
            in >> p.email;


           if (isConsole) cout << "Entrez le mot de passe : ";
            in >> p.password;

        if (isConsole)   cout << "Entrez le telephone : ";
            in >> p.tlf;
          if (isConsole)  if (p.tlf.length() != 8 ) {
                throw invalid_argument("Le numero de telephone doit contenir 8 chiffres.");
            }

          if (isConsole) cout << "Entrez la date de naissance (jour mois annee) : ";
          if(isConsole){
               in >> p.date_naissance.jour >> p.date_naissance.mois >> p.date_naissance.anne;
          }else{
                string dateStr;
                in >> dateStr;
                sscanf(dateStr.c_str(), "%d/%d/%d", &p.date_naissance.jour, &p.date_naissance.mois, &p.date_naissance.anne);
          }
            break;
        }
        catch (const invalid_argument& e) {
            system("color 0C");
            cerr << "Erreur : " << e.what() << endl;
            cout << "Veuillez reessayer.\n" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("color F0");
        }
    }
    return in;
}



istream& operator>>(istream& in, Personne* p)
{
    while (true) {
        try {
            in>>p->id;
            cout << "Entrez le nom : ";
            in >> p->nom;
            if (p->nom.empty()) throw invalid_argument("Le nom ne peut pas etre vide.");

            cout << "Entrez le prenom : ";
            in >> p->prenom;
            if (p->prenom.empty()) throw invalid_argument("Le prénom ne peut pas etre vide.");

            cout << "Entrez le CIN : ";
            in >> p->cinn;
            if (p->cinn.length() != 8 ) {
                throw invalid_argument("Le CIN doit contenir exactement 8 chiffres.");
            }

            cout << "Entrez lemail : ";
            in >> p->email;
            /*if (p.email.find('@') == string::npos || p.email.find('.') == string::npos) {
                throw invalid_argument("Email invalide.");
            }*/

            cout << "Entrez le mot de passe : ";
            in >> p->password;

            cout << "Entrez le telephone : ";
            in >> p->tlf;
            if (p->tlf.length() != 8 ) {
                throw invalid_argument("Le numero de telephone doit contenir 8 chiffres.");
            }

            cout << "Entrez la date de naissance (jour mois annee) : ";
            in >> p->date_naissance.jour >> p->date_naissance.mois >> p->date_naissance.anne;
            break;
        }
        catch (const invalid_argument& e) {
            system("color 0C");
            cerr << "Erreur : " << e.what() << endl;
            cout << "Veuillez reessayer.\n" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            system("color F0");
        }
    }
    return in;
}

void Personne::modifier() {
    cout << "Modifier le nom: ";
    cin >> nom;
    cout << "Modifier le prenom: ";
    cin >> prenom;
    cout << "Modifier le CIN: ";
    cin >> cinn;
    cout << "Modifier lemail: ";
    cin >> email;
    cout << "Modifier le password: ";
    cin >> password;
    cout << "Modifier le telephone: ";
    cin >> tlf;
    cout << "Modifier la date de naissance: ";
    cin >> date_naissance.jour >> date_naissance.mois >> date_naissance.anne;
}

Personne& Personne::operator=(const Personne& p) {
    if (this != &p) {
        this->id = p.id;
        this->nom = p.nom;
        this->prenom = p.prenom;
        this->cinn = p.cinn;
        this->email = p.email;
        this->password = p.password;
        this->tlf = p.tlf;
        this->date_naissance = p.date_naissance;
    }
    return *this;
}
