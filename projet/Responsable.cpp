#include "env.h"
using namespace std;

Responsable::Responsable() : Personne() {
    LireResidentFromFichier();
    LireMedecinFromFichier();
    LireMedecinInfirmierFromFichier();
    batiment.chargerEtages();
}

Responsable::Responsable(int id, string nom, string prenom, string cinn, string email, string password, string tlf, DatePerso date_naissance)
    : Personne(id, nom, prenom, cinn, email, password, tlf, date_naissance) {
            LireResidentFromFichier();
            LireMedecinFromFichier();
            LireMedecinInfirmierFromFichier();
            batiment.chargerEtages();
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

    os <<  r.batiment;

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

   os <<  r->batiment;

    return os;
}

istream& operator>>(istream& is, Responsable* r) {
    if (r != nullptr) {
        is >> *r;
    }
    return is;
}

void Responsable::ajouterEmploye(Personnel* employe) {
    credentials c;
    if (typeid(*employe) == typeid(Medecin)) {
        employes.push_back(employe);
        c.SaveCredentials(employe->getEmail(), employe->getPassword(), "Medecin");
        Medecin* medecin = dynamic_cast<Medecin*>(employe);
        medecin->ecrirerMedecinDansFichier();
        cout << "Medecin ajoute avec succes.\n";
    }
    else if (typeid(*employe) == typeid(MedecinInfirmier)) {
        employes.push_back(employe);
        c.SaveCredentials(employe->getEmail(), employe->getPassword(), "MedecinInfirmier");
        MedecinInfirmier* medecinInf = dynamic_cast<MedecinInfirmier*>(employe);
        medecinInf->ecrirerMedecinInfDansFichier();
        cout << "Medecin-infirmier ajoute avec succes.\n";
    }
    else {
        cout << "Erreur : Seuls les médecins ou medecins-infirmiers peuvent etre ajoutes.\n";
        delete employe;
    }
}

void Responsable::supprimerEmploye(int id) {
    for (size_t i = 0; i < employes.size(); ++i) {
        if (employes[i]->getId() == id) {
            int test=typeid(employes[i])==typeid(Medecin) ? 1 : 0;
            delete employes[i];
            employes.erase(employes.begin() + i);
            cout << "Employe supprime avec succes.\n";
            if(test==1) sauvegarderMedecinDansFichier();
            else sauvegarderMedecinInfirmierDansFichier();
            return;
        }
    }
    cout << "Aucun employe avec cet ID.\n";
}

void Responsable::afficherEmployes() {
    if (employes.empty()) {
        cout << "Aucun employe enregistre.\n";
        return;
    }
    cout << "Liste des employes :\n";
    for (Personnel* p : employes) {
        if (typeid(*p) == typeid(Medecin)) {
            Medecin* medecin = dynamic_cast<Medecin*>(p);
            cout<<medecin;
        } else if(typeid(*p)==typeid(MedecinInfirmier)) {
            MedecinInfirmier* medecinInf = dynamic_cast<MedecinInfirmier*>(p);
            cout<<medecinInf;
        }
    }
}

void Responsable::modifier(int id) {
    for (Personnel* p : employes) {
        if (p->getId() == id) {
            int test=typeid(*p)==typeid(Medecin) ? 1 : 0;
            cout << "Modification de lemploye avec ID " << id << " :\n";
            p->modifier();
            if(test==1) sauvegarderMedecinDansFichier();
            else sauvegarderMedecinInfirmierDansFichier();
            return;
        }
    }
    cout << "Aucun employe trouve avec cet ID.\n";
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

void Responsable::LireMedecinFromFichier(){
      try{
            ifstream of("BD\\Medecin.txt");
            Medecin r;
           while (of >> r) {
                employes.push_back(new Medecin(r));
            }
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}

void Responsable::LireMedecinInfirmierFromFichier(){
      try{
            ifstream of("BD\\MedecinInfirmier.txt");
            MedecinInfirmier r;
           while (of >> r) {
                employes.push_back(new MedecinInfirmier(r));
            }
            of.close();
    }catch(exception e){
        cerr<<"Erreur"<<e.what();
    }
}

void Responsable::sauvegarderResidentsDansFichier() {
    try {
        ofstream of("BD\\Resident.txt", ios::trunc);
        if (!of) {
            cerr << "Erreur lors de louverture du fichier pour lecriture.\n";
            return;
        }

        for (const auto& resident : residents) {
            of << resident << endl ;
        }

        of.close();
        cout << "Residents mis a jour dans le fichier avec succe.\n";
    } catch (exception& e) {
        cerr << "Erreur lors de la sauvegarde des residents : " << e.what() << endl;
    }
}

void Responsable::sauvegarderMedecinDansFichier() {
    try {
        ofstream of("BD\\Medecin.txt", ios::trunc);
        if (!of) {
            cerr << "Erreur lors de louverture du fichier pour lecriture.\n";
            return;
        }

      for (int i=0;i<employes.size();i++) {
            of << employes[i] << endl ;
      }

        of.close();
        cout << "Medecin mis a jour dans le fichier avec succe.\n";
    } catch (exception& e) {
        cerr << "Erreur lors de la sauvegarde des residents : " << e.what() << endl;
    }
}

void Responsable::sauvegarderMedecinInfirmierDansFichier() {
    try {
        ofstream of("BD\\MedecinInfirmier.txt", ios::trunc);
        if (!of) {
            cerr << "Erreur lors de louverture du fichier pour lecriture.\n";
            return;
        }

      for (int i=0;i<employes.size();i++) {
            of << employes[i] << endl ;
      }

        of.close();
        cout << "MedecinInfirmier mis a jour dans le fichier avec succe.\n";
    } catch (exception& e) {
        cerr << "Erreur lors de la sauvegarde des residents : " << e.what() << endl;
    }
}

void Responsable::AfficherResident() {
        if (residents.empty()) {
            cout << "Aucun resident enregistre.\n";
            return;
        }
        for (int i=0;i<residents.size();i++) {
            cout <<residents[i]<<endl;
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
            cout << "Resident non trouve.\n";
            return;
        }
        residents[index].modifier();
        sauvegarderResidentsDansFichier();
        cout << "Resident modifie avec succes.\n";
}

 void Responsable::SupprimerResident(int id) {
        int index = RechercherResident(id);
        if (index == -1) {
            cout << "Resident non trouve.\n";
            return;
        }
        residents.erase(residents.begin() + index);
        sauvegarderResidentsDansFichier();
        cout << "Resident supprime avec succes.\n";
}

void Responsable::afficherPersonne() {
    cout << *this;
}

 void Responsable::modifier(){
    Personne::modifier();
 }
