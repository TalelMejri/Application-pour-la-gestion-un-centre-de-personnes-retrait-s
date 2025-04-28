#include "env.h"

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

void LogoutUser() {
    ofstream off("BD\\reste_connecte.txt", ios::trunc);
    if (off.is_open()) {
        off.close();
        cout << " Deconnexion reussie." << endl;
    } else {
        cout << "Erreur lors de la deconnexion." << endl;
    }
}

void resteConnecte(string email,string role){
 ofstream of("BD\\reste_connecte.txt", ios::trunc);
    if (of.is_open()) {
        of << email << " " << role << endl;
        of.close();
    }
}

void Connexion(credentials& connectedUser, credentials& c) {
    string email, password;
    int choix;
    do {
        cout << "\n----- Bienvenue -----" << endl;
        cout << "1. Se connecter" << endl;
        cout << "2. S'inscrire" << endl;
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
                cout << "\nConnexion reussie en tant que  " << role << endl;
                int checkRes;
                cout << "\nVoulez-vous rester connecte ? (1 = Oui, 0 = Non): ";
                cin >> checkRes;
                if (checkRes == 1) resteConnecte(email, role);
                connectedUser.email = email;
                connectedUser.role = role;
                return;
            } else {
                cout << "\nCompte introuvable. Voulez-vous vous inscrire ? (1 = Oui, 0 = Non): ";
                int reponse;
                cin >> reponse;
                if (reponse == 1) {
                    Resident res;
                    cin >> res;
                    res.ecrirerResidentDansFichier();
                    afficherChargement("Enregistrement", 1);
                } else {
                    cout << "Retour au menu principal.\n";
                }
            }
        } else if (choix == 2) {
            Resident res;
            cin >> res;
            res.ecrirerResidentDansFichier();
            c.SaveCredentials(res.getEmail(), res.getPassword(), "Resident");
            afficherChargement("Enregistrement", 1);
            cout << "\nInscription réussie ! Vous pouvez maintenant vous connecter.\n";
        } else if (choix == 3) {
            afficherChargement("Au Revoir", 2);
            exit(0);
        } else {
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
        cout << "\nAppuyez sur Entrée pour continuer...";
        cin.ignore();
        cin.get();
        system("cls");
    } while (true);
}

void MenuResponsable(Responsable& responsable) {
    int choix;

    do {
        cout << "\n===== MENU RESPONSABLE =====" << endl;
        cout << "1. Ajouter un employe" << endl;
        cout << "2. Supprimer un employe" << endl;
        cout << "3. Modifier un employe" << endl;
        cout << "4. Afficher tous les employes" << endl;
        cout << "6. Supprimer un resident" << endl;
        cout << "7. Modifier un resident" << endl;
        cout << "8. Afficher tous les residents" << endl;
        cout << "9. Afficher informations du batiment" << endl;
        cout << "10. Gerer les etages (ajouter, supprimer, afficher)" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                int typePersonnel;
    cout << "Quel type d'employe voulez-vous ajouter ?" << endl;
    cout << "1. Personnel\n2. Medecin\n3. MedecinInfirmier\nVotre choix : ";
    cin >> typePersonnel;

    Personnel* emp = nullptr;

    if (typePersonnel == 1) {
        emp = new Personnel();
        cin >> *emp;
    } else if (typePersonnel == 2) {
        emp = new Medecin();
        cin >> *(dynamic_cast<Medecin*>(emp));
    } else if (typePersonnel == 3) {
        emp = new MedecinInfirmier();
        cin >> *(dynamic_cast<MedecinInfirmier*>(emp));
    } else {
        cout << "Type d'employe invalide. Operation annulee.\n";
        break;
    }

    responsable.ajouterEmploye(emp);
    cout << "Employe ajoute avec succes.\n";
    break;
            }
            case 2: {
                int id;
                cout << "ID de lemploye a supprimer : ";
                cin >> id;
                responsable.supprimerEmploye(id);
                break;
            }
            case 3: {
                int id;
                cout << "ID de lemploye a modifier : ";
                cin >> id;
                responsable.modifier(id);
                break;
            }
            case 4: {
                responsable.afficherEmployes();
                break;
            }
            case 6: {
                int id;
                cout << "ID du resident a supprimer : ";
                cin >> id;
                responsable.SupprimerResident(id);
                break;
            }
            case 7: {
                int id;
                cout << "ID du resident a modifier : ";
                cin >> id;
                responsable.ModifierResident(id);
                break;
            }
            case 8: {
                responsable.AfficherResident();
                break;
            }
            case 9: {
                cout<<responsable;
                break;
            }
            case 10: {
                int sousChoix;
                cout << "\nGestion des étages :" << endl;
                cout << "1. Ajouter un étage" << endl;
                cout << "2. Supprimer un étage" << endl;
                cout << "3. Afficher tous les étages" << endl;
                cout << "Votre choix : ";
                cin >> sousChoix;

                if (sousChoix == 1) {
                    cout << "Quel type d'étage voulez-vous ajouter ?" << endl;
                    cout << "1. Etage Alzheimer\n2. Etage Cardio\n3. Etage Neurologie\nVotre choix : ";
                    int typeEtage;
                    cin >> typeEtage;
                    int id;
                    string typeNom;
                    cout << "ID de l'étage : ";
                    cin >> id;
                    cout << "Nom/type de l'étage : ";
                    cin.ignore();
                    getline(cin, typeNom);

                    if (typeEtage == 1) {
                        EtageAlzheimer* etage = new EtageAlzheimer(id, 0, typeNom);
                        responsable.batiment.ajouterEtage(etage);
                    } else if (typeEtage == 2) {
                        EtageCardio* etage = new EtageCardio(id, 0, typeNom);
                        responsable.batiment.ajouterEtage(etage);
                    } else if (typeEtage == 3) {
                        EtageNeurologie* etage = new EtageNeurologie(id, 0, typeNom);
                        responsable.batiment.ajouterEtage(etage);
                    }
                } else if (sousChoix == 2) {
                    int id;
                    cout << "ID de l'étage à supprimer : ";
                    cin >> id;
                    responsable.batiment.supprimerEtage(id);
                } else if (sousChoix == 3) {
                    responsable.batiment.afficherEtage();
                }
                break;
            }
            case 0:
                LogoutUser();
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Essayez encore." << endl;
        }

    } while (choix != 0);
}
