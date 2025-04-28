#include "env.h"
using namespace std;

int main() {
    afficherChargement("CenterX", 2);
    system("cls");
    system("color F0");
    credentials c;
    credentials TestConnect = c.CheckConnecter();
    if(TestConnect.email==""){
        string email, password;
        int choix;
          while (true) {
            cout << "\n----- Bienvenue -----" << endl;
            cout << "1. Se connecter" << endl;
            cout << "2. Registre" << endl;
            cout << "3. Quitter" << endl;
            cout << "Choix: ";
            cin >> choix;
        if (choix == 1) {
            cout << "\n--- Connexion ---" << endl;
            cout << "Email: ";
            cin >> email;
            cout << "Mot de passe: ";
            cin >> password;
            string role = c.VerifierEmailPassword(email, password);
            if (role != "") {
                cout << "\n Connexion reussie en tant que " << role << endl;
                int checkRes;
                cout << "\n Voulez vous rester connecte (1 = Oui, 0 = Non): "  << endl;
                cin>>checkRes;
                if (checkRes==1) resteConnecte(email,role);
                else LogoutUser();
                  if(TestConnect.role=="Resident"){
            Resident r = GetUserDetails<Resident>(TestConnect.email,TestConnect.role);
            cout<<r;
            // MenuResident();
       }else if(TestConnect.role=="Infirmier"){
            Infirmier inf = GetUserDetails<Infirmier>(TestConnect.email,TestConnect.role);
            // MenuInfirmier();
        }else if(TestConnect.role=="Medecin"){
            Medecin med = GetUserDetails<Medecin>(TestConnect.email,TestConnect.role);
            // MenuMedecin();
        }else if(TestConnect.role=="MedecinInfirmier"){
            MedecinInfirmier MedInf = GetUserDetails<MedecinInfirmier>(TestConnect.email,TestConnect.role);
            // MenuMedecinInfirmier();
        }else{
                Responsable res = GetUserDetails<Responsable>(TestConnect.email,TestConnect.role);
               // MenuResponsable();
        }
            } else {
                cout << "\n Compte introuvable. Souhaitez-vous vous inscrire ? (1 = Oui, 0 = Non): ";
                int reponse;
                cin >> reponse;
                if (reponse == 1) {
                    Resident res;
                    cin>>res;
                    res.ecrirerResidentDansFichier();
                    afficherChargement("Enregistrer", 1);
                } else {
                    cout << " Retour au menu principal .\n";
                }
            }
        } else if (choix == 2) {
            Resident res;
            cin>>res;
            res.ecrirerResidentDansFichier();
            c.SaveCredentials(res.getEmail(),res.getPassword(),"Resident");
            afficherChargement("Enregistrer", 1);
            cout << "\n Inscription reussie ! Vous pouvez maintenant vous connecter.\n";
        } else if (choix == 3) {
            afficherChargement("Au Revoir", 2);
            break;
        } else {
            cout << " Choix invalide. Veuillez reessayer \n";
        }
        cout << "\nAppuyez sur Entree pour continuer... ";
        cin.ignore();
        cin.get();
        system("cls");
    }
    }else{
        if(TestConnect.role=="Resident"){
            Resident r = GetUserDetails<Resident>(TestConnect.email,TestConnect.role);
            cout<<r;
            // MenuResident();
       }else if(TestConnect.role=="Infirmier"){
            Infirmier inf = GetUserDetails<Infirmier>(TestConnect.email,TestConnect.role);
            // MenuInfirmier();
        }else if(TestConnect.role=="Medecin"){
            Medecin med = GetUserDetails<Medecin>(TestConnect.email,TestConnect.role);
            // MenuMedecin();
        }else if(TestConnect.role=="MedecinInfirmier"){
            MedecinInfirmier MedInf = GetUserDetails<MedecinInfirmier>(TestConnect.email,TestConnect.role);
            // MenuMedecinInfirmier();
        }else{
                Responsable res = GetUserDetails<Responsable>(TestConnect.email,TestConnect.role);
                MenuResponsable(res);
        }
    }
    return 0;
}
