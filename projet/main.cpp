#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "Resident.h"
#include "Medecin.h"
#include "Infirmier.h"
#include "MedecinInfirmier.h"
#include "Responsable.h"
#include "EtageAlzheimer.h"

using namespace std;

class credentials {
public:
    string email;
    string password;
    string role;
};

void afficherChargement(const char* message, int duree) {
    printf("\n\n%60s", message);
    fflush(stdout);
    for (int i = 0; i < duree; i++) {
        printf(".");
        fflush(stdout);
         sleep(1);
    }
    printf("\n");
}

string VerifierEmailPassword(string email, string pass) {
    fstream f("BD\\credentials.txt");
    if (!f.is_open()) exit(-1);
    credentials c;
    while (f >> c.email >> c.password >> c.role) {
        if (c.email == email && c.password == pass) {
            f.close();
            return c.role;
        }
    }
    f.close();
    return "";
}

void resteConnecte(string email,string role){
 ofstream of("BD\\reste_connecte.txt", ios::trunc);
    if (of.is_open()) {
        of << email << " " << role << endl;
        of.close();
    }
}

void inscrireResident() {
    string nom, prenom, cinn, email, password, telf;
    cout << "------ Inscription Resident ------" << endl;
    Batiment bat;

    EtageAlzheimer* e1 = new EtageAlzheimer(1, 5, "Alzheimer");
    bat.ajouterEtage(e1);

    bat.enregistrerEtages();

    Batiment bat2;
    bat2.chargerEtages();

    bat2.afficherEtage();
    /*Etage* etage;
    bat.ajouterEtage(etage);
    bat.afficherEtage();*/

      /* Resident res;
    cin>>res;
    res.ecrirerResidentDansFichier();
       Resident res1;
    cin>>res1;
    res1.ecrirerResidentDansFichier();*/

    /*MedecinInfirmier med;
    cin>>med;
    cout<<med;
    med.ecrirerMedecinInfDansFichier();*/

    //Responsable r;
    /*cin>>r;*/
    //r.AfficherResident();
    /*Infirmier* inf = new Infirmier;
    cin >> *inf;*/
    /*r.ajouterEmploye(inf);
    r.afficherEmployes();
    r.afficherPersonne();

    Responsable r1;
    cin>>r1;
       Infirmier* inf1 = new Infirmier;
    cin >> *inf1;
    r1.ajouterEmploye(inf1);
    r1.afficherEmployes();
    r.afficherPersonne();

    r1=r;
    r1.afficherPersonne();*/

    /*Infirmier inf;
    cin>>inf;
    inf.ecrirerInfirmierDansFichier();*/
 /*  Medecin c;
    cin>>c;
    c.ecrirerMedecinDansFichier();*/
    system("pause");
    Resident res;
    cin>>res;
    res.ecrirerResidentDansFichier();


    /*ofstream of("BD\\Resident.txt", ios::app);
    if (of.is_open()) {
        of << res.getId()<<" "<<res.getNom() << " " << res.getPassword() << " " << res.getCIN() << " " << res.getEmail() << " " << res.getPassword() << " " << res.getTlf() << " "<<res.getDateNaissance().jour<<"/"<<res.getDateNaissance().mois<<"/"<<res.getDateNaissance().anne<< endl;
        of.close();
    }*/
    ofstream off("BD\\credentials.txt", ios::app);
    if (off.is_open()) {
        off << res.getEmail() << " " << res.getPassword()  << " resident" << endl;
        off.close();
    }
    cout << "\n✅ Inscription réussie ! Vous pouvez maintenant vous connecter.\n";
}

credentials  CheckConnecter(){
     credentials TestConnect;
    ifstream off("BD\\reste_connecte.txt");
      if (off.is_open() && off.peek() != ifstream::traits_type::eof()) {
        off >> TestConnect.email >> TestConnect.role;
        off.close();
    }else{
        TestConnect.email = "";
        TestConnect.role = "";
    }
    return TestConnect;
}

void LogoutUser() {
    ofstream off("BD\\reste_connecte.txt", ios::trunc);
    if (off.is_open()) {
        off.close();
        cout << "✅ Déconnexion réussie." << endl;
    } else {
        cout << "❌ Erreur lors de la déconnexion." << endl;
    }
}

template<typename T>
T GetUserDetails( string email,  string role) {
    T user;
    string filename;
    if (role == "resident") filename = "BD\\Resident.txt";
    else filename = "BD\\personnel.txt";
    ifstream f(filename);
    if (!f.is_open()) {
            cerr << "Erreur lors de l'ouverture de Resident.txt" << endl;
            exit(-1);
    }

    /*DateNaissance d;
    sscanf(date.c_str(), "%d/%d/%d", &d.jour, &d.mois, &d.anne);
    user.setDateNaissance(d);*/

}

int main() {
    afficherChargement("CenterX", 0);
    system("cls");
    system("color F0");
    credentials TestConnect=CheckConnecter();
    if(TestConnect.email!=""){
             cout<<"Welcome"<<TestConnect.email;
              int logout;
              cout << "\n Voulez vous logout (1 = Oui, 0 = Non): "  << endl;
              cin>>logout;
              if (logout==1){
                     LogoutUser();
              }
    }else{
          string email, password;
         int choix;

        while (true) {
            cout << "\n----- Bienvenue -----" << endl;
            cout << "1. Se connecter" << endl;
            cout << "2. S'inscrire comme Resident" << endl;
            cout << "3. Quitter" << endl;
            cout << "Choix: ";
            cin >> choix;

        if (choix == 1) {
            cout << "\n--- Connexion ---" << endl;
            cout << "Email: ";
            cin >> email;
            cout << "Mot de passe: ";
            cin >> password;

            string role = VerifierEmailPassword(email, password);
            if (role != "") {
                cout << "\n✅ Connexion réussie en tant que " << role << endl;
                int checkRes;
                cout << "\n Voulez vous rester connecté (1 = Oui, 0 = Non): "  << endl;
                if (role== "resident") {
                        Resident r = GetUserDetails<Resident>(email, role);
                        cout << "Bienvenue " << r.getNom() << " !\n";
                }
                cin>>checkRes;
                if (checkRes==1)
                    resteConnecte(email,role);
            } else {
                cout << "\n❌ Compte introuvable. Souhaitez-vous vous inscrire ? (1 = Oui, 0 = Non): ";
                int reponse;
                cin >> reponse;
                if (reponse == 1) {
                    inscrireResident();
                    afficherChargement("Loading", 1);
                } else {
                    cout << "🔙 Retour au menu principal.\n";
                }
            }

        } else if (choix == 2) {
            inscrireResident();
        } else if (choix == 3) {
            cout << "👋 Au revoir !" << endl;
            break;
        } else {
            cout << "❌ Choix invalide. Veuillez réessayer.\n";
        }
        cout << "\nAppuyez sur Entrée pour continuer... ";
        cin.ignore();
        cin.get();
        system("cls");
    }
}
    return 0;
}

 /*
    Batiment batiment("Centre", "Projet");
    EtageCardio etageCardio(1,2,"dd");
    EtageAlzheimer etageAlzheimer(2,3,"hh");

    batiment.ajouterEtage(&etageCardio);
    batiment.ajouterEtage(&etageAlzheimer);

    Resident* resident = new Resident(1, "TestRes", "TestRes", "123456", "TestRes@example.com", "motdepasse", "123456789", {1, 1, 1990}, 1500);
    Infirmier* infirmier = new Infirmier(2, "TestInf", "TestInf", "987654", "TestInf@example.com", "password", "987654321", {1, 1, 1990}, 2000, "Infirmier", 5);
    Medecin* medecin = new Medecin(3, "TestMed", "TestMed", "135792", "TestMed@example.com", "password", "123123123", {10, 10, 1980}, 5000, "Cardiologue");

    batiment.ajouterPersonne(resident);
    batiment.ajouterPersonne(infirmier);
    batiment.ajouterPersonne(medecin);

    int choix;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Afficher Batiment" << endl;
        cout << "2. Ajouter une personne" << endl;
        cout << "3. Ajouter un etage" << endl;
        cout << "4. Afficher les personnes du batiment" << endl;
        cout << "5. Afficher les etages du batiment" << endl;
        cout << "6. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;

        switch(choix) {
            case 1:
                batiment.afficherBatiment();
                break;
            case 2: {
                int typePersonne;
                cout << "Entrez le type de personne (1: Resident, 2: Infirmier, 3: Medecin): ";
                cin >> typePersonne;

                if (typePersonne == 1) {
                    Resident* newResident = new Resident(4, "test", "test", "112233", "test@example.com", "pass1234", "123987654", {25, 12, 1995}, 1000);
                    batiment.ajouterPersonne(newResident);
                    cout << "Resident ajouté" << endl;
                } else if (typePersonne == 2) {
                    Infirmier* newInfirmier = new Infirmier(5, "test2", "test", "667788", "test@example.com", "password", "667788990", {15, 3, 1988}, 2200, "Infirmier",8);
                    batiment.ajouterPersonne(newInfirmier);
                    cout << "Infirmier ajouté" << endl;
                } else if (typePersonne == 3) {
                    Medecin* newMedecin = new Medecin(6, "test3", "test", "102938", "test@example.com", "12345", "987654321", {18, 7, 1975}, 5500, "Neurologue");
                    batiment.ajouterPersonne(newMedecin);
                    cout << "Medecin ajouté" << endl;
                } else {
                    cout << "Type de personne invalide" << endl;
                }
                break;
            }
            case 3: {
                int typeEtage;
                cout << "Entrez le type d'etage (1: Cardio, 2: Alzheimer): ";
                cin >> typeEtage;

                if (typeEtage == 1) {
                    EtageCardio* newEtage = new EtageCardio(3,4,"hh");
                    batiment.ajouterEtage(newEtage);
                    cout << "Etage Cardio ajouté!" << endl;
                } else if (typeEtage == 2) {
                    EtageAlzheimer* newEtage = new EtageAlzheimer(4,4,"ggg");
                    batiment.ajouterEtage(newEtage);
                    cout << "Etage Alzheimer ajouté" << endl;
                } else {
                    cout << "Type d'etage invalide" << endl;
                }
                break;
            }
            case 4:
                cout << "\nListe des personnes dans le batiment:" << endl;
                for (auto personne : batiment.getPersonnes()) {
                    personne->afficherPersonne();
                }
                break;
            case 5:
                cout << "\nListe des etages dans le batiment:" << endl;
                for (auto etage : batiment.getEtages()) {
                    etage->afficherEtage();
                }
                break;
            case 6:
                cout << "exit" << endl;
                break;
            default:
                cout << "Choix invalide" << endl;
        }
    } while (choix != 6);

    delete resident;
    delete infirmier;
    delete medecin;

    return 0;*/
